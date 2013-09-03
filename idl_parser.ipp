#ifndef IDL_PARSER_IPP
#define IDL_PARSER_IPP

#include <iostream>
#include <fstream>
#include <bitset>
#include <set>
#include <map>
#include <vector>
#include <cassert>
#include "idl_grammar.hpp"
#include <idlmm.hpp>

namespace idl 
{
namespace parser 
{

const char * NSS = "::"; // namespace separator

template < typename Set >
idlmm::ParameterMode get_direction(const Set& s)
{
    using namespace grammar;

    idlmm::ParameterMode res = 0;

    if (s.test(FLAG_OUT))
        res = 1;
    else if (s.test(FLAG_INOUT))
        res = 2;

    return res;
}

struct SemanticState
{
    typedef grammar::semantic_context_type context_type_t;
    typedef std::vector< ecore::EObject * > objects_t;

    struct Context
    {
        context_type_t context_type;
        std::string identifier;
        std::string data;
        std::bitset< sizeof(void *) * 8 > flags; 
        objects_t& objects;
        std::size_t prev_size;
        grammar::primitive_types primitive_type;

        Context(objects_t& objects_,
                context_type_t context_type_) : 
            context_type(context_type_),
            objects(objects_),
            prev_size(objects_.size()),
            primitive_type(grammar::PT_NULL)
        {}

        // restores previous size, discards current objects
        void clear()
        {
            objects.resize(prev_size);
        }

        ~Context()
        {
            // No memory leaks due to rollback
            for (std::size_t i = prev_size; i < objects.size(); i++) 
            {
                delete objects[i];
            }

            clear();
        }
    };

    ecore::EObject * result;

    typedef std::deque< Context > contexts_t; 
    contexts_t contexts;

    objects_t objects;

    typedef std::vector< std::string > literals_t;
    literals_t literals;

    SemanticState() : result (NULL) {}

    void push_identifier(const std::string& id)
    {
        //std::cout << id << std::endl;
        contexts.back().identifier = id;
    }

    void push_literal(const std::string& l)
    {
        //std::cout << __FUNCTION__ << " " << l << std::endl;
        literals.push_back(l);
    }

    void new_context(context_type_t type)
    {
        //std::cout << "context " << type << std::endl;
        contexts.push_back(Context(objects, type));
    }

    void set_flag(grammar::flags flag)
    {
        //std::cout << "flag " << flag << std::endl;
        contexts.back().flags.set(flag);
    }

    void set_primitive_type(grammar::primitive_types type)
    {
        //std::cout << "primitive_type " << type << std::endl;
        contexts.back().primitive_type = type;
    }

    template < class Contained, class Obj, typename Fn >
    void populate(Context& c, Obj * o, Fn f)
    {
        for (std::size_t i = c.prev_size; i < c.objects.size(); i++) 
        {
            Contained * t = c.objects[i]->as< Contained >();
            assert(t);
            if (t) (o->*f)().push_back(t);
        }

        // avoid double free
        c.clear();
    }

    // attempt to implement a lookup function
    // TODO must be optimized
    // TODO merge equivalent namespaces
    template < typename Type >
    Type* lookup(const std::string& f)
    {
        typedef Type* Type_ptr;
        typedef std::map< std::string, Type_ptr > scope_t;

        scope_t scope;
        std::size_t size = objects.size();

        for (contexts_t::reverse_iterator it = contexts.rbegin(); 
                it != contexts.rend(); it++) 
        {
            // previous scope transformation
            if (!it->identifier.empty() && !scope.empty())
            {
                scope_t old (scope);
                scope.clear();

                for (typename scope_t::iterator jt = old.begin(); 
                        jt != old.end(); ++jt) 
                {
                    scope[it->identifier + NSS + jt->first] = jt->second;
                }
            }

            typedef std::vector< std::pair< std::string, idlmm::Container_ptr > > 
                containers_t;
            containers_t containers;

            // current objects
            for (std::size_t i = it->prev_size; i < size; i++) 
            {
                Type_ptr t = 
                    objects[i]->as< Type  >(); 

                if (t)
                    scope[t->getIdentifier()] = t;

                idlmm::Container_ptr c =
                    objects[i]->as< idlmm::Container >();

                if (c)
                    containers.push_back(std::make_pair(c->getIdentifier(), c));
            }
            // next iteration
            size = it->prev_size;

            // Recurse into the containers
            for (std::size_t i = 0; i < containers.size(); i++) 
            {
                idlmm::Container_ptr c = containers[i].second;
                const std::string& first = containers[i].first;
                const std::string prefix = 
                    (first.empty())? first: first + NSS; 

                for (std::size_t j = 0; j < c->getContains().size(); j++) 
                {
                    Type_ptr t = 
                        c->getContains()[j]->as< Type  >(); 

                    if (t)
                        scope[prefix + t->getIdentifier()] = t;

                    idlmm::Container_ptr r =
                        c->getContains()[j]->as< idlmm::Container >();

                    if (r)
                        containers.push_back(std::make_pair(
                                    prefix + r->getIdentifier(), r));
                }
            }

            typename scope_t::iterator i = scope.find(f);
            if (i != scope.end())
                return i->second;
        }

        std::cerr << "Error: undefined reference to " << f << std::endl;
        std::cerr << "Current scope:" << std::endl;
        for (typename scope_t::const_iterator it = scope.begin(); 
                it != scope.end(); ++it) 
        {
            std::cerr << "  " << it->first << std::endl;
        }

        return NULL;
    }

    bool try_to_set_type(idlmm::Typed_ptr typed)
    {
        const Context& c = contexts.back();
        bool res = false;

        if (c.primitive_type != grammar::PT_NULL)
        {
            idlmm::PrimitiveDef * p = new idlmm::PrimitiveDef();
            p->setKind(static_cast< idlmm::PrimitiveKind >(c.primitive_type));
            typed->setContainedType(p);
            res = true;
        }
        else if (!c.data.empty())
        {
            idlmm::TypedefDef_ptr t = lookup< idlmm::TypedefDef >(c.data);
            if (t)
            {
                typed->setSharedType(t);
                res = true;
            }
        }

        return res;
    }

    bool try_to_set_type_to_alias(idlmm::AliasDef_ptr typed)
    {
        Context& c = contexts.back();
        if (c.prev_size != objects.size())
        {
            assert(objects.size() == c.prev_size + 1);

            idlmm::IDLType_ptr t = 
                objects[c.prev_size]->as< idlmm::IDLType >();
            assert(t);
            typed->setContainedType(t);

            c.clear();

            return true;
        }
        return try_to_set_type(typed);
    }
    
    template < typename S, typename match_pair >
    void set_context_data(S& state, match_pair const& mp)
    {
        // TODO switch for expressions
    }

    template < typename S, typename match_pair >
    void set_data(S& state, match_pair const& mp)
    {
        contexts.back().data = state.to_string(mp.first, mp.second);
    }

    void commit()
    {
        using namespace idlmm;
        using namespace grammar;

        IdlmmFactory_ptr f = IdlmmFactory::_instance(); 

        Context& c = contexts.back();
        const std::size_t diff = objects.size() - c.prev_size;
        //std::cout << "commit " << c.context_type << std::endl;

        ecore::EObject_ptr obj = NULL;

        switch (c.context_type)
        {
        case CONTEXT_TRANSLATION_UNIT:
            {
                TranslationUnit_ptr o = f->createTranslationUnit();
                o->setIdentifier(c.identifier);

                populate< Contained >(c, o, 
                        &TranslationUnit::getContains);

                obj = o;
            }
            break;
        case CONTEXT_MODULE:
            {
                ModuleDef_ptr o = f->createModuleDef();
                o->setIdentifier(c.identifier);

                populate< Contained >(c, o, &ModuleDef::getContains);

                obj = o;
            }
            break;
        case CONTEXT_STRUCT:
            {
                StructDef_ptr o = f->createStructDef();
                o->setIdentifier(c.identifier);

                populate< Field >(c, o, &StructDef::getMembers);

                obj = o;
            }
            break;
        case CONTEXT_UNION:
            {
                UnionDef_ptr o = f->createUnionDef();
                o->setIdentifier(c.identifier);

                populate< UnionField >(c, o, &UnionDef::getUnionMembers);

                // TODO discriminator

                obj = o;
            }
            break;
        case CONTEXT_INTERFACE:
            {
                InterfaceDef_ptr o = f->createInterfaceDef();
                o->setIdentifier(c.identifier);
                o->setIsAbstract(c.flags.test(FLAG_ABSTRACT));

                populate< Contained >(c, o, &InterfaceDef::getContains);

                obj = o;
            }
            break;
        case CONTEXT_OPERATION:
            {
                OperationDef_ptr o = f->createOperationDef();
                o->setIdentifier(c.identifier);
                o->setIsOneway(c.flags.test(FLAG_ONEWAY));

                populate< ParameterDef >(c, o, 
                        &OperationDef::getParameters);

                try_to_set_type(o);

                obj = o;
            }
            break;
        case CONTEXT_PARAMETER:
            {
                ParameterDef_ptr o = f->createParameterDef();
                o->setIdentifier(c.identifier);
                o->setDirection(get_direction(c.flags));

                try_to_set_type(o);

                obj = o;
            }
            break;
        case CONTEXT_ATTRIBUTE:
            {
                AttributeDef_ptr o = f->createAttributeDef();
                o->setIdentifier(c.identifier);
                o->setIsReadonly(c.flags.test(FLAG_READONLY));

                try_to_set_type(o);

                obj = o;
            }
            break;
        case CONTEXT_STRUCT_FIELD:
            {
                Field_ptr o = f->createField();
                o->setIdentifier(c.identifier);

                try_to_set_type(o);

                obj = o;
            }
            break;
        case CONTEXT_UNION_FIELD:
            {
                UnionField_ptr o = f->createUnionField();
                o->setIdentifier(c.identifier);

                try_to_set_type(o);
                
                populate< Expression >(c, o, &UnionField::getLabel);

                obj = o;
            }
            break;
        case CONTEXT_ALIAS:
            {
                AliasDef_ptr o = f->createAliasDef();
                o->setIdentifier(c.identifier);

                try_to_set_type_to_alias(o);

                obj = o;
            }
            break;
        case CONTEXT_ARRAY:
            {
                AliasDef_ptr o = f->createAliasDef();
                o->setIdentifier(c.identifier);

                ArrayDef_ptr a = f->createArrayDef();
                try_to_set_type(a);
                o->setContainedType(a);

                // bounds
                assert(diff > 0);
                for (std::size_t i = c.prev_size; i < objects.size(); i++) 
                {
                    a->getBounds().push_back(objects[i]->as< Expression >());
                }

                c.clear();
                obj = o;
            }
            break;
        case CONTEXT_ENUM:
            {
                EnumDef_ptr o = f->createEnumDef();
                o->setIdentifier(c.identifier);
                // BUG in EMF4CPP o->setMembers(literals);
                literals.clear();

                obj = o;
            }
            break;
        case CONTEXT_SEQUENCE:
            {
                SequenceDef_ptr o = f->createSequenceDef();
                try_to_set_type(o);

                // TODO bounds

                obj = o;
            }
            break;
        case CONTEXT_CONST:
            {
                ConstantDef_ptr o = f->createConstantDef();
                o->setIdentifier(c.identifier);

                try_to_set_type(o);

                // constant value
                assert(diff == 1);
                o->setConstValue(objects[c.prev_size]->as< Expression >());

                c.clear();
                obj = o;
            }
            break;
        case CONTEXT_BINARY_EXPRESSION:
            {
                if (diff == 2)
                {
                    BinaryExpression_ptr o = f->createBinaryExpression();
                    o->setLeft(objects[c.prev_size]->as< Expression >());
                    o->setRight(objects[c.prev_size + 1]->as< Expression >());
                    o->setOperator(c.data);

                    c.clear();
                    obj = o;
                }
                else if (diff == 1)
                {
                    obj = objects[c.prev_size];
                    c.clear();
                }
                else
                    assert(false);
            }
            break;
        case CONTEXT_UNARY_EXPRESSION:
            {
                UnaryExpression_ptr o = f->createUnaryExpression();
                o->setExpression(objects[c.prev_size]->as< Expression >());
                o->setOperator(c.data);

                c.clear();
                obj = o;
            }
            break;
        case CONTEXT_VALUE_EXPRESSION:
            {
                ValueExpression_ptr o = f->createValueExpression();
                o->setValue(c.data);

                obj = o;
            }
            break;
        case CONTEXT_CONSTANT_REF:
            {
                ConstantDefRef_ptr o = f->createConstantDefRef();
                // TODO support references to enum members
                Constant_ptr r = lookup< Constant >(c.data);

                if (r)
                    o->setConstant(r);

                obj = o;
            }
            break;
        default:
            assert(false);
            break;
        }
        contexts.pop_back();

        if (!contexts.empty())
        {
            assert (obj); 
            if (obj) objects.push_back(obj);
        }
        else
        {
            assert (obj); 
            result = obj;
        }
    }

    void rollback()
    {
        //std::cout << "rollback " << contexts.back().context_type << std::endl;
        contexts.pop_back();
        literals.clear();
    }
};

} // namespace parser
} // namespace idl

#endif /* IDL_PARSER_IPP */

#include <iostream>
#include <fstream>
#include <bitset>
#include <set>
#include <map>
#include <vector>
#include <cassert>
#include "idl_grammar.hpp"
#include <idlmm.hpp>

using namespace idl::grammar;

namespace
{

const char * NSS = "::"; // namespace separator

//const std::set < std::string >& primitive_types()
//{
    //static const char * typesc_[] = {
        //"octet", "char", "long", "unsigned long", "short",
        //"unsigned short", "float", "double", "long double",
        //"long long", "unsigned long long"
    //};
    //static const std::set< std::string > types(typesc_, 
            //typesc_ + sizeof(typesc_) / sizeof(const char *));
    //return types;
//}

template < typename Set >
idlmm::ParameterMode get_direction(const Set& s)
{
    idlmm::ParameterMode res = 0;

    if (s.test(FLAG_OUT))
        res = 1;
    else if (s.test(FLAG_INOUT))
        res = 2;

    return res;
}

struct SemanticState
{
    typedef semantic_context_type context_type_t;

    struct Context
    {
        context_type_t context_type;
        std::string identifier;
        std::string type;
        std::bitset< sizeof(void *) * 8 > flags; 
        std::vector< ecore::EObject * > objects;
        primitive_types primitive_type;

        Context(context_type_t context_type_) : 
            context_type(context_type_),
            primitive_type(PT_NULL)
        {}

        ~Context()
        {
            // No memory leaks due to rollback
            for (std::size_t i = 0; i < objects.size(); i++) 
            {
                delete objects[i];
            }
        }

        void clear()
        {
            objects.clear();
        }
    };

    idlmm::TranslationUnit_ptr result;

    typedef std::deque< Context > contexts_t; 
    contexts_t contexts;

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
        std::cout << __FUNCTION__ << " " << l << std::endl;
        literals.push_back(l);
    }

    void push_type(const std::string& type)
    {
        //std::cout << "type " << type << std::endl;
        contexts.back().type = type;
    }

    void new_context(context_type_t type)
    {
        //std::cout << "context " << type << std::endl;
        contexts.push_back(Context(type));
    }

    void set_flag(flags flag)
    {
        //std::cout << "flag " << flag << std::endl;
        contexts.back().flags.set(flag);
    }

    void set_primitive_type(primitive_types type)
    {
        //std::cout << "primitive_type " << type << std::endl;
        contexts.back().primitive_type = type;
    }

    template < class Contained, class Obj, typename Fn >
    void populate(Context& c, Obj * o, Fn f)
    {
        for (std::size_t i = 0; i < c.objects.size(); i++) 
        {
            (o->*f)().push_back(c.objects[i]->as< Contained >());
        }

        // avoid double free
        c.clear();
    }

    typedef std::map< std::string, idlmm::TypedefDef_ptr > scope_t;

    // attempt to implement a lookup function
    // TODO must be optimized
    idlmm::TypedefDef_ptr lookup(const std::string& f)
    {
        scope_t scope;

        for (contexts_t::reverse_iterator it = contexts.rbegin(); 
                it != contexts.rend(); it++) 
        {
            // previous scope transformation
            if (!it->identifier.empty() && !scope.empty())
            {
                scope_t old (scope);
                scope.clear();

                for (scope_t::iterator jt = old.begin(); 
                        jt != old.end(); ++jt) 
                {
                    scope[it->identifier + NSS + jt->first] = jt->second;
                }
            }

            typedef std::vector< std::pair< std::string, idlmm::Container_ptr > > 
                containers_t;
            containers_t containers;

            // current objects
            for (std::size_t i = 0; i < it->objects.size(); i++) 
            {
                idlmm::TypedefDef_ptr t = 
                    it->objects[i]->as< idlmm::TypedefDef  >(); 

                if (t)
                    scope[t->getIdentifier()] = t;

                idlmm::Container_ptr c =
                    it->objects[i]->as< idlmm::Container >();

                if (c)
                    containers.push_back(std::make_pair(c->getIdentifier(), c));
            }

            // Recurse into the containers
            for (std::size_t i = 0; i < containers.size(); i++) 
            {
                idlmm::Container_ptr c = containers[i].second;
                const std::string& first = containers[i].first;
                const std::string prefix = 
                    (first.empty())? first: first + NSS; 

                for (std::size_t j = 0; j < c->getContains().size(); j++) 
                {
                    idlmm::TypedefDef_ptr t = 
                        c->getContains()[j]->as< idlmm::TypedefDef  >(); 

                    if (t)
                        scope[prefix + t->getIdentifier()] = t;

                    idlmm::Container_ptr r =
                        c->getContains()[j]->as< idlmm::Container >();

                    if (r)
                        containers.push_back(std::make_pair(
                                    prefix + r->getIdentifier(), r));
                }
            }

            scope_t::iterator i = scope.find(f);
            if (i != scope.end())
                return i->second;
        }

        std::cerr << "Error: undefined reference to " << f << std::endl;
        std::cerr << "Current scope:" << std::endl;
        for (scope_t::const_iterator it = scope.begin(); it != scope.end(); ++it) 
        {
            std::cerr << "  " << it->first << std::endl;
        }

        return NULL;
    }

    bool try_to_set_type(idlmm::Typed_ptr typed)
    {
        const Context& c = contexts.back();
        bool res = false;

        if (c.primitive_type != PT_NULL)
        {
            idlmm::PrimitiveDef * p = new idlmm::PrimitiveDef();
            p->setKind(static_cast< idlmm::PrimitiveKind >(c.primitive_type));
            typed->setContainedType(p);
            res = true;
        }
        else if (!c.type.empty())
        {
            idlmm::TypedefDef_ptr t = lookup(c.type);
            if (t)
            {
                typed->setSharedType(t);
                res = true;
            }
        }

        return res;
    }

    void commit()
    {
        using namespace idlmm;
        IdlmmFactory_ptr f = IdlmmFactory::_instance(); 

        Context& c = contexts.back();
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

                result = o;
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
        case CONTEXT_ALIAS:
            {
                AliasDef_ptr o = f->createAliasDef();
                o->setIdentifier(c.identifier);

                try_to_set_type(o);

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
        default:
            assert(false);
            break;
        }
        contexts.pop_back();

        if (!contexts.empty())
        {
            assert (obj); 
            if (obj) contexts.back().objects.push_back(obj);
        }
        else
        {
            assert(result);
            assert(result == obj);
        }
    }

    void rollback()
    {
        //std::cout << "rollback " << contexts.back().context_type << std::endl;
        contexts.pop_back();
        literals.clear();
    }
};

} // namespace

namespace idl
{

idlmm::TranslationUnit_ptr parse(const char * file)
{
    idlmm::TranslationUnit_ptr res = NULL;
    std::ifstream is(file);
    if (is.good())
    {
        SemanticState ss;
        parser::IStreamState < SemanticState > iss(ss, is);

        if (idl::grammar::gram::match(iss))
        {
            res = ss.result;

            assert(res);

            // emf4cpp stuff
            res->_initialize();
        }
    }

    return res;
}

} // namespace idl


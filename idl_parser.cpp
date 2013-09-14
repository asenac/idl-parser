#include <cassert>
#include "idl_parser.hpp"
#include "idl_parser.ipp"

using namespace idl::parser;

namespace
{

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

} // namespace

namespace idl
{

template < typename State >
idlmm::TranslationUnit_ptr doParse(State& s)
{
    idlmm::TranslationUnit_ptr res = NULL;

    if (idl::grammar::gram::match(s))
    {
        ecore::EObject * obj = s.semantic_state().result;

        if (s.semantic_state().errors)
            delete obj;
        else
        {
            res = obj->as< idlmm::TranslationUnit > ();
            assert(res);

            // emf4cpp stuff
            res->_initialize();
        }
    }
    else
    {
        s.get_error(std::cerr);
    }

    return res;
}

idlmm::TranslationUnit_ptr parse(std::istream& is)
{
    if (is.good())
    {
        using namespace ::parser;
        IStreamReader reader(is);
        SemanticState ss;
        ReaderState < SemanticState, IStreamReader > iss(ss, reader);

        return doParse(iss);
    }

    return NULL;
}

idlmm::TranslationUnit_ptr parse(const char * file)
{
    std::ifstream is(file);
    return parse(is);
}

idlmm::TranslationUnit_ptr parseString(const std::string& str)
{
    using namespace ::parser;
    Reader reader(str.c_str(), str.size());
    SemanticState ss;
    ReaderState < SemanticState, Reader > iss(ss, reader);

    return doParse(iss);
}

} // namespace idl


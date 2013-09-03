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
        res = s.semantic_state().result;

        assert(res);

        // emf4cpp stuff
        res->_initialize();
    }
    else
    {
        s.get_error(std::cerr);
    }

    return res;
}

idlmm::TranslationUnit_ptr parse(const char * file)
{
    std::ifstream is(file);
    if (is.good())
    {
        SemanticState ss;
        ::parser::IStreamState < SemanticState > iss(ss, is);

        return doParse(iss);
    }

    return NULL;
}

idlmm::TranslationUnit_ptr parseString(const std::string& str)
{
    SemanticState ss;
    ::parser::State < SemanticState > iss(ss, str.c_str(), str.size());

    return doParse(iss);
}

} // namespace idl


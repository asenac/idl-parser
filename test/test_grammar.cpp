#include <iostream>
#include <cassert>
#include <sstream>
#include <idlmm.hpp>
#include "idl_parser.hpp"
#include "idl_grammar.hpp"
#include "idl_parser.ipp"

using namespace idl::grammar;
using namespace idl::parser;

template < typename Rule >
struct TestGrammar
{
    std::istringstream str_;
    SemanticState ss;
    parser::IStreamState < SemanticState > iss;
    std::ostream& err;

    TestGrammar(const char * str, std::ostream& er = std::cerr) :
        str_(str), iss(ss, str_), err(er)
    {
    }

    //const std::string& str_;
    //SemanticState ss;
    //parser::State < SemanticState > iss;
    //std::ostream& err;

    //TestGrammar(const char * str, std::ostream& er = std::cerr) :
        //str_(str), iss(ss, str_.c_str(), str_.size()), err(er)
    //{
    //}

    template < typename ExpectedResultType >
    ExpectedResultType * parse()
    {
        bool res = Rule::match(iss);

        if (!res) 
        {
            std::cout << "ERROR" << std::endl;
            iss.get_error(err);
        }

        return res? ss.result->as< ExpectedResultType >() : NULL;
    }

    ~TestGrammar()
    {
        delete ss.result;
    }
};

template< typename ExpectedResultType, typename Test >
void assertNotNull(Test& t)
{
    assert(t.template parse< ExpectedResultType >());
}

int main(int argc, char **argv)
{
    const char * module_tests[] = {
        "module A {}", 
        "module A{}", 
        "module A{ }", 
        NULL
    };
    for (const char ** i = module_tests; *i; i++)
    {
        TestGrammar< module_ > t(*i);
        assertNotNull< idlmm::ModuleDef >(t);
    }

    const char * tu_tests[] = {
        "module A {};", 
        "/***/module A {};", 
        "//\nmodule A {}; /* asas asd */ \t", 
        NULL
    };
    for (const char ** i = tu_tests; *i; i++)
    {
        TestGrammar< gram > t(*i);
        assertNotNull< idlmm::TranslationUnit >(t);
    }
    
    return 0;
}

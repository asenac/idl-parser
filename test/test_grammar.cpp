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

    bool ruleMatch() 
    {
        return Rule::match(iss);
    }

    template < typename ExpectedResultType >
    ExpectedResultType * parse()
    {
        bool res = Rule::match(iss);

        if (!res) 
            iss.get_error(err);

        return res? ss.result->as< ExpectedResultType >() : NULL;
    }

    ~TestGrammar()
    {
        delete ss.result;
    }
};

template < typename Rule >
struct TestGrammarString
{
    const std::string str_;
    SemanticState ss;
    parser::State < SemanticState > iss;
    std::ostream& err;

    TestGrammarString(const char * str, std::ostream& er = std::cerr) :
        str_(str), iss(ss, str_.c_str(), str_.size()), err(er)
    {
    }

    bool ruleMatch() 
    {
        return Rule::match(iss);
    }

    template < typename ExpectedResultType >
    ExpectedResultType * parse()
    {
        bool res = Rule::match(iss);

        if (!res) 
            iss.get_error(err);

        return res? ss.result->as< ExpectedResultType >() : NULL;
    }

    ~TestGrammarString()
    {
        delete ss.result;
    }
};

template< typename ExpectedResultType, typename Test >
void assertNotNull(Test& t)
{
    assert(t.template parse< ExpectedResultType >());
}

template< typename ExpectedResultType, typename Test >
void assertNotNullAtEnd(Test& t)
{
    assert(t.template parse< ExpectedResultType >());
    assert(t.iss.at_end());
}

int main(int argc, char **argv)
{
    // Token
    {
#define STR(tok) #tok
#define TOKEN_TEST(tok)                                                 \
        { TestGrammar< tok ## _t > t(STR(tok)); assert(t.ruleMatch()); }

        TOKEN_TEST(union);
        TOKEN_TEST(switch);
        TOKEN_TEST(module);
        TOKEN_TEST(interface);
        TOKEN_TEST(struct);

#undef TOKEN_TEST
    }

    // Union
    {
        const char * union_tests[] = {
            "union A switch (long) {\n}", 
            "union A switch(long){ default: \n long b;}", 
            NULL
        };
        for (const char ** i = union_tests; *i; i++)
        {
            TestGrammar< union_ > t(*i);
            assertNotNull< idlmm::UnionDef >(t);
        }
    }

    // Module
    {
        const char * module_tests[] = {
            "module A {}", 
            "module A{}", 
            "module A{ }", 
            "module A{ interface C {}; /* aseas23\n**/}", 
            NULL
        };
        for (const char ** i = module_tests; *i; i++)
        {
            TestGrammar< module_ > t(*i);
            assertNotNull< idlmm::ModuleDef >(t);
        }
    }

    // Translation unit
    {
        const char * tu_tests[] = {
            "module A {};", 
            "/***/module A {};", 
            "//\nmodule A {}; /* asas asd */ \t", 
            "union A switch (long) {\n};", 
            "typedef long B;\nunion A switch (B) { default: B a;\n};", 
            NULL
        };
        for (const char ** i = tu_tests; *i; i++)
        {
            TestGrammar< gram > t(*i);
            assertNotNullAtEnd< idlmm::TranslationUnit >(t);

            TestGrammarString< gram > ts(*i);
            assertNotNullAtEnd< idlmm::TranslationUnit >(ts);
        }
    }
    
    return 0;
}

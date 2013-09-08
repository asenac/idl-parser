#include <iostream>
#include <cassert>
#include <cstring>
#include <sstream>
#include <idlmm.hpp>
#include "idl_parser.hpp"
#include "idl_grammar.hpp"
#include "idl_parser.ipp"

using namespace idl::grammar;
using namespace idl::parser;

template < typename Rule, typename Reader = ::parser::Reader >
struct TestGrammar
{
    SemanticState ss;
    parser::ReaderState < SemanticState, Reader > iss;
    std::ostream& err;

    TestGrammar(Reader& r, std::ostream& er = std::cerr) :
        iss(ss, r), err(er)
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
        {   ::parser::Reader r(STR(tok), std::strlen(STR(tok)));        \
            TestGrammar< tok ## _t > t(r); assert(t.ruleMatch()); }

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
            ::parser::Reader r(*i, std::strlen(*i));
            TestGrammar< union_ > t(r);
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
            "module B { typedef string string_t; }",
            "module B { typedef string < 10 * 10 > string_t; }",
            NULL
        };
        for (const char ** i = module_tests; *i; i++)
        {
            ::parser::Reader r(*i, std::strlen(*i));
            TestGrammar< module_ > t(r);
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
            "interface Andres;",
            "typedef sequence< long, 10 > mySeq;",
            NULL
        };
        for (const char ** i = tu_tests; *i; i++)
        {
            ::parser::Reader r(*i, std::strlen(*i));
            TestGrammar< gram > t(r);
            assertNotNullAtEnd< idlmm::TranslationUnit >(t);
        }
    }
    
    return 0;
}

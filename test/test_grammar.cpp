#include <iostream>
#include <cassert>
#include <idlmm.hpp>
#include "idl_parser.hpp"
#include "idl_grammar.hpp"
#include "idl_parser.ipp"

using namespace idl::grammar;
using namespace idl::parser;

template < typename Rule >
struct TestGrammar
{
    const std::string& str_;
    SemanticState ss;
    parser::State < SemanticState > iss;

    TestGrammar(const std::string& str) :
        str_(str), iss(ss, str_.c_str(), str_.size())
    {
    }

    bool parse()
    {
        return Rule::match(iss);
    }

    ~TestGrammar()
    {
        delete ss.result;
    }
};

int main(int argc, char **argv)
{
    
    return 0;
}

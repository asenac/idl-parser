#ifndef PREPROCESSOR_HPP
#define PREPROCESSOR_HPP

#include "parser.hpp"

namespace preprocessor 
{

using namespace parser;

struct space_ : char_ < ' ' > {};
struct directive_ : 
    seq_ < 
        char_ < '#' >, 
        space_,
        positive_,
        space_, 
        string_, 
        opt_ < seq_ < space_, positive_ > >,
        char_< '\n' >
    > 
{};

struct preprocessor_ : star_< directive_ > {};

struct pp_new_line : seq_ < new_line, preprocessor_ > {};

} // namespace preprocessor

#endif /* PREPROCESSOR_HPP */

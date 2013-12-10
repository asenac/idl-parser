#ifndef PREPROCESSOR_HPP
#define PREPROCESSOR_HPP

#include <parser/parser.hpp>
#include <parser/parser_common.hpp>

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

struct ignore_ :
    seq_ <
        char_ < '#' >,
        until_< '\n' >
    >
{};

struct preprocessor_ : star_< ignore_ > {};

struct pp_new_line : seq_ < new_line, preprocessor_ > {};

struct pp_until_new_line :
    apply_until_ < not_new_line, pp_new_line >
{};

} // namespace preprocessor

#endif /* PREPROCESSOR_HPP */

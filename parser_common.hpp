#ifndef PARSER_COMMON_HPP
#define PARSER_COMMON_HPP

#include "parser.hpp"

namespace parser 
{

struct colon : char_ < ':' > {};
struct semicol : char_ < ';' > {};
struct comma : char_ < ',' > {};
struct point : char_ < '.' > {};

struct digit_ : cirange_ < '0', '9'> {};
// TODO allow scientific notation
struct number_ : 
    seq_ < plus_< digit_ >, opt_ < seq_ < point, plus_ < digit_ > > > > 
{};
struct positive_ : plus_< digit_ > {};

struct string_ :
    seq_< char_< '"' >,
          star_ < or_ <
                     seq_< char_ <'\\'>, anychar_ >, // escape
                     notchar_<'"'> // normal chars
                     > >,
          char_<'"'> >
{};

} // namespace parser

#endif /* PARSER_COMMON_HPP */

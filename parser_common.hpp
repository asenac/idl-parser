#ifndef PARSER_COMMON_HPP
#define PARSER_COMMON_HPP

#include "parser.hpp"

namespace parser 
{

typedef char_ < ';' > semicol;
typedef char_ < ',' > comma;
typedef char_ < '.' > point;

typedef cirange_ < '0', '9'> digit_;
// TODO allow scientific notation
typedef seq_ < plus_< digit_ >, opt_ < seq_ < point, plus_ < digit_ > > > > 
    number_;
typedef plus_< digit_ > positive_;

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

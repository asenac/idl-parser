#ifndef IDL_TOKENS_HPP
#define IDL_TOKENS_HPP

#include "parser.hpp"
#include "parser_common.hpp"
#include "preprocessor.hpp"

namespace idl 
{
namespace tokens 
{

using namespace ::parser;

typedef or_ <
            seq_ < char_ < '>' >, char_ < '>' > >,
            seq_ < char_ < '<' >, char_ < '<' > >
            >
            shift_operator;
typedef char_ < '&' > and_operator;
typedef char_ < '&' > or_operator;
typedef char_ < '^' > xor_operator;
//seq_ < char_ < '=' >, char_ < '=' > >

typedef or_ <
            char_ < '+' >,
            char_ < '-' >,
            char_ < '~' >
            > unary_operator;

typedef or_< char_ < '*' >, char_ < '/' >, char_ < '%' > > mult_operator;

typedef or_< char_ < '+' >, char_ < '-' > > add_operator;
typedef seq_ < opt_ < add_operator >, plus_< digit_ > > integer_;

typedef seq_< 
            or_ < 
                cirange_ < 'A', 'Z' >,
                cirange_ < 'a', 'z' >
                >,
            star_ <
                or_ < 
                    cirange_ < 'A', 'Z' >,
                    cirange_ < 'a', 'z' >,
                    digit_,
                    char_ < '_' >
                    >
                >
            > identifier_rule;

// strings
typedef string_ string_rule;

typedef seq_< char_ < ':' >, char_ < ':' > > scope_sep;

typedef seq_ < 
            opt_< scope_sep >,
            identifier_rule, 
            star_< seq_ < scope_sep, identifier_rule > > 
        > fqn_rule;

// spaces

typedef seq_ < char_ < '*' >, char_ < '/' > > ccomment_end;
typedef 
    seq_ < 
            char_ < '/' >, 
            char_ < '*' >, 
            apply_until_ < 
                // to be or not to be
                or_ < new_line, not_new_line >,
                ccomment_end 
            >
        > 
    ccomment_;

typedef seq_ < char_ < '/' >, char_ < '/' >, 
        ::preprocessor::pp_until_new_line > comment_;

// space
typedef 
    or_ < 
            char_<' '>, char_<'\t'>, 
            ::preprocessor::pp_new_line, char_<'\r'>, 
            comment_, ccomment_
        > 
    space;

// chars not allowed to be in tokens
typedef seq_ < 
            req_not_cirange_ < 'a', 'z' >,
            req_not_cirange_ < 'A', 'Z' >,
            req_not_cirange_ < '0', '9' >
            > rspace;

// token: requires an space at the end 
template <typename C0,
          typename C1,
          typename C2 = true_,
          typename C3 = true_,
          typename C4 = true_,
          typename C5 = true_,
          typename C6 = true_,
          typename C7 = true_>
struct tok_ : seq_< seq_ < C0, C1, C2, C3, C4, C5, C6, C7 >, rspace>
{
};

// Zero or more spaces
typedef star_ < space > spaces_;

// One or more spaces
typedef plus_ < space > space_;

typedef space __;

typedef char_< 'a' > a_;
typedef char_< 'b' > b_;
typedef char_< 'c' > c_;
typedef char_< 'd' > d_;
typedef char_< 'e' > e_;
typedef char_< 'f' > f_;
typedef char_< 'g' > g_;
typedef char_< 'h' > h_;
typedef char_< 'i' > i_;
typedef char_< 'j' > j_;
typedef char_< 'k' > k_;
typedef char_< 'l' > l_;
typedef char_< 'm' > m_;
typedef char_< 'n' > n_;
typedef char_< 'o' > o_;
typedef char_< 'p' > p_;
typedef char_< 'q' > q_;
typedef char_< 'r' > r_;
typedef char_< 's' > s_;
typedef char_< 't' > t_;
typedef char_< 'u' > u_;
typedef char_< 'v' > v_;
typedef char_< 'w' > w_;
typedef char_< 'x' > x_;
typedef char_< 'y' > y_;
typedef char_< 'z' > z_;
typedef char_< 'A' > A_;
typedef char_< 'B' > B_;
typedef char_< 'C' > C_;
typedef char_< 'D' > D_;
typedef char_< 'E' > E_;
typedef char_< 'F' > F_;
typedef char_< 'G' > G_;
typedef char_< 'H' > H_;
typedef char_< 'I' > I_;
typedef char_< 'J' > J_;
typedef char_< 'K' > K_;
typedef char_< 'L' > L_;
typedef char_< 'M' > M_;
typedef char_< 'N' > N_;
typedef char_< 'O' > O_;
typedef char_< 'P' > P_;
typedef char_< 'Q' > Q_;
typedef char_< 'R' > R_;
typedef char_< 'S' > S_;
typedef char_< 'T' > T_;
typedef char_< 'U' > U_;
typedef char_< 'V' > V_;
typedef char_< 'W' > W_;
typedef char_< 'X' > X_;
typedef char_< 'Y' > Y_;
typedef char_< 'Z' > Z_;

typedef tok_ < o_, c_, t_, e_, t_ > octet_t;
typedef tok_ < c_, h_, a_, r_ > char_t;
typedef tok_ < l_, o_, n_, g_ > long_t;
typedef tok_ < u_, n_, s_, i_, g_, n_, e_, seq_ < d_, __, l_, o_, n_, g_ > > unsigned_long_t;
typedef tok_ < s_, h_, o_, r_, t_ > short_t;
typedef tok_ < u_, n_, s_, i_, g_, n_, e_, seq_ < d_, __, s_, h_, o_, r_, t_ > > unsigned_short_t;
typedef tok_ < f_, l_, o_, a_, t_ > float_t;
typedef tok_ < d_, o_, u_, b_, l_, e_ > double_t;
typedef tok_ < l_, o_, n_, g_, __, d_, o_, seq_ < u_, b_, l_, e_ > > long_double_t;
typedef tok_ < l_, o_, n_, g_, __, l_, o_, seq_ < n_, g_ > > long_long_t;
typedef tok_ < u_, n_, s_, i_, g_, n_, e_, seq_ < d_, __, l_, o_, n_, g_, __, seq_ < l_, o_, n_, g_ > > > unsigned_long_long_t;
typedef tok_ < a_, t_, t_, r_, i_, b_, u_, seq_ < t_, e_ > > attribute_t;
typedef tok_ < o_, n_, e_, w_, a_, y_ > oneway_t;
typedef tok_ < r_, e_, a_, d_, o_, n_, l_, y_ > readonly_t;
typedef tok_ < i_, n_ > in_t;
typedef tok_ < o_, u_, t_ > out_t;
typedef tok_ < i_, n_, o_, u_, t_ > inout_t;
typedef tok_ < s_, t_, r_, u_, c_, t_ > struct_t;
typedef tok_ < m_, o_, d_, u_, l_, e_ > module_t;
typedef tok_ < i_, n_, t_, e_, r_, f_, a_, seq_ < c_, e_ > > interface_t;
typedef tok_ < a_, b_, s_, t_, r_, a_, c_, t_ > abstract_t;
typedef tok_ < t_, y_, p_, e_, d_, e_, f_ > typedef_t;
typedef tok_ < s_, t_, r_, i_, n_, g_ > string_t;
typedef tok_ < w_, s_, t_, r_, i_, n_, g_ > wstring_t;
typedef tok_ < v_, o_, i_, d_ > void_t;
typedef tok_ < e_, n_, u_, m_ > enum_t;
typedef tok_ < s_, e_, q_, u_, e_, n_, c_, e_ > sequence_t;
typedef tok_ < c_, o_, n_, s_, t_ > const_t;
typedef tok_ < t_, r_, u_, e_ > true_t;
typedef tok_ < f_, a_, l_, s_, e_ > false_t;
typedef tok_ < u_, n_, i_, o_, n_ > union_t;
typedef tok_ < c_, a_, s_, e_ > case_t;
typedef tok_ < s_, w_, i_, t_, c_, h_ > switch_t;
typedef tok_ < d_, e_, f_, a_, u_, l_, t_ > default_t;
typedef tok_ < e_, x_, c_, e_, p_, t_, i_, seq_ < o_, n_ > > exception_t;

template< char i, typename Rule, char e >
struct embrace_ : seq_ < char_ < i >, spaces_, Rule, spaces_, char_ < e > >
{};

typedef or_ < true_t, false_t > bool_; 

// expressions
//struct exp_item;

//struct exp_item : 
    //or_ < 
        //number_, 
        //identifier_rule,  
        //bool_,
        //embrace_ < '(', exp_item, ')' >
        //>
//{};

//typedef seq_< 
            //spaces_,
            //exp_item, 
            //spaces_,
            //star_ < seq_ < operator_, spaces_, exp_item, spaces_ > > 
            //> expression_rule;

} // namespace tokens
} // namespace idl

#endif /* IDL_TOKENS_HPP */

#ifndef IDL_TOKENS_HPP
#define IDL_TOKENS_HPP

#include <parser/parser.hpp>
#include <parser/parser_common.hpp>
#include <parser/preprocessor.hpp>

namespace idl
{
namespace tokens
{

using namespace ::parser;

struct shift_operator :
    or_ <
            seq_ < char_ < '>' >, char_ < '>' > >,
            seq_ < char_ < '<' >, char_ < '<' > >
        >
{};
struct and_operator : char_ < '&' > {};
struct or_operator : char_ < '&' > {};
struct xor_operator : char_ < '^' > {};
//seq_ < char_ < '=' >, char_ < '=' > >

struct unary_operator :
    or_ <
            char_ < '+' >,
            char_ < '-' >,
            char_ < '~' >
        >
{};

struct mult_operator : or_< char_ < '*' >, char_ < '/' >, char_ < '%' > > {};

struct add_operator : or_< char_ < '+' >, char_ < '-' > > {};
struct integer_ : seq_ < opt_ < add_operator >, plus_< digit_ > > {};

struct identifier_rule :
    seq_<
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
            >
{};

// strings
typedef string_ string_rule;

struct scope_sep : seq_< char_ < ':' >, char_ < ':' > > {};

struct fqn_rule :
    seq_ <
            opt_< scope_sep >,
            identifier_rule,
            star_< seq_ < scope_sep, identifier_rule > >
        >
{};

// spaces

struct ccomment_end : seq_ < char_ < '*' >, char_ < '/' > > {};
struct ccomment_ :
    seq_ <
            char_ < '/' >,
            char_ < '*' >,
            apply_until_ <
                // to be or not to be
                or_ < new_line, not_new_line >,
                ccomment_end
            >
        >
{};

struct comment_ :
    seq_ < char_ < '/' >, char_ < '/' >,
        ::preprocessor::pp_until_new_line >
{};

// space
struct space :
    or_ <
            char_<' '>, char_<'\t'>,
            ::preprocessor::pp_new_line, char_<'\r'>,
            comment_, ccomment_
        >
{};

// chars not allowed to be in tokens
struct rspace : seq_ <
            req_not_cirange_ < 'a', 'z' >,
            req_not_cirange_ < 'A', 'Z' >,
            req_not_cirange_ < '0', '9' >
            >
{};

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
struct spaces_ : star_ < space > {};

// One or more spaces
struct space_ : plus_ < space > {};

struct __ : space {};

struct a_ : char_< 'a' > {};
struct b_ : char_< 'b' > {};
struct c_ : char_< 'c' > {};
struct d_ : char_< 'd' > {};
struct e_ : char_< 'e' > {};
struct f_ : char_< 'f' > {};
struct g_ : char_< 'g' > {};
struct h_ : char_< 'h' > {};
struct i_ : char_< 'i' > {};
struct j_ : char_< 'j' > {};
struct k_ : char_< 'k' > {};
struct l_ : char_< 'l' > {};
struct m_ : char_< 'm' > {};
struct n_ : char_< 'n' > {};
struct o_ : char_< 'o' > {};
struct p_ : char_< 'p' > {};
struct q_ : char_< 'q' > {};
struct r_ : char_< 'r' > {};
struct s_ : char_< 's' > {};
struct t_ : char_< 't' > {};
struct u_ : char_< 'u' > {};
struct v_ : char_< 'v' > {};
struct w_ : char_< 'w' > {};
struct x_ : char_< 'x' > {};
struct y_ : char_< 'y' > {};
struct z_ : char_< 'z' > {};
struct A_ : char_< 'A' > {};
struct B_ : char_< 'B' > {};
struct C_ : char_< 'C' > {};
struct D_ : char_< 'D' > {};
struct E_ : char_< 'E' > {};
struct F_ : char_< 'F' > {};
struct G_ : char_< 'G' > {};
struct H_ : char_< 'H' > {};
struct I_ : char_< 'I' > {};
struct J_ : char_< 'J' > {};
struct K_ : char_< 'K' > {};
struct L_ : char_< 'L' > {};
struct M_ : char_< 'M' > {};
struct N_ : char_< 'N' > {};
struct O_ : char_< 'O' > {};
struct P_ : char_< 'P' > {};
struct Q_ : char_< 'Q' > {};
struct R_ : char_< 'R' > {};
struct S_ : char_< 'S' > {};
struct T_ : char_< 'T' > {};
struct U_ : char_< 'U' > {};
struct V_ : char_< 'V' > {};
struct W_ : char_< 'W' > {};
struct X_ : char_< 'X' > {};
struct Y_ : char_< 'Y' > {};
struct Z_ : char_< 'Z' > {};

struct octet_t : tok_ < o_, c_, t_, e_, t_ > {};
struct char_t : tok_ < c_, h_, a_, r_ > {};
struct long_t : tok_ < l_, o_, n_, g_ > {};
struct unsigned_long_t : tok_ < u_, n_, s_, i_, g_, n_, e_, seq_ < d_, __, l_, o_, n_, g_ > > {};
struct short_t : tok_ < s_, h_, o_, r_, t_ > {};
struct unsigned_short_t : tok_ < u_, n_, s_, i_, g_, n_, e_, seq_ < d_, __, s_, h_, o_, r_, t_ > > {};
struct float_t : tok_ < f_, l_, o_, a_, t_ > {};
struct double_t : tok_ < d_, o_, u_, b_, l_, e_ > {};
struct long_double_t : tok_ < l_, o_, n_, g_, __, d_, o_, seq_ < u_, b_, l_, e_ > > {};
struct long_long_t : tok_ < l_, o_, n_, g_, __, l_, o_, seq_ < n_, g_ > > {};
struct unsigned_long_long_t : tok_ < u_, n_, s_, i_, g_, n_, e_, seq_ < d_, __, l_, o_, n_, g_, __, seq_ < l_, o_, n_, g_ > > > {};
struct attribute_t : tok_ < a_, t_, t_, r_, i_, b_, u_, seq_ < t_, e_ > > {};
struct oneway_t : tok_ < o_, n_, e_, w_, a_, y_ > {};
struct readonly_t : tok_ < r_, e_, a_, d_, o_, n_, l_, y_ > {};
struct in_t : tok_ < i_, n_ > {};
struct out_t : tok_ < o_, u_, t_ > {};
struct inout_t : tok_ < i_, n_, o_, u_, t_ > {};
struct struct_t : tok_ < s_, t_, r_, u_, c_, t_ > {};
struct module_t : tok_ < m_, o_, d_, u_, l_, e_ > {};
struct interface_t : tok_ < i_, n_, t_, e_, r_, f_, a_, seq_ < c_, e_ > > {};
struct abstract_t : tok_ < a_, b_, s_, t_, r_, a_, c_, t_ > {};
struct typedef_t : tok_ < t_, y_, p_, e_, d_, e_, f_ > {};
struct string_t : tok_ < s_, t_, r_, i_, n_, g_ > {};
struct wstring_t : tok_ < w_, s_, t_, r_, i_, n_, g_ > {};
struct void_t : tok_ < v_, o_, i_, d_ > {};
struct enum_t : tok_ < e_, n_, u_, m_ > {};
struct sequence_t : tok_ < s_, e_, q_, u_, e_, n_, c_, e_ > {};
struct const_t : tok_ < c_, o_, n_, s_, t_ > {};
struct true_t : tok_ < t_, r_, u_, e_ > {};
struct false_t : tok_ < f_, a_, l_, s_, e_ > {};
struct union_t : tok_ < u_, n_, i_, o_, n_ > {};
struct case_t : tok_ < c_, a_, s_, e_ > {};
struct switch_t : tok_ < s_, w_, i_, t_, c_, h_ > {};
struct default_t : tok_ < d_, e_, f_, a_, u_, l_, t_ > {};
struct exception_t : tok_ < e_, x_, c_, e_, p_, t_, i_, seq_ < o_, n_ > > {};
struct valuetype_t : tok_ < v_, a_, l_, u_, e_, t_, y_, seq_ < p_, e_ > > {};
struct factory_t : tok_ < f_, a_, c_, t_, o_, r_, y_ > {};
struct setraises_t : tok_ < s_, e_, t_, r_, a_, i_, s_, seq_ < e_, s_ > > {};
struct getraises_t : tok_ < g_, e_, t_, r_, a_, i_, s_, seq_ < e_, s_ > > {};
struct raises_t : tok_ < r_, a_, i_, s_, e_, s_ > {};
struct public_t : tok_ < p_, u_, b_, l_, i_, c_ > {};
struct private_t : tok_ < p_, r_, i_, v_, a_, t_, e_ > {};
struct fixed_t : tok_ < f_, i_, x_, e_, d_ > {};

template< char i, typename Rule, char e >
struct embrace_ : seq_ < char_ < i >, spaces_, Rule, spaces_, char_ < e > >
{};

struct bool_ : or_ < true_t, false_t > {};

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

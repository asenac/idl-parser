#ifndef IDL_GRAMMAR_HPP
#define IDL_GRAMMAR_HPP

#include "parser.hpp"
#include "idl_tokens.hpp"

namespace idl 
{
namespace grammar 
{

using namespace ::parser;
using namespace tokens;

enum primitive_types
{
    PT_UNSIGNED_SHORT,
    PT_UNSIGNED_LONG_LONG,
    PT_UNSIGNED_LONG,
    PT_LONG_DOUBLE,
    PT_LONG_LONG,
    PT_LONG,
    PT_OCTET,
    PT_CHAR,
    PT_SHORT,
    PT_FLOAT,
    PT_DOUBLE,
    PT_STRING,
    PT_WSTRING,
    PT_VOID,
    PT_NULL
};

template < typename Name, primitive_types type >
struct primitive_type : 
    semantic_rule < primitive_type < Name, type >, Name >
{
    template <typename S, typename match_pair>
    static inline void process_match (S& state, match_pair const& mp)
    {
        state.semantic_state().set_primitive_type(type);
    }
};


struct const_expr;
struct string_def : 
    seq_< string_t, opt_ < seq_ < spaces_, embrace_< '<', const_expr, '>' > > > >
{};
struct wstring_def : 
    seq_< wstring_t, opt_ < seq_ < spaces_, embrace_< '<', const_expr, '>' > > > >
{};


struct primitive_types_rule :
    or_<
       primitive_type < unsigned_short_t, PT_UNSIGNED_SHORT >,
       primitive_type < unsigned_long_long_t, PT_UNSIGNED_LONG_LONG >,
       primitive_type < unsigned_long_t, PT_UNSIGNED_LONG >,
       primitive_type < long_double_t, PT_LONG_DOUBLE >,
       primitive_type < long_long_t, PT_LONG_LONG >,
       primitive_type < long_t, PT_LONG >,
       primitive_type < octet_t, PT_OCTET >,
       or_ <
           primitive_type < void_t, PT_VOID >,
           primitive_type < char_t, PT_CHAR >,
           primitive_type < short_t, PT_SHORT >,
           primitive_type < float_t, PT_FLOAT >,
           primitive_type < double_t, PT_DOUBLE >,
           primitive_type < string_t, PT_STRING >,
           primitive_type < wstring_t, PT_WSTRING >
       >
    > 
{};

enum flags
{
    FLAG_ONEWAY,
    FLAG_READONLY,
    FLAG_ABSTRACT,
    FLAG_IN,
    FLAG_OUT,
    FLAG_INOUT,
    FLAG_DEFAULT
};

template < typename Name, flags flag >
struct flag_ : semantic_rule < flag_ < Name, flag >, Name >
{
    template <typename S, typename match_pair>
    static inline void process_match (S& state, match_pair const& mp)
    {
        state.semantic_state().set_flag(flag);
    }
};

template < typename Name, flags flag >
struct optflag_ : opt_< seq_< flag_ < Name, flag >, space_ > >
{
};

template < typename rule >
struct data_ : 
    semantic_rule < data_ < rule >, rule >
{
    template <typename S, typename match_pair>
    static inline void process_match (S& state, match_pair const& mp)
    {
        state.semantic_state().set_data(state, mp);
    }
};

enum semantic_context_type
{
    CONTEXT_TRANSLATION_UNIT,
    CONTEXT_MODULE,
    CONTEXT_INTERFACE,
    CONTEXT_INTERFACE_FWD,
    CONTEXT_STRUCT,
    CONTEXT_STRUCT_FIELD,
    CONTEXT_UNION,
    CONTEXT_UNION_FIELD,
    CONTEXT_ALIAS,
    CONTEXT_ARRAY,
    CONTEXT_ATTRIBUTE,
    CONTEXT_OPERATION,
    CONTEXT_PARAMETER,
    CONTEXT_ENUM,
    CONTEXT_SEQUENCE,
    CONTEXT_STRING,
    CONTEXT_WSTRING,
    CONTEXT_CONST,
    CONTEXT_EXCEPTION,
    CONTEXT_VALUETYPE,
    CONTEXT_FIXED,

    // Expressions
    CONTEXT_UNARY_EXPRESSION,
    CONTEXT_BINARY_EXPRESSION,
    CONTEXT_VALUE_EXPRESSION,
    CONTEXT_CONSTANT_REF
};

template < typename C0, semantic_context_type type >
struct semantic_context
{
    typedef semantic_rule < semantic_context, C0 > rule_t;

    template <typename S>
    static inline bool match (S& state)
    {
        state.semantic_state().new_context(type);

        bool res = rule_t::match(state);
        res ? 
            state.semantic_state().commit() : 
            state.semantic_state().rollback();

        return res;
    }

    template <typename S, typename match_pair>
    static inline void process_match (S& state, match_pair const& mp)
    {
        state.semantic_state().set_context_data(state, mp);
    }
};

struct identifier_ :
    semantic_rule < 
        identifier_,
        identifier_rule
    >
{
    template <typename S, typename match_pair>
    static inline void process_match (S& state, match_pair const& mp)
    {
        const std::string s (state.to_string(mp.first, mp.second));
        state.semantic_state().push_identifier(s);
    }
};

struct literal_ :
    semantic_rule < 
        literal_,
        identifier_rule
    >
{
    template <typename S, typename match_pair>
    static inline void process_match (S& state, match_pair const& mp)
    {
        const std::string s (state.to_string(mp.first, mp.second));
        state.semantic_state().push_literal(s);
    }
};

struct type_fqn_ :
    data_< 
        fqn_rule
    >
{};

struct type_rule :
    or_ < primitive_types_rule, type_fqn_ >
{};

// attribute

struct attribute_rule :
    seq_ < 
            optflag_<  readonly_t, FLAG_READONLY >,
            attribute_t,
            space_,
            type_rule,
            space_,
            identifier_
        > 
{};
struct attribute_ :
    semantic_context < 
        attribute_rule,
        CONTEXT_ATTRIBUTE
    >
{};

// operation

struct direction_rule :
    or_ < 
            flag_ < inout_t, FLAG_INOUT >,   
            flag_ < in_t, FLAG_IN >, 
            flag_ < out_t, FLAG_OUT > 
        >
{};
struct parameter_rule :
    seq_ < 
            direction_rule, 
            space_,
            type_rule , 
            space_, 
            identifier_
         > 
{};
struct parameter_ : semantic_context< parameter_rule, CONTEXT_PARAMETER >
{};

template < typename Item >
struct item_ :
    seq_ <
            spaces_,
            Item,
            spaces_
         >
{};


// useful for comma-separated lists
template < typename Item, typename Sep = comma >
struct pluslist_ :
    seq_ <
            item_ < Item >,
            star_ < seq_ < Sep, item_ < Item > > >
         > 
{};

template < typename Item, typename Sep = comma >
struct list_ :
    or_ <
        pluslist_< Item, Sep >,
        spaces_ 
    >
{};

struct parameter_list : list_ < parameter_ > {};

struct fqn_usage : 
    semantic_rule < fqn_usage, fqn_rule >
{
    template <typename S, typename match_pair>
    static inline void process_match (S& state, match_pair const& mp)
    {
        const std::string s (state.to_string(mp.first, mp.second));
        state.semantic_state().push_literal(s);
    }
};

struct raises_ : 
    seq_ < raises_t, embrace_< '(', pluslist_ < fqn_usage  >, ')' > >
{};

struct operation_rule :
    seq_ < 
            optflag_< oneway_t, FLAG_ONEWAY >,
            type_rule,
            space_,
            identifier_,
            embrace_ < '(', parameter_list, ')' >,
            opt_ < seq_ < spaces_, raises_ > >
        > 
{};
struct operation_ :
    semantic_context < 
        operation_rule,
        CONTEXT_OPERATION
    >
{};

// constant
struct const_expr;
struct mult_expr;
struct add_expr;

struct constant_ref_expr :
    semantic_context< data_ < fqn_rule >, CONTEXT_CONSTANT_REF > 
{};

struct value_rule : or_ < string_rule, bool_, number_ > {}; 

struct value_expr :
    semantic_context< 
                data_ < value_rule >,
                CONTEXT_VALUE_EXPRESSION 
            > 
{};

struct primary_expr :
or_ < 
                value_expr, 
                constant_ref_expr,  
                embrace_ < '(', const_expr, ')' >
            > 
{};

struct unary_expr :
    semantic_context< 
                seq_ <  
                        data_ < unary_operator >, spaces_, primary_expr 
                    >, 
                    CONTEXT_UNARY_EXPRESSION 
                > 
{};

template < typename Operator, typename Left, typename Right = Left >
struct binary_expr :
    semantic_context< 
        seq_ <  
            Left, 
            opt_ <
                seq_ <
                    spaces_, 
                    data_ < Operator >, 
                    spaces_, 
                    Right
                >
            >
        >, 
        CONTEXT_BINARY_EXPRESSION >
{};

struct mult_expr :  
    binary_expr < mult_operator, primary_expr, mult_expr > 
{};

struct add_expr :  
    binary_expr < add_operator, mult_expr > 
{};

struct shift_expr :  
    binary_expr < shift_operator, add_expr > 
{};

struct and_expr :  
    binary_expr < and_operator, shift_expr > 
{};

struct xor_expr :  
    binary_expr < xor_operator, and_expr > 
{};

struct or_expr :  
    binary_expr < or_operator, xor_expr > 
{};

struct const_expr : or_expr
{};

struct const_rule :
    seq_ < 
                const_t, 
                space_, 
                type_rule, 
                space_, 
                identifier_, 
                spaces_,
                seq_ < 
                        char_ < '=' >, 
                        spaces_, 
                        const_expr
                > 
        > 
{};

struct const_ : semantic_context< const_rule, CONTEXT_CONST >
{};

// sequence

struct sequence_rule :
    seq_< 
        sequence_t, 
        spaces_, 
        char_ < '<' >, 
        spaces_, 
        type_rule, 
        spaces_, 
        opt_< seq_ < comma, spaces_, const_expr, spaces_ > >,
        char_ < '>' > 
    > 
{};

struct sequence_ :
    semantic_context < 
        sequence_rule,
        CONTEXT_SEQUENCE
    >
{};

// fixed 
struct fixed_rule :
    seq_< 
        fixed_t, 
        spaces_, 
        embrace_ < 
            '<',  
            seq_ < const_expr, spaces_,   comma, spaces_, const_expr >,
            '>' 
            > 
    > 
{};
struct fixed_ :
    semantic_context < 
        fixed_rule,
        CONTEXT_FIXED
    >
{};

struct typedef_string_ : semantic_context< string_def, CONTEXT_STRING >
{};

struct typedef_wstring_ : semantic_context< wstring_def, CONTEXT_WSTRING >
{};

// typedefs

struct typedef_type_rule : 
    or_ < 
        typedef_string_, typedef_wstring_, 
        sequence_, fixed_, type_rule 
    > 
{};

struct alias_rule : 
    seq_ < 
        typedef_t, space_, 
        typedef_type_rule, space_, 
        pluslist_ < literal_  > 
    >
{};

struct alias_ :
    semantic_context < 
        alias_rule,
        CONTEXT_ALIAS
    >
{
};

struct array_rule :
    seq_ < 
            typedef_t, space_, type_rule, space_, identifier_, spaces_,
            plus_ < embrace_<'[', const_expr, ']' > >
        > 
{};

struct array_ :
    semantic_context < 
        array_rule,
        CONTEXT_ARRAY
    >
{
};

// contexts

template < typename Statements, typename Sep = semicol >
struct context_: 
    embrace_ < 
            '{', 
                star_< seq_ < spaces_, Statements, spaces_, Sep > >,
            '}' 
        > 
{};

template < typename Name, 
           typename Body, 
           semantic_context_type type,
           typename PreContext = true_,
           typename Sep = semicol >
struct context_rule : 
    seq_< 
        Name, space_, 
        semantic_context < 
            seq_ < identifier_, spaces_, PreContext, spaces_, context_ < Body, Sep > >, 
            type 
        >
    >
{};

// struct

struct struct_field :
    semantic_context < 
            seq_ < type_rule, space_, pluslist_< literal_ > >, 
            CONTEXT_STRUCT_FIELD 
        > 
{};

typedef struct_field struct_body; 
struct struct_ : 
    context_rule< struct_t, struct_body, CONTEXT_STRUCT > 
{};

// exception 

struct exception_ :
    context_rule< exception_t, struct_field, CONTEXT_EXCEPTION > 
{};

// value type
struct valuetype_body : struct_field 
{};
struct valuetype_ : 
    context_rule < valuetype_t, valuetype_body, CONTEXT_VALUETYPE >
{};

// union

struct union_field :
    semantic_context < 
            seq_ < 
                star_ < 
                    seq_ < 
                        or_ <
                            seq_ <
                                case_t, 
                                space_, 
                                const_expr 
                                >,
                            flag_< default_t, FLAG_DEFAULT >
                            >,
                        spaces_, 
                        char_ < ':' >, 
                        spaces_ 
                        > 
                    >, 
                type_rule, 
                space_, 
                identifier_ 
                >, 
            CONTEXT_UNION_FIELD 
        > 
{};

typedef union_field union_body; 
struct discriminator_ : seq_< switch_t, spaces_, embrace_ < '(' , type_rule, ')' > > 
{};
struct union_ : context_rule< union_t, union_body, CONTEXT_UNION, discriminator_ > 
{};

template < typename Name, 
           typename Body, 
           semantic_context_type type,
           typename Sep = comma >
struct list_context : 
    seq_< 
        Name, space_, 
        semantic_context < 
            seq_ < 
                identifier_, 
                spaces_, 
                embrace_ < '{', list_ < Body, Sep >, '}' > 
                >, 
            type 
        >
    >
{};

struct enum_ :
    list_context < 
            enum_t, 
            literal_, 
            CONTEXT_ENUM
        > 
{};

// Can it be an interface within an interface?
struct contained_ : 
    or_< const_, array_, alias_, exception_, struct_, union_, enum_ >
{};

typedef fqn_usage super_type;

struct interface_body : 
    or_< contained_, attribute_, operation_ > 
{};
struct inheritance_ : opt_ < seq_< char_ < ':' >, pluslist_ < super_type > > >
{};
struct interface_ :
    context_rule< 
            interface_t, 
            interface_body, 
            CONTEXT_INTERFACE,
            inheritance_
        > 
{};

struct interface_fwd_ :
    semantic_context< 
            seq_ < interface_t, space_, identifier_ >, 
            CONTEXT_INTERFACE_FWD
        > 
{};

struct module_;
struct module_body : or_< module_, interface_, contained_ >
{};
struct module_ : context_rule < module_t, module_body, CONTEXT_MODULE >
{};

struct statement_ :
    seq_ < 
            spaces_, 
            or_ < module_, interface_, interface_fwd_, contained_ >, 
            spaces_, 
            semicol 
        > 
{};

struct gram :
    semantic_context < 
            seq_ < 
                ::preprocessor::preprocessor_, 
                star_ < statement_ >, 
                spaces_, 
                eof_ 
            >, 
            CONTEXT_TRANSLATION_UNIT 
        >
{};

} // namespace grammar
} // namespace idl

#endif /* IDL_GRAMMAR_HPP */

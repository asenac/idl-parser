#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <utility>
#include <vector>
//#include <exception> // Exceptions
//#include <stdexcept>

namespace parser
{

struct Reader
{
    // Position type
    typedef const char * PositionType;

    // buffer
    PositionType buf_;
    // actual pos
    PositionType pos_;
    // buf_fer length
    std::size_t len_;

    Reader(const char* b, std::size_t l)
        : buf_ (b), pos_ (b),  len_(l) 
    {
    }

    inline bool
    at_end() const
    {
        return static_cast<std::size_t>(pos_ - buf_) == len_;
    }

    inline char
    char_at_pos () const
    {
        return *pos_;
    }

    inline void
    advance()
    {
        ++pos_;
    }

    inline PositionType
    pos()
    {
        return pos_;
    }

    inline void 
    set_pos(PositionType p)
    {
        pos_ = p;
    }

    inline std::string
    to_string(const char * p, std::size_t size) const
    {
        return std::string(p, size);
    }

    std::pair< PositionType, PositionType > get_line(const char * p)
    {
        PositionType init =  p;
        PositionType end =  p;

        if (init > buf_)
        {
            do 
            {
                init--;
            }
            while (init > buf_ && *init != '\n');

            if (*init == '\n') init++;
        }

        while (end < buf_ + len_ && *end != '\n')
            end++;

        return std::make_pair(init, end);
    }
};

struct IStreamReader
{
    // Position type
    typedef std::streampos PositionType;

    // stream
    std::istream& in_;

    IStreamReader(std::istream& in)
        : in_ (in) 
    {
    }

    inline bool
    at_end() const
    {
        return !in_.good();
    }

    inline char
    char_at_pos () const
    {
        return in_.peek();
    }

    inline void
    advance()
    {
        in_.get();
    }

    inline PositionType
    pos()
    {
        return in_.tellg();
    }

    inline void 
    set_pos(PositionType p)
    {
        in_.seekg(p);
    }

    inline std::string
    to_string(std::streampos p, std::size_t size)
    {
        const std::streampos old = in_.tellg();

        std::vector< char > buffer(size);
        in_.seekg(p);
        in_.read(&*buffer.begin(), size);
        in_.seekg(old);

        return std::string(buffer.begin(), buffer.end());
    }

    std::pair< PositionType, PositionType > get_line(PositionType p)
    {
        PositionType init =  p;

        // Begining
        if (init > 0)
        {
            do 
            {
                in_.seekg(init);
                in_.seekg(-1, in_.cur);
                init = in_.tellg();
            }
            while (in_.good() && in_.peek() != '\n');

            if (!in_.good())
            {
                in_.clear();
                in_.seekg(0, in_.beg);
                init = in_.tellg();
            }
            else if (in_.peek() == '\n')
            {
                in_.seekg(1, in_.cur);
                init = in_.tellg();
            }
        }

        // End
        in_.seekg(p);

        while (!at_end() && in_.peek() != '\n')
            in_.get();

        if (at_end())
        {
            in_.clear();
            in_.seekg(0, in_.end);
        }

        return std::make_pair(init, in_.tellg());
    }
};

template <typename SemanticState, typename Reader >
struct ReaderState
{
    // For reference, the SemanticState itself.
    typedef SemanticState SemType;

    // Position type
    typedef typename Reader::PositionType PositionType;

    // The inner semantic state.
    SemanticState& ss_;

    Reader& reader_;

    // State stack, for backtracking
    std::vector< PositionType > pos_stack_;

    PositionType max_pos_;

    std::size_t line_;

    std::vector< std::size_t > line_stack_;

    // ctor
    ReaderState (SemanticState& ss, Reader& r)
        : ss_ (ss), reader_(r), max_pos_(pos()), line_(1)
    {
    }

    SemanticState&
    semantic_state()
    {
        return ss_;
    }

    inline void
    new_line()
    {
        line_++;
    }

    inline bool
    at_end() const
    {
        return reader_.at_end();
    }

    inline bool
    match_at_pos_advance (char c)
    {
        if (!at_end() && reader_.char_at_pos() == c)
        {
            reader_.advance();
            return true;
        }
        return false;
    }

    inline bool
    match_at_pos (char c) const
    {
        return !at_end() && (reader_.char_at_pos() == c);
    }

    inline char
    char_at_pos() const
    {
        return reader_.char_at_pos();
    }

    inline PositionType pos() const
    {
        return reader_.pos();
    }

    inline void
    advance()
    {
        if (!at_end())
            reader_.advance();

        // TODO: throw at_end
    }

    // Common interface
    inline void
    push_state()
    {
        line_stack_.push_back (line_);
        pos_stack_.push_back (pos());
    }

    inline void
    check_max()
    {
        PositionType p = pos();
        if (max_pos_ < p)
            max_pos_ = p;
    }

    inline void
    rollback()
    {
        check_max();
        reader_.set_pos(pos_stack_.back());
        line_ = line_stack_.back();
        pos_stack_.pop_back();
        line_stack_.pop_back();
    }

    inline void
    commit()
    {
        check_max();
        pos_stack_.pop_back();
        line_stack_.pop_back();
    }

    inline std::string
    to_string(PositionType p, std::size_t size) const
    {
        return reader_.to_string(p, size);
    }

    template < typename Stream >
    void get_error(Stream& ss)
    {
        if (max_pos_)
        {
            const std::pair< PositionType, PositionType > p =
                reader_.get_line(max_pos_);

            // error line
            const std::size_t size = p.second - p.first;
            ss << to_string(p.first, size) << std::endl;

            // marker
            const std::size_t diff = max_pos_ - p.first;
            for (std::size_t i = 0; i < diff; i++) 
                ss << ' ';
            ss << '^' << std::endl;
        }
    }
};

////////////////////////////////////////////////////////////////////////
// parser
// based on the wonderful yard parser http://code.google.com/p/yardparser/
template <bool b>
struct identity
{
    template <typename whatever>
    static inline bool match (whatever const&)
    {
        return b;
    }
};

typedef identity<true> true_;
typedef identity<false> false_;

// lambda, empty rule
typedef true_ empty_;

struct eof_
{
    template <typename S>
    static inline bool match (S& state)
    {
        return state.at_end();
    }
};

template <char c>
struct char_
{
    template <typename S>
    static inline bool match (S& state)
    {
        return state.match_at_pos_advance (c);
    }
};

// NOTE: I could have implemented this in some other way
// but it would need a negative match with another Truth Environment
// or something...
template <char c>
struct notchar_
{
    template <typename S>
    static inline bool match (S& state)
    {
        if (state.at_end())
            return false;

        if (state.match_at_pos (c))
            return false;
        state.advance();
        return true;
    }
};

// NOTE: cannot be done this way
// template <typename C0>
// struct not_
// {
//     template <typename S>
//     static inline bool match (S& state)
//     {
//         return !C0::match (state);
//     }
// };

// character range, not inclusive
template <char c1, char c2>
struct crange_
{
    template <typename S>
    static inline bool match (S& state)
    {
        if (state.at_end())
            return false;

        char c = state.char_at_pos();
        if (c >= c1 && c < c2)
        {
            state.advance();
            return true;
        }
        return false;
    }
};

// character range, inclusive
template <char c1, char c2>
struct cirange_
{
    template <typename S>
    static inline bool match (S& state)
    {
        if (state.at_end())
            return false;

        char c = state.char_at_pos();
        if (c >= c1 && c <= c2)
        {
            state.advance();
            return true;
        }
        return false;
    }
};

struct anychar_
{
    template <typename S>
    static inline bool match (S& state)
    {
        if (state.at_end())
            return false;

        state.advance();
        return true;
    }
};

// Useful for '*/'
template <char c1, char c2>
struct untilchars_
{
    template <typename S>
    static inline bool match (S& state)
    {
        while (!state.at_end())
        {
            const bool res = state.match_at_pos(c1);
            state.advance(); // advance anyway
            if (res && state.match_at_pos_advance(c2))
                return true;
        }

        return false;
    }
};

// Non-advance rules
// requires char
template <char c>
struct req_
{
    template <typename S>
    static inline bool match (S& state)
    {
        return state.match_at_pos (c);
    }
};

template <char c1, char c2>
struct req_not_cirange_
{
    template <typename S>
    static inline bool match (S& state)
    {
        if (state.at_end())
            return true;

        char c = state.char_at_pos();
        if (c >= c1 && c <= c2)
        {
            return false;
        }
        return true;
    }
};

// Semantic Rule: for rules that want a process_match operation to be
// called in their A type. Usually tends to be the class itself, but
// I'll try different approaches using the state...
template <typename A, typename C0>
struct semantic_rule
{
    template <typename S>
    static inline bool match (S& state)
    {
        typename S::PositionType p = state.pos();

        // Try the rule itself
        bool result;
        if (true == (result = C0::match (state)))
            A::process_match (state, std::make_pair (p, state.pos() - p));

        return result;
    }
};

template <typename A>
struct semantic_action : semantic_rule < A, true_ >
{
};

// Ordered sequence of elements: abc
template <typename C0,
          typename C1,
          typename C2 = true_,
          typename C3 = true_,
          typename C4 = true_,
          typename C5 = true_,
          typename C6 = true_,
          typename C7 = true_>
struct seq_
{
    template <typename S>
    static inline bool match (S& state)
    {
        state.push_state();

        bool var = C0::match (state)
            && C1::match (state)
            && C2::match (state)
            && C3::match (state)
            && C4::match (state)
            && C5::match (state)
            && C6::match (state)
            && C7::match (state);
        var ? state.commit() : state.rollback();

        return var;
    }
};

// Element decission: a|b
template <typename C0,
          typename C1,
          typename C2 = false_,
          typename C3 = false_,
          typename C4 = false_,
          typename C5 = false_,
          typename C6 = false_,
          typename C7 = false_>
struct or_
{
    template <typename S>
    static inline bool match (S& state)
    {
        state.push_state();

        bool var = C0::match (state)
            || C1::match (state)
            || C2::match (state)
            || C3::match (state)
            || C4::match (state)
            || C5::match (state)
            || C6::match (state)
            || C7::match (state);

        var ? state.commit() : state.rollback();

        return var;
    }
};

// One or more repetitions: a+
template <typename C0>
struct plus_
{
    template <typename S>
    static inline bool match (S& state)
    {
        if (!C0::match (state))
            return false;
        // Note: yes, I unroll this loop intentionally
        while (C0::match (state)
               && C0::match (state)
               && C0::match (state)
               && C0::match (state)
               && C0::match (state)
               && C0::match (state)
               && C0::match (state)
               && C0::match (state)
               && C0::match (state)
               && C0::match (state))
            ;
        return true;
    }
};

// Zero or more repetitions: a*
template <typename C0>
struct star_
{
    template <typename S>
    static inline bool match (S& state)
    {
        while (C0::match (state)
               && C0::match (state)
               && C0::match (state)
               && C0::match (state)
               && C0::match (state)
               && C0::match (state)
               && C0::match (state)
               && C0::match (state)
               && C0::match (state)
               && C0::match (state))
            ;
        return true;
    }
};

// Optional (special star_ case): a?
template <typename C0>
struct opt_
{
    template <typename S>
    static inline bool match (S& state)
    {
        C0::match (state);
        return true;
    }
};

template < char c >
struct until_ : seq_ < star_ < notchar_ < c > >, char_ < c > >
{
};

// apply C0 until C1
template <typename C0,
          typename C1>
struct apply_until_ 
{
    template <typename S>
    static inline bool match (S& state)
    {
        state.push_state();

        bool var = false;

        while (!(var = C1::match (state)))
            if (!C0::match (state))
                break;

        var ? state.commit() : state.rollback();

        return var;
    }
};

struct new_line 
{
    template <typename S>
    static inline bool match(S& state)
    {
        bool res = state.match_at_pos_advance ('\n');
        if (res) state.new_line();
        return res;
    }
};

typedef notchar_ < '\n' > not_new_line;
typedef apply_until_ < not_new_line, new_line > until_new_line;
// anychar counting lines
typedef or_< new_line, not_new_line> anychar_lc;

} // parser

#endif // PARSER_HPP

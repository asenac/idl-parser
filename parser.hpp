#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <deque>
//#include <exception> // Exceptions
//#include <stdexcept>

namespace parser
{

////////////////////////////////////////////////////////////////////////
// parser state
template <typename SemanticState>
struct State
{
    // For reference, the SemanticState itself.
    typedef SemanticState SemType;

    // Position type
    typedef const char * PositionType;

    // buffer
    const char* buf_;
    // actual pos
    const char* pos_;
    // buf_fer length
    size_t len_;

    // The inner semantic state.
    SemanticState& ss_;

    // State stack, for backtracking
    std::deque< const char* > pos_stack_;

    PositionType max_pos_;

    // ctor
    State (SemanticState& ss, const char* b, size_t l)
        : buf_ (b), pos_ (b),  len_(l), ss_ (ss), max_pos_(NULL)
    {
    }

    SemanticState&
    semantic_state()
    {
        return ss_;
    }

    inline bool
    at_end() const
    {
        return static_cast<size_t>(pos_ - buf_) == len_;
    }

    inline bool
    match_at_pos_advance (char c)
    {
        if (!at_end() && (*pos_ == c))
        {
            ++pos_;
            return true;
        }
        return false;
    }

    inline bool
    match_at_pos (char c) const
    {
        return !at_end() && (*pos_ == c);
    }

    inline char
    char_at_pos() const
    {
        return *pos_;
    }

    inline const char* pos() const
    {
        return pos_;
    }

    inline void
    advance()
    {
        if (!at_end())
            ++pos_;

        // TODO: throw at_end
    }

    inline void
    skip(size_t how_many)
    {
        if (static_cast<size_t>(pos_ - buf_) + how_many <= len_)
            pos_ += how_many;

        // TODO: throw at_end
    }

    // Common interface
    inline void
    push_state()
    {
        pos_stack_.push_front (pos_);
    }

    inline void
    check_max()
    {
        if (max_pos_ < pos_)
            max_pos_ = pos_;
    }

    inline void
    rollback()
    {
        check_max();
        pos_ = pos_stack_.front();
        pos_stack_.pop_front();
    }

    inline void
    commit()
    {
        check_max();
        pos_stack_.pop_front();
    }

    inline std::string
    to_string(const char * p, std::size_t size) const
    {
        return std::string(p, size);
    }

    template < typename Stream >
    void get_error(Stream& ss)
    {
        if (max_pos_)
        {
            PositionType init =  max_pos_;
            PositionType end =  max_pos_;

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

            // error line
            const std::size_t size = end - init;
            ss << to_string(init, size) << std::endl;

            // marker
            const std::size_t diff = max_pos_ - init;
            for (std::size_t i = 0; i < diff; i++) 
                ss << ' ';
            ss << '^' << std::endl;
        }
    }
};

////////////////////////////////////////////////////////////////////////
// parser state
template <typename SemanticState>
struct IStreamState
{
    // For reference, the SemanticState itself.
    typedef SemanticState SemType;

    // Position type
    typedef std::streampos PositionType;

    // stream
    std::istream& in_;

    // The inner semantic state.
    SemanticState& ss_;

    // State stack, for backtracking
    std::deque< std::streampos > pos_stack_;

    std::streampos max_pos_;

    // ctor
    IStreamState (SemanticState& ss, std::istream& in)
        : in_ (in), ss_ (ss), max_pos_(0)
    {
    }

    SemanticState&
    semantic_state()
    {
        return ss_;
    }

    inline bool
    at_end() const
    {
        return !in_.good();
    }

    inline bool
    match_at_pos_advance (char c)
    {
        if (!at_end())
        {
            if (in_.get() == c)
            {
                return true;
            }
            else
            {
                in_.unget();
            }
        }
        return false;
    }

    inline bool
    match_at_pos (char c) const
    {
        if (at_end())
            return false;

        char r = in_.peek();
        return (r == c);
    }

    inline char
    char_at_pos() const
    {
        return in_.peek();
    }

    inline PositionType pos() const
    {
        return in_.tellg();
    }

    inline void
    advance()
    {
        if (!at_end())
            in_.get();

        // TODO: throw at_end
    }

    inline void
    skip(size_t how_many)
    {
        in_.ignore(how_many);

        // TODO: throw at_end
    }

    // Common interface
    inline void
    push_state()
    {
        pos_stack_.push_front (in_.tellg());
    }

    inline void
    check_max()
    {
        std::streampos cur = in_.tellg();
        if (max_pos_ < cur)
            max_pos_ = cur;
    }

    inline void
    rollback()
    {
        check_max();
        in_.seekg(pos_stack_.front());
        pos_stack_.pop_front();
    }

    inline void
    commit()
    {
        check_max();
        pos_stack_.pop_front();
    }

    inline std::string
    to_string(std::streampos p, std::size_t size)
    {
        const std::streampos old = in_.tellg();

        char buffer[size];
        in_.seekg(p);
        in_.read(buffer, size);
        in_.seekg(old);

        return std::string(buffer, size);
    }

    template < typename Stream >
    void get_error(Stream& ss)
    {
        if (max_pos_ > -1)
        {
            std::streampos init =  max_pos_;

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
            in_.seekg(max_pos_);

            while (!at_end() && in_.peek() != '\n')
                in_.get();

            if (at_end())
            {
                in_.clear();
                in_.seekg(0, in_.end);
            }

            // error line
            const std::size_t size = in_.tellg() - init;
            ss << to_string(init, size) << std::endl;

            // marker
            const std::size_t diff = max_pos_ - init;
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

} // parser

#endif // PARSER_HPP

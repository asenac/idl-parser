#ifndef IDL_PARSER_HPP
#define IDL_PARSER_HPP

namespace idlmm 
{
class TranslationUnit;
typedef TranslationUnit * TranslationUnit_ptr;
} // namespace idlmm

namespace idl 
{

idlmm::TranslationUnit_ptr parse(const char * file);

} // namespace idl

#endif /* IDL_PARSER_HPP */

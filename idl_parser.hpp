#ifndef IDL_PARSER_HPP
#define IDL_PARSER_HPP

#include <string>
#include <istream>

namespace idlmm 
{
class TranslationUnit;
typedef TranslationUnit * TranslationUnit_ptr;
} // namespace idlmm

namespace idl 
{

idlmm::TranslationUnit_ptr parse(const char * file);
idlmm::TranslationUnit_ptr parse(std::istream& is);
idlmm::TranslationUnit_ptr parseString(const std::string& str);

} // namespace idl

#endif /* IDL_PARSER_HPP */

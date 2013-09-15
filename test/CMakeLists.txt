
add_executable(test_grammar test_grammar.cpp)
add_test(grammar test_grammar)
valgrind_test(grammar $<TARGET_FILE:test_grammar>)

target_link_libraries(test_grammar
    idl_parser
    idlmm
)

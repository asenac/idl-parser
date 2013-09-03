add_executable(test_grammar test_grammar.cpp)
add_test(grammar test_grammar)

target_link_libraries(test_grammar
    idl_parser
    emf4cpp-idlmm
    emf4cpp-ecore
    emf4cpp-ecorecpp
)

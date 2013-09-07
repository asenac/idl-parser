macro(valgrind_test TEST)
    add_test(NAME ${TEST}-valgrind 
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMAND valgrind --leak-check=full --error-exitcode=1 --log-file=test_grammar.valgrind.out ./${TEST} ${ARGN})
endmacro(valgrind_test)

add_executable(test_grammar test_grammar.cpp)
add_test(grammar test_grammar)
valgrind_test(test_grammar)

target_link_libraries(test_grammar
    idl_parser
    emf4cpp-idlmm
    emf4cpp-ecore
    emf4cpp-ecorecpp
)

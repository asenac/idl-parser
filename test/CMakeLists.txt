add_executable(test_read test_read.cpp)
target_link_libraries(test_read
    idl_parser
    idlmm
)

macro(valgrind_test TEST EXEC)
    add_test(NAME ${TEST}-valgrind 
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMAND valgrind --leak-check=full --error-exitcode=1 --log-file=${TEST}.valgrind.out ${EXEC} ${ARGN})
endmacro(valgrind_test)

foreach(idl scope.idl test.idl test3.idl)
    add_test(NAME read-${idl} 
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMAND test_read ${EXAMPLES_DIR}/${idl})
    valgrind_test(read-${idl} $<TARGET_FILE:test_read> ${EXAMPLES_DIR}/${idl})
endforeach(idl)

foreach(idl test2.idl error.idl error2.idl)
    add_test(NAME read-${idl} 
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMAND ${UTILS_DIR}/test_runner.py 1 $<TARGET_FILE:test_read> ${EXAMPLES_DIR}/${idl})
    valgrind_test(read-${idl} $<TARGET_FILE:test_read> ${EXAMPLES_DIR}/${idl})
endforeach(idl)

add_executable(test_grammar test_grammar.cpp)
add_test(grammar test_grammar)
valgrind_test(grammar $<TARGET_FILE:test_grammar>)

target_link_libraries(test_grammar
    idl_parser
    idlmm
)

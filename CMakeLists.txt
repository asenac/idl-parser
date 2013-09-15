cmake_minimum_required(VERSION 2.6)
project(idl_parser)

enable_testing()

set(CMAKE_CXX_FLAGS "-Wall -Werror -pedantic")

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/model
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_subdirectory(model)

add_library(idl_parser STATIC idl_parser.cpp)

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
        COMMAND test_read ${CMAKE_CURRENT_SOURCE_DIR}/examples/${idl})
    valgrind_test(read-${idl} $<TARGET_FILE:test_read> ${CMAKE_CURRENT_SOURCE_DIR}/examples/${idl})
endforeach(idl)

foreach(idl test2.idl error.idl error2.idl)
    add_test(NAME read-${idl} 
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/utils/test_runner.py 1 $<TARGET_FILE:test_read> ${CMAKE_CURRENT_SOURCE_DIR}/examples/${idl})
    valgrind_test(read-${idl} $<TARGET_FILE:test_read> ${CMAKE_CURRENT_SOURCE_DIR}/examples/${idl})
endforeach(idl)

add_subdirectory(test)


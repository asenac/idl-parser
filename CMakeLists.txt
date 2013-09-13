cmake_minimum_required(VERSION 2.6)
project(idl_parser)

enable_testing()

set(EMF4CPP_DIR $ENV{HOME}/local/emf4cpp)

set(CMAKE_CXX_FLAGS "-Wall -Werror -pedantic")

include_directories(
    ${EMF4CPP_DIR}/include/emf4cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/model
    ${CMAKE_CURRENT_SOURCE_DIR}
)

link_directories(
    ${EMF4CPP_DIR}/lib
)

add_subdirectory(model)

add_library(idl_parser STATIC idl_parser.cpp)

add_executable(test_idl test_idl.cpp)
target_link_libraries(test_idl
    idl_parser
    emf4cpp-idlmm
    emf4cpp-ecore
    emf4cpp-ecorecpp
)

add_executable(test_read test_read.cpp)
target_link_libraries(test_read
    idl_parser
    emf4cpp-idlmm
    emf4cpp-ecore
    emf4cpp-ecorecpp
)

macro(valgrind_test TEST EXEC)
    add_test(NAME ${TEST}-valgrind 
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMAND valgrind --leak-check=full --error-exitcode=1 --log-file=${TEST}.valgrind.out ./${EXEC} ${ARGN})
endmacro(valgrind_test)

foreach(idl scope.idl test.idl test2.idl test3.idl)
    add_test(NAME read-${idl} 
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMAND test_read ${CMAKE_CURRENT_SOURCE_DIR}/examples/${idl})
    valgrind_test(read-${idl} test_read ${CMAKE_CURRENT_SOURCE_DIR}/examples/${idl})
endforeach(idl)

add_subdirectory(test)


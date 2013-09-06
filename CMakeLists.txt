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

add_subdirectory(test)


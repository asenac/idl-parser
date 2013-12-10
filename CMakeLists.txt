cmake_minimum_required(VERSION 2.6)
project(idl_parser)

enable_testing()

set(CMAKE_CXX_FLAGS "-Wall -Werror -pedantic")

set(EXAMPLES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/examples)
set(UTILS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/utils)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

add_subdirectory(src)
add_subdirectory(test EXCLUDE_FROM_ALL)


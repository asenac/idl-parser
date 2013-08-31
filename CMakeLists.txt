cmake_minimum_required(VERSION 2.6)
project(idl_parser)

include_directories(
    $ENV{HOME}/local/emf4cpp/include/emf4cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/model
)

link_directories(
    $ENV{HOME}/local/emf4cpp/lib
)

add_subdirectory(model)

add_executable(idl_parser test_idl.cpp idl_parser.cpp)

target_link_libraries(idl_parser
    emf4cpp-idlmm
    emf4cpp-ecore
    emf4cpp-ecorecpp
)


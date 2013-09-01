cmake_minimum_required(VERSION 2.6)
project(idl_parser)

set(EMF4CPP_DIR $ENV{HOME}/local/emf4cpp)

include_directories(
    ${EMF4CPP_DIR}/include/emf4cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/model
)

link_directories(
    ${EMF4CPP_DIR}/lib
)

add_subdirectory(model)

add_executable(idl_parser test_idl.cpp idl_parser.cpp)

target_link_libraries(idl_parser
    emf4cpp-idlmm
    emf4cpp-ecore
    emf4cpp-ecorecpp
)


cmake_minimum_required(VERSION 3.8)

project(flipwiz)

set(CMAKE_CXX_STANDARD 17)

# set binary directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# source code
add_subdirectory(src)

# Resources
file(COPY ${CMAKE_SOURCE_DIR}/res DESTINATION ${CMAKE_BINARY_DIR})

# tests
#option(BUILD_TESTS "Build unit tests" ON)
#if (BUILD_TESTS)
#    add_subdirectory(tests)
#endif()

# docs
#option(BUILD_DOCS "Build documentation" OFF)
#if (BUILD_DOCS)
#    add_subdirectory(docs)
#endif()

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/application.manifest
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
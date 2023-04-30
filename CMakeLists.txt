cmake_minimum_required(VERSION 3.8)

project(flipwiz)

set(CMAKE_CXX_STANDARD 17)

# source code of application
add_subdirectory(src)

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
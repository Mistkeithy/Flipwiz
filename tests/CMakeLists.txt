#add_executable(tests
#    MyClassTest.cpp
#)
#
#target_include_directories(tests PRIVATE
#    ${CMAKE_CURRENT_SOURCE_DIR}
#)
#
#target_link_libraries(tests PRIVATE
#    mylib
#)
#
## add Catch
#add_library(Catch INTERFACE)
#target_include_directories(Catch INTERFACE
#    ${CMAKE_CURRENT_SOURCE_DIR}
#)
#target_sources(Catch INTERFACE
#    catch.hpp
#)
#
#target_link_libraries(tests PRIVATE
#    Catch
#)
#
## add tests
#include(CTest)
#add_test(NAME MyTests COMMAND tests)
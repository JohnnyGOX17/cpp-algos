cmake_minimum_required(VERSION 3.11)
project(CppAlgos 
  LANGUAGES CXX
  VERSION 0.1
  DESCRIPTION "C++ algorithms and data structures"
)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  CppAlgos
  ./leetcode/hello_test.cpp
)
target_link_libraries(
  CppAlgos
  GTest::gtest_main
)

if ( CMAKE_CXX_COMPILER_ID MATCHES "Clang|AppleClang|GNU" )
  target_compile_options(CppAlgos PRIVATE -Wall -Wextra -Wunreachable-code -Wpedantic -Werror)
endif()
if ( CMAKE_CXX_COMPILER_ID MATCHES "Clang" )
  target_compile_options(CppAlgos PRIVATE -Wweak-vtables -Wexit-time-destructors -Wmissing-noreturn)
endif()
if ( CMAKE_CXX_COMPILER_ID MATCHES "MSVC" )
  target_compile_options(CppAlgos PRIVATE /W4 /w44265 /w44061 /w44062)
endif()

include(GoogleTest)
gtest_discover_tests(CppAlgos)

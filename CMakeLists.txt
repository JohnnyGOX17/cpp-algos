cmake_minimum_required(VERSION 3.11)
project(CppAlgos VERSION 0.1)

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
  hello_test.cpp
)
target_link_libraries(
  CppAlgos
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(CppAlgos)

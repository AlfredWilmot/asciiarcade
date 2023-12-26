cmake_minimum_required(VERSION 3.14)
project(asciiarcade)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Variables
set(SRC_DIR src)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)



# References:
# > https://google.github.io/googletest/quickstart-cmake.html
# > https://cmake.org/cmake/help/latest/guide/tutorial/index.html
# > https://ncona.com/2019/03/building-a-cpp-project-with-cmake/

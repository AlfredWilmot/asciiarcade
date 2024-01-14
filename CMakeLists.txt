cmake_minimum_required(VERSION 3.14)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Needed by clangd LSP when using "FetchContent"
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

project(
    asciiarcade
    VERSION 1.0
    LANGUAGES CXX
)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.12.1
)
FetchContent_MakeAvailable(googletest)
enable_testing()

add_executable(
    "${PROJECT_NAME}"
    src/SceneView.cpp
    test/SceneViewTest.cpp
)

target_link_libraries(
    "${PROJECT_NAME}"
    GTest::gtest_main
    GTest::gmock_main
)

include(GoogleTest)
gtest_discover_tests("${PROJECT_NAME}")

include_directories(include)

##############
# References #
##############

## gtest stuff ##
# > https://youtu.be/zfgFphZ63UY?si=X0bmbHkB00xbLqxH
# > https://google.github.io/googletest/quickstart-cmake.html

## CMake stuff ##
# > https://cmake.org/cmake/help/v3.14/module/FetchContent.html
# > https://cmake.org/cmake/help/latest/guide/tutorial/index.html
# > https://ncona.com/2019/03/building-a-cpp-project-with-cmake/
# > https://cliutils.gitlab.io/modern-cmake/chapters/basics/example.html

## clangd stuff ##
# > https://stackoverflow.com/questions/73356618/how-should-i-configure-clangd-to-make-it-scan-the-library-i-download-with-cmake

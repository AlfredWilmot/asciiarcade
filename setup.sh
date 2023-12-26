#!/bin/bash

PROJECT_DIR="${PWD}"

gtest() {
    BUILD_DIR="${PROJECT_DIR}/build"
    cmake -S . -B "${BUILD_DIR}"
    cmake --build "${BUILD_DIR}"
    cd "${BUILD_DIR}" && ctest
    cd "${PROJECT_DIR}"
}

setup_cpputest_test_runner() {
    TEST_RUNNER_MODULE='cpputest/'
    if [ ! -d "$TEST_RUNNER_MODULE"  ]; then
        git submodule add https://github.com/cpputest/cpputest.git
    fi
    cd "$TEST_RUNNER_MODULE"
    autoreconf . -i
    ./configure
    make tdd
    export CPPUTEST_HOME=$(pwd)
    cd -

    # References:
    # > http://cpputest.github.io/
}

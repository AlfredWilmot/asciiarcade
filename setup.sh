#!/bin/bash

install_gtest() {
  cd tests/
  git submodule add https://github.com/google/googletest.git -b release-1.12.1
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

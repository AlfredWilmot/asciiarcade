#!/bin/bash

setup_test_runner() {
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

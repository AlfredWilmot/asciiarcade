#include "CppUTest/CommandLineTestRunner.h"

int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}

/*
 References:
 > https://github.com/jwgrenning/cpputest-starter-project/blob/master/tests/AllTests.cpp
*/

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../tests/doctest/doctest.h"
#include "dummy.cpp"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <size.h>
#include "vector.h"
#include "matrix.h"
// This is all that is needed to compile a test-runner executable.
// More tests can be added here, or in a new tests/*.cpp file.
/*TEST_CASE("mnozenie wektorow") {
    double argumentsV1[] = {2.0, 3.0, 1.0};
    double argumentsV2[] = {2.0, 4.0 , 1.0};
    double argumentsV3[] = {4.0, 12.0 ,1.0};
    Vector<SIZE> x=Vector<SIZE>(argumentsV1);
   Vector<SIZE> t=Vector<SIZE>(argumentsV2);
   Vector<SIZE> y=Vector<SIZE>(argumentsV3);
   Vector<SIZE> a=x*t;
    CHECK(a == y);
}*/
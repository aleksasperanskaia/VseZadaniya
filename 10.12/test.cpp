#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "calc.h"
TEST_SUITE("easy") {
    TEST_CASE("Testing evaluate") {
        CHECK(a(1,1)==2);
        CHECK(add(-1,1)==0);
        CHECK(add(-1,-1)==-2);
    }
        REQUIRE(22.0/7 ==doctest::Approx(3.141).epsilon(0.01));
    }
}

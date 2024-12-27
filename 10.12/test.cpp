#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Basic operations") {
    CHECK(evaluate("1+1") == 2);
    CHECK(evaluate("5-2") == 3);
    CHECK(evaluate("4*3") == 12);
    CHECK(evaluate("8/4") == 2);
}

TEST_CASE("Exponentiation") {
    CHECK(evaluate("2^3") == 8);
    CHECK(evaluate("10^0") == 1);
}

TEST_CASE("Mixed operations") {
    CHECK(evaluate("2+3*4") == 14); // Multiplication has higher precedence
    CHECK(evaluate("10-3/3") == 9); // Division has higher precedence
}

TEST_CASE("Negative numbers") {
    CHECK(evaluate("-5+10") == 5);
    CHECK(evaluate("-2*-3") == 6);
    CHECK(evaluate("-8/2") == -4);
}

TEST_CASE("Edge cases") {
    CHECK_THROWS_AS(evaluate(""), std::runtime_error);
    CHECK_THROWS_WITH(evaluate(""), "empty input");

    CHECK_THROWS_AS(evaluate("5/0"), std::runtime_error);
    CHECK_THROWS_WITH(evaluate("5/0"), "division by zero is impossible");

    CHECK_THROWS_AS(evaluate("2++2"), std::runtime_error);
    CHECK_THROWS_WITH(evaluate("2++2"), "Incorrect expression");

    CHECK_THROWS_AS(evaluate("2--2"), std::runtime_error);
    CHECK_THROWS_WITH(evaluate("2--2"), "Incorrect expression");

    CHECK_THROWS_AS(evaluate("2..3+1"), std::runtime_error);
    CHECK_THROWS_WITH(evaluate("2..3+1"), "dot at the end");

    CHECK_THROWS_AS(evaluate("3."), std::runtime_error);
    CHECK_THROWS_WITH(evaluate("3."), "Некорректное число: точка в конце");
}

TEST_CASE("Complex expressions") {
    CHECK(evaluate("3+5*2-8/4") == 10); // Operator precedence
    CHECK(evaluate("2^3+1") == 9);
}

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "calc.h"

TEST_CASE("Тест compute") {

    CHECK(compute(2, 3, '+') == 5);
    CHECK(compute(5, 2, '-') == 3);
    CHECK(compute(3, 4, '*') == 12);
    CHECK(compute(8, 2, '/') == 4);


    CHECK_THROWS_AS(compute(8, 0, '/'), std::runtime_error);


    CHECK(compute(2, 3, '^') == 8);


    CHECK_THROWS_AS(compute(2, 3, '&'), std::runtime_error);
}

TEST_CASE("Тест parseTerm") {
    std::istringstream ss;

    ss.str("5");
    double result = parseTerm(ss);
    CHECK(result == 5);

    ss.str("3.5");
    result = parseTerm(ss);
    CHECK(result == 3.5);


    ss.str("(2+3)");
    result = parseTerm(ss);
    CHECK(result == 5);


    ss.str("2 * 3");
    result = parseTerm(ss);
    CHECK(result == 6);


    ss.str("-3 * 2");
    result = parseTerm(ss);
    CHECK(result == -6);
}

TEST_CASE("Тест evaluate") {

    CHECK_THROWS_AS(evaluate("2.2.2 * 3"), std::runtime_error);
    CHECK_THROWS_AS(evaluate("7."), std::runtime_error);

    CHECK_THROWS_AS(evaluate("2 / 0"), std::runtime_error);


    CHECK_THROWS_AS(evaluate(""), std::runtime_error);
}

TEST_CASE("Тест обработки ошибок") {

    CHECK_THROWS_AS(evaluate("5 + + 3"), std::runtime_error);
    CHECK_THROWS_AS(evaluate("5 + * 3"), std::runtime_error);
    CHECK_THROWS_AS(evaluate("(2 + 3"), std::runtime_error);
    CHECK_THROWS_AS(evaluate("3 + (2 + 4"), std::runtime_error);

    CHECK_THROWS_AS(evaluate("3 + + 4"), std::runtime_error);

}
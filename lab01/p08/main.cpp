#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"

#include <vector>
#include <sstream>

#include "Rational.hpp"

using namespace std;

TEST_CASE("Default constructor")
{
    const Rational<int> x;

    REQUIRE(x.num() == 0);
    REQUIRE(x.den() == 1);

    vector<Rational<long long>> v(10);

    for (auto r : v)
    {
        REQUIRE(r.num() == 0);
        REQUIRE(r.den() == 1);
    }

    ostringstream sout;
    sout << x;

    REQUIRE(sout.str() == "0/1");
}

TEST_CASE("Constructor Rational(num, den")
{
    ostringstream sout;

    SUBCASE("denominator is equal to zero")
    {
        REQUIRE_THROWS_AS(Rational<int>(5, 0), runtime_error); 
    }

    SUBCASE("reducing 20/10")
    {
        Rational<int> x(20, 10);
        sout << x;

        REQUIRE(sout.str() == "2/1");
    }

    SUBCASE("reducing 10/25")
    {
        Rational<int> x(10, 25);
        sout << x;

        REQUIRE(sout.str() == "2/5");
    }

    SUBCASE("reducing 11/17")
    {
        Rational<int> x(11, 17);
        sout << x;

        REQUIRE(sout.str() == "11/17");
    }

    SUBCASE("reducing 28/-12")
    {
        Rational<int> x(28, -12);
        sout << x;

        REQUIRE(sout.str() == "-7/3");
    }

    SUBCASE("reducing 6/1")
    {
        Rational<int> x(6);
        sout << x;

        REQUIRE(sout.str() == "6/1");
    }
}

TEST_CASE("Addition")
{
    ostringstream sout;

    SUBCASE("1/2 + 2/3")
    {
        Rational<int> x(1, 2);
        Rational<int> y(2, 3);
        sout << x + y;

        REQUIRE(sout.str() == "7/6");
    }

    // SUBCASE("1/2 + 2")
    // {
    //     Rational<int> x(1, 2);
    //     Rational<int> y(2);
    //     Rational<int> r = x + 2;
    //     sout << r;

    //     REQUIRE(sout.str() == "3/2");
    // }
}

TEST_CASE("Substruction")
{
    // TODO
}

TEST_CASE("Multiplication")
{
    // TODO
}

TEST_CASE("Division")
{
    // TODO
}
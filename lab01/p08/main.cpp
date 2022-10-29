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
}
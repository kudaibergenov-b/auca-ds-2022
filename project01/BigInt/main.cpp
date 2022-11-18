#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"

#include <sstream>
#include <string>
#include <stdexcept>

#include "BigInt.hpp"

using namespace std;

TEST_CASE("Default constructor")
{
    BigInt x;
    ostringstream sout;
    sout << x;
    REQUIRE(sout.str() == "0");

    vector<BigInt> v(5);
    for (const auto &e : v)
    {
        ostringstream sout2;
        sout2 << e;
        REQUIRE(sout2.str() == "0");
    }
}

TEST_CASE("Constructor with a string")
{
    ostringstream sout;
    SUBCASE("positive number, test #1")
    {
        BigInt x("123456789123456789");
        sout << x;
        REQUIRE(sout.str() == "123456789123456789");
    }

    SUBCASE("positive number, test #2")
    {
        BigInt x("+123456789123456789");
        sout << x;
        REQUIRE(sout.str() == "123456789123456789");
    }

    SUBCASE("negative number")
    {
        BigInt x("-123");
        sout << x;
        REQUIRE(sout.str() == "-123");
    }

    SUBCASE("empty string")
    {
        REQUIRE_THROWS_AS(BigInt(""), runtime_error);
    }

    SUBCASE(" 123")
    {
        REQUIRE_THROWS_AS(BigInt(" 123"), runtime_error);
        REQUIRE_THROWS_WITH(BigInt(" 123"), "Incorrect format of BigInteger");
    }

    SUBCASE("123-123")
    {
        REQUIRE_THROWS_AS(BigInt("123-123"), runtime_error);
        REQUIRE_THROWS_WITH(BigInt("123-123"), "Incorrect format of BigInteger");
    }

    SUBCASE("hello")
    {
        REQUIRE_THROWS_AS(BigInt("hello"), runtime_error);
        REQUIRE_THROWS_WITH(BigInt("hello"), "Incorrect format of BigInteger");
    }

    // SUBCASE("0000213")
    // {
    //     BigInt x("0000213");
    //     sout << x;
    //     REQUIRE(sout.str() == "213");
    // }
}

TEST_CASE("Addition")
{
    ostringstream sout;

    SUBCASE("positive + positive, test #1")
    {
        BigInt x("193");
        BigInt y("59");
        sout << x + y;
        REQUIRE(sout.str() == "252");
    }

    SUBCASE("positive + positive, test #2")
    {
        BigInt x("999");
        BigInt y("1");
        sout << x + y;
        REQUIRE(sout.str() == "1000");
    }

    SUBCASE("positive + positive, test #3")
    {
        for (int x = 0; x <= 1000; ++x)
        {
            for (int y = 0; y <= 1000; ++y)
            {
                BigInt a(to_string(x));
                BigInt b(to_string(y));
                sout << a + b;
                REQUIRE(sout.str() == to_string(x + y));
                sout.str("");
            }
        }
    }
}


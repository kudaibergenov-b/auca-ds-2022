#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"

#include<vector>

using namespace std;

TEST_CASE("Default constructor")
{
    vector<int> v;

    REQUIRE(v.empty());
    REQUIRE(v.size() == 0);
}

TEST_CASE("Copy Constructor")
{
    vector<int> v = {1, 2, 3, 4, 5};

    //TODO
}

TEST_CASE("push back")
{
    vector<int> v;

    //TODO
}

TEST_CASE("back()")
{
    vector<int> v = {1, 2, 3};

    REQUIRE(v.back() == 3);

    v.back() = 100;

    REQUIRE(v.back() == 100);
}

TEST_CASE("front()")
{
    vector<int> v = {1, 2, 3};

    REQUIRE(v.front() == 1);

    v.front() = 100;

    REQUIRE(v.front() == 100);
}

TEST_CASE("[]")
{
    vector<int> v = {1, 2, 3};

    REQUIRE(v[0] == 1);

    v.assign(1, 100);

    REQUIRE(v[0] == 100);
}

TEST_CASE("assignment()")
{
    vector<int> v = {1, 2, 3};
    vector<int> c = {3, 4, 5};

    c = v;

    REQUIRE(c[0] == 1);

    //TODO

    v = vector<int>();

    REQUIRE(v.size() == 0);
}

TEST_CASE("at()")
{
    vector<int> v = {1, 2 ,3};

    REQUIRE(v.at(1) == 2);

    REQUIRE_THROWS_AS(v.at(5), out_of_range);
}
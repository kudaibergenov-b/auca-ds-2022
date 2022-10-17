#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"

#include<vector>

using namespace std;

template <typename C>
string containerToStr(const C &c)
{
    ostringstream sout;
    bool isFirst = true;
    sout << "{";
    for (const auto &e : c)
    {
        if (!isFirst)
        {
            sout << ", ";
        }
        sout << e;
        isFirst = false;
    }
    sout << "}";

    return sout.str();
}

TEST_CASE("default constructor")
{
    vector<int> v;

    REQUIRE(v.empty());
    REQUIRE(v.size() == 0);
}

TEST_CASE("constructor with size")
{
    vector<int> v(10);

    REQUIRE(v.size() == 10);

    for (auto i : v)
    {
        REQUIRE(v[i] == 0);
    }
}

TEST_CASE("constructor with size and initial value")
{
    vector<int> v(10, 1);

    REQUIRE(v.size() == 10);

    for (auto i : v)
    {
        REQUIRE(v[i] == 1);
    }
}

TEST_CASE("copy constructor")
{
    vector<int> v = {1, 2, 3, 4, 5};

    vector<int> v2 = v;

    REQUIRE(v2.size() == 5);
    REQUIRE(containerToStr(v2) == "{1, 2, 3, 4, 5}");

    v[0] = 1000;
    v2[4] = 42;

    REQUIRE(containerToStr(v) == "{1000, 2, 3, 4, 5}");
    REQUIRE(containerToStr(v2) == "{1, 2, 3, 4, 42}");
}

TEST_CASE("assignment operator")
{
    vector<int> v = {1, 2, 3};
    vector<int> c = {3, 4, 5};

    c = v;

    REQUIRE(c[0] == 1);

    v[2] = 34;
    c[0] = 100;

    REQUIRE(containerToStr(v) == "{1, 2, 34}");
    REQUIRE(containerToStr(c) == "{100, 2, 3}");

    v = vector<int>();

    REQUIRE(v.size() == 0);
}

TEST_CASE("move constructor")
{
    vector<int> v = {1, 2, 3};
    vector<int> v2 = move(v);

    REQUIRE(containerToStr(v) == "{}");
    REQUIRE(containerToStr(v2) == "{1, 2, 3}");
}

TEST_CASE("move assignment")
{
    vector<int> v = {1, 2, 3};
    vector<int> v2 = {4, 5, 6};

    v2 = move(v);

    REQUIRE(containerToStr(v) == "{}");
    REQUIRE(containerToStr(v2) == "{1, 2, 3}");
}

TEST_CASE("[]")
{
    vector<int> v = {1, 2, 3};

    REQUIRE(v[0] == 1);

    v.assign(1, 100);

    REQUIRE(v[0] == 100);
}

TEST_CASE("at()")
{
    vector<int> v = {1, 2 ,3};

    REQUIRE(v.at(1) == 2);

    REQUIRE_THROWS_AS(v.at(5), out_of_range);
}

TEST_CASE("push back")
{
    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    REQUIRE(v.size() == 5);
    REQUIRE(containerToStr(v) == "{1, 2, 3, 4, 5}");
    REQUIRE(v.capacity() == 8);
}

TEST_CASE("pop_back")
{
    vector<int> v = {1, 2, 3, 4};

    REQUIRE(containerToStr(v) == "{1, 2, 3, 4}");
    REQUIRE(v.size() == 4);

    v.pop_back();

    REQUIRE(containerToStr(v) == "{1, 2, 3}");
    REQUIRE(v.size() == 3);
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


#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"

#include<string>

using namespace std;

TEST_CASE("default constructor")
{
    string s;

    REQUIRE(s.length() == 0);
    REQUIRE(s == "");
}

TEST_CASE("constructor with size and initial value")
{
    string s(5, 'a');

    REQUIRE(s.length() == 5);
    REQUIRE(s == "aaaaa");
}

TEST_CASE("copy constructor")
{
    string s1("hello");
    string s2(s1);

    REQUIRE(s1 == s2);

    s1 = "hi";
    s2 = "Hello";

    REQUIRE(s1 == "hi");
    REQUIRE(s2 == "Hello");
}

TEST_CASE("assignment operator")
{
    string s("abc");
    
    REQUIRE(s == "abc");

    s = "abcde";

    REQUIRE(s == "abcde");
}

TEST_CASE("move constructor")
{
    string s1("full");
    string s2 = move(s1);

    REQUIRE(s1 == "");
    REQUIRE(s2 == "full");
}

TEST_CASE("move assignment")
{
    string s1("full");
    string s2;

    s2 = move(s1);

    REQUIRE(s1 == "");
    REQUIRE(s2 == "full");
}

TEST_CASE("subscript operator")
{
    string s("testcase");

    REQUIRE(s[0] == 't');
}

TEST_CASE("at(index)")
{
    string s("12345");

    REQUIRE(s.at(4) == '5');
    REQUIRE_THROWS_AS(s.at(5), out_of_range);
}

TEST_CASE("push_back")
{
    string s;

    s.push_back('w');
    s.push_back('o');
    s.push_back('r');
    s.push_back('d');

    REQUIRE(s.length() == 4);
    REQUIRE(s == "word");
}

TEST_CASE("pop_back")
{
    string s("bee");

    REQUIRE(s.length() == 3);
    REQUIRE(s == "bee");

    s.pop_back();

    REQUIRE(s.length() == 2);
    REQUIRE(s == "be");
}

TEST_CASE("+, += operators")
{
    string s1("hello");
    string s2("world");

    string s3 = s1 + s2;

    REQUIRE(s3 == "helloworld");
}

TEST_CASE("comparison operators, method compare")
{
    string s1("abc");
    string s2("12345");

    bool a = s1 == s2;
    bool b = s1 != s2;
    bool c = s1.length() < s2.length();
    bool d = s1.length() >= s2.length();;

    REQUIRE(a == false);
    REQUIRE(b == true);
    REQUIRE(c == true);
    REQUIRE(d == false);
    REQUIRE(s1.compare(s2) != 0);
}

TEST_CASE("for (auto &c : str)")
{
    // TODO
}

TEST_CASE("front()")
{
    // TODO
}

TEST_CASE("back()")
{
    // TODO
}

TEST_CASE("substr(index, length), find(char ch)")
{
    // TODO
}

TEST_CASE("iterators, operators")
{
    // TODO
}


TEST_CASE("insert(index, length, char)")
{
    // TODO
}

TEST_CASE("erase(index, length)")
{
    // TODO
}

TEST_CASE("constructor string(beg, end)")
{
    // TODO
}

TEST_CASE("reverse algorithm")
{
    // TODO
}

TEST_CASE("sort algorithm")
{
    // TODO
}

TEST_CASE("binary_search")
{
    // TODO
}

TEST_CASE("min_element")
{
    // TODO
}

TEST_CASE("max_element")
{
    // TODO
}
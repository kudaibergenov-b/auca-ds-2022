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
    string s1("CASUAL");
    string s2;

    for (auto c : s1)
    {
        s2 += c + 32;
    }

    REQUIRE(s2 == "casual");
}

TEST_CASE("front()")
{
    string s("abcde");

    REQUIRE(s.front() == 'a');

    s.front() = 'A';

    REQUIRE(s.front() == 'A');
}

TEST_CASE("back()")
{
    string s("abcde");

    REQUIRE(s.back() == 'e');

    s.back() = 'E';

    REQUIRE(s.back() == 'E');
}

TEST_CASE("substr(index, length), find(char ch)")
{
    string str("Love and peace");
    string sbstr = str.substr(0, 4);

    REQUIRE(sbstr == "Love");
    REQUIRE(sbstr.find('L') == 0);
}

TEST_CASE("iterators")
{
    string str("TOMATO");

    SUBCASE("* dereference")
    {
        auto it = str.begin();
        REQUIRE(*it == 'T');
        *it = 't';
        REQUIRE(*(str.begin()) == 't');
    }

    SUBCASE("+")
    {
        auto it = str.begin();
        REQUIRE(*it == 'T');
        REQUIRE(*(it + 2) == 'M');
        it += 3;
        REQUIRE(*it == 'A');
    }

    SUBCASE("it1 - it2")
    {
        auto it1 = str.begin();
        auto it2 =  it1 + 2;
        REQUIRE(it2 - it1 == 2);
        auto it3 = str.begin() + 1;
        int index = it3 - str.begin();
        REQUIRE(str.at(index) == 'O');
    }
}


TEST_CASE("insert(index, length, char)")
{
    string str("board");

    str.insert(str.begin(), 1, 'a');

    REQUIRE(str == "aboard");
}

TEST_CASE("erase(index, length)")
{
    string str("watermelon");

    str.erase(0, 5);

    REQUIRE(str == "melon");
    REQUIRE(str.length() == 5);
}

TEST_CASE("constructor string(beg, end)")
{
    string s1("cocacola");
    string s2(s1.begin() + 4, s1.end());

    REQUIRE(s2 == "cola");
    REQUIRE(s2.length() == 4);
}

TEST_CASE("reverse algorithm")
{
    string str("12345");

    reverse(str.begin(), str.end());

    REQUIRE(str == "54321");
}

TEST_CASE("sort algorithm")
{
    string str("cebda");

    sort(str.begin(), str.end());

    REQUIRE(str == "abcde");
}

TEST_CASE("binary_search")
{
    string str("aaaa");

    REQUIRE(binary_search(str.begin(), str.end(), 'a'));
}

TEST_CASE("min_element")
{
    // TODO
}

TEST_CASE("max_element")
{
    // TODO
}
#include <iostream>
#include <vector>
#include <string>
#include <readMemory.hpp>

using namespace std;

vector<string> readMemory(vector<string> &memory)
{
    int i = 0;

    while (getline(cin, memory[i]) && !memory[i].empty())
    {
        i++;
    }
}
#include <iostream>
#include <vector>
#include <string>
#include <fillMemory.hpp>

using namespace std;

vector<string> fillMemory(vector<string> &memory)
{
    for (int i = 0; i < 1000; i++)
    {
        memory[i] = "000";
    }

    return memory;
}
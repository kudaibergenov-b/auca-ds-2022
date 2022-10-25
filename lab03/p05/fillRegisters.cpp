#include <iostream>
#include <vector>
#include <string>
#include <fillRegisters.hpp>

using namespace std;

vector<string> fillRegisters(vector<string> &registers)
{
    for (int i = 0; i < 10; i++)
    {
        registers[i] = "000";
    }

    return registers;
}
#include <bits/stdc++.h>
#include <fillRegisters.hpp>
#include <fillMemory.hpp>
#include <readMemory.hpp>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            cout << endl;
        }
        vector<string> registers;
        vector<string> memory;
        int instructions = 0;

        fillRegisters(registers);
        fillMemory(memory);
        readMemory(memory);
    }
}
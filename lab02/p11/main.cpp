#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int solve(char *name)
{
    int sum = 0;
    int t;

    while (*name)
    {
        if (*name >= 'a' && *name <= 'z')
        {
            sum += *name - 96;
        }
        else if (*name >= 'A' && *name <= 'Z')
        {
            sum += *name - 64;
        }
        ++name;
    }

    while (sum >= 10)
    {
        t = 0;

        while (sum)
        {
            t += sum % 10;
            sum /= 10;
        }

        sum = t;
    }

    return sum;
}

int main()
{
    iostream::sync_with_stdio(false);

    int a, b;
    char n1[30], n2[30];

    while (cin >> n1 >> n2)
    {
        a = solve(n1);
        b = solve(n2);

        setprecision(2);
        cout << (a < b ? a * 100 / b : b * 100 / a) << "\n";
    }
}
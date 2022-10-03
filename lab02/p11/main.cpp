#include <bits/stdc++.h>
#include <cstdio>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int solve(char *name)
{
    int sum(0), t;

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

    char n1[25], n2[25];
    int a, b;
    
    while (cin >> n1 >> n2)
    {
        a = solve(n1);
        b = solve(n2);

        if (a < b) {
            printf("%.2f %%\n", a * 100.0 / b);
        } else {
            printf("%.2f %%\n", b * 100.0 / a);
        }
    }
}
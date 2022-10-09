#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int solve(string s)
{
    int sum = 0;

    for (int i = 0; i < sz(s); i++)
    {
        if (isalpha(s[i]))
        {
            if (isupper(s[i]))
            {
                sum += (tolower(s[i]) - 96);
            }
            else
            {
                sum += (s[i] - 96);
            }
        }   
  }

    while (sum > 9)
    {
        int t = 0;

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
    
    for (string s1, s2; getline(cin, s1), getline(cin, s2);)
    {
        a = solve(s1);
        b = solve(s2);

        if (a < b) {
            printf("%.2f %%\n", a * 100.0 / b);
        } else {
            printf("%.2f %%\n", b * 100.0 / a);
        }
    }
}
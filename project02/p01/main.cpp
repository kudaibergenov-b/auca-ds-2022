#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;
int m;

int main()
{
    iostream::sync_with_stdio(false);

    int n;
    vector<int> v;

    while (cin >> n >> m, cout << n << " " << m << "\n", n)
    {
        for (int i = 0; i < n; ++i)
        {
            int a;
            cin >> a;
            v.push_back(a);
        }

        sort(begin(v), end(v),
              [](const int &x, const int &y)
              { if (x % m != y % m)
                {
                    return x % m < y % m;
                }
                else
                {
                    if (x % 2 != 0 && y % 2 != 0)
                    {
                        return x > y;
                    }
                    else if (x % 2 != 0 && y % 2 == 0)
                    {
                        return true;
                    }
                    else if (x % 2 == 0 && y % 2 != 0)
                    {
                        return false;
                    }
                    else
                    {
                        return x < y;
                    }
                }});

        for (int i = 0; i < n; ++i)
        {
            cout << v[i] << "\n";
        }
    }
}
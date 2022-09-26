#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int t, n, x;
    cin >> t;

    while (t--)
    {
        cin >> n;
        int max = 0;
        int min = 99;

        while (n--)
        {
            cin >> x;
            if (x < min)
            {
                min = x;
            }
            if (x > max)
            {
                max = x;
            }
        }
        int res = (max - min) * 2;

        cout << res << "\n";
    }
}
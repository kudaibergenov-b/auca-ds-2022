#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int t, a, b, c;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> a >> b >> c;
        cout << "Case " << i << ": ";
        if ((a > b && a < c) || (a > c && a < b))
        {
            cout << a << "\n";
        }
        else if ((b > a && b < c) || (b > c && b < a))
        {
            cout << b << "\n";
        }
        else
        {
            cout << c << "\n";
        }
    }
}
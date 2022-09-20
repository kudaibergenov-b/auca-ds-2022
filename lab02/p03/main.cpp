#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int n, x, y;
    cin >> n;

    while (n--)
    {
        cin >> x >> y;
        cout << (x / 3) * (y / 3) << "\n";
    }
}
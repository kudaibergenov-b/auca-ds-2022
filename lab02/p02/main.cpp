#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int64_t n;
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n;
        cout << ((int)sqrt(8 * n + 1) - 1) / 2 << "\n";
    }
}
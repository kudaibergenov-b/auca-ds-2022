#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    for (int a, b; cin >> a >> b;)
    {
        if (a == -1 && b == -1)
        {
            break;
        }

        if (a < b)
        {
            swap(a, b);
        }

        int res = min(a - b, 100 - a + b);

        cout << res << "\n";
    }
}
#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int t, n, s;
    cin >> t;

    while (t--) {
        cin >> n;
        s=(((((((n * 567) / 9) + 7492) *235) / 47) - 498) / 10) % 10;
        cout << abs(s) << "\n";
    }
}
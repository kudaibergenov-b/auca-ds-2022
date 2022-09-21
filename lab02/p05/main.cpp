#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int t = 1;
    int n, r;

    while (cin >> r >> n, n) {
        --r;
        cout << "Case " << t++ << ": ";
        if (r / n > 26) {
            cout << "impossible\n";
         } else {
            cout << r / n << "\n";
        }
    }
}
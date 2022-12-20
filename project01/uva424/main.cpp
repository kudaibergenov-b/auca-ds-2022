#include <bits/stdc++.h>

#include "../BigInt/BigInt.hpp"

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    
    BigInt sum = 0;
    for (BigInt x; cin >> x;)
    {
        if (x == 0)
        {
            break;
        }

        sum += x;
    }

    cout << sum << "\n";
}
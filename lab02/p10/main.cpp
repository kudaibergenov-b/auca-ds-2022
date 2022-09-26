#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int t, n, h, nHigh, nLow, temp;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        cin >> n >> temp;
        nHigh = 0;
        nLow = 0;
        for (int j = 0; j < n - 1; j++)
        {
            cin >> h;
            if (h > temp)
            {
                nHigh++;
            }
            if (h < temp)
            {
                nLow++;
            }

            temp = h;
        }

        cout << "Case " << i << ": " << nHigh << " " << nLow << "\n";
    }
}
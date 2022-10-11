#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int a[10];
    long long t, res;

    for (long n, m; cin >> n >> m;)
    {
        res = 0;
        
        for (int i = n; i <= m; i++)
        {
            for (int j = 0; j <= 9; j++)
            {
                a[j] = 0;
            }
                
            t = i;

            while (t != 0)
            {
                if (a[t % 10] == 1)
                {
                    break;
                }
                a[t % 10] = 1;
                t /= 10;
            }
            if (t == 0)
            {
                res++;
            }
        }

        cout << res << endl;
    }
}
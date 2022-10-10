#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    for (int b, n; cin >> b >> n && b != 0 && n != 0;)
    {
        vector<int> banks;
        bool canPay = true;
        for (int i = 0; i < b; i++)
        {
            int money;
            cin >> money;
            banks.push_back(money);
        }
        for (int k = 0; k < n; k++)
        {
            
            int d, c, v;
            cin >> d >> c >> v;
            banks[d - 1] -= v;
            banks[c - 1] += v;
        }
        for (int i = 0; i < b; i++)
        {
            if (banks[i] < 0)
            {
                canPay = false;
            }
        }

        cout << (canPay ? "S" : "N") << endl;
    } 
}
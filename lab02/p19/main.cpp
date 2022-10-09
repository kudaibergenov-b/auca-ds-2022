#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int t;
    cin >> t;
    cin.ignore();
    string s;

    while (t--) 
    {
        int count = 0;
        getline(cin, s);

        for (auto c : s)
        {
            if (c == 'M')
            {
                count++;
            } else if (c == 'F')
            {
                count--;
            }
        }

        if (count == 0 && sz(s) >= 4)
        {
            cout << "LOOP" << endl;
        } else 
        {
            cout << "NO LOOP" << endl;
        }
    }
}
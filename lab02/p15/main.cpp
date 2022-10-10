#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) 
    {
        int max = 0;
        string str;
        int a;
        vector<string> s;
        vector<int> in;
        for (int j = 0; j < 10; j++)
        {
            cin >> str >> a;
            s.push_back(str);
            in.push_back(a);
            if (in[j] >= max) 
            {
                max = in[j];
            }
        }

        cout << "Case #" << i << ":" << endl;

        for (int k = 0; k < sz(in); k++)
        {
            if (in[k] == max)
            {
                cout << s[k] << endl;
            }  
        }
    }
}
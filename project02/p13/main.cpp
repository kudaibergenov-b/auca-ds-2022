#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

void printVector(vector<string> &vs)
{
    int max = 0;

    for (auto s : vs)
    {
        if ((int)s.length() > max)
        {
            max = s.length();
        }
    }

    for (auto &s : vs)
    {
        string t;
        t.resize(max - s.length(), ' ');
        t += s;
        swap(s, t);
    }

    for (auto &s : vs)
    {
        cout << s << endl;
    }
}

int main()
{
    iostream::sync_with_stdio(false);

    string s;
    vector<string> vs;

    while (getline(cin, s))
    {
        if (s == "")
        {
            sort(begin(vs), end(vs),
            [](string s1, string s2)
            {   reverse(begin(s1), end(s1));
                reverse(begin(s2), end(s2));
                return s1 < s2; });

            printVector(vs);

            cout << endl;
            vs.clear();
            continue;
        }
        vs.push_back(s);
    }
    sort(begin(vs), end(vs),
        [](string s1, string s2)
        { reverse(begin(s1), end(s1));
          reverse(begin(s2), end(s2));
          return s1 < s2; });
          
    printVector(vs);
}
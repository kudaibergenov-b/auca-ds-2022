#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct Skill
{
    string mName;
    int mValue;
    Skill(const string &name)
        : mName(name), mValue(0)
        {
        }
    Skill(const string &name, int value)
        : mName(name), mValue(value)
        {
        }
};

int main()
{
    iostream::sync_with_stdio(false);

    int m, n;
    vector<Skill> skills1;
    string name;
    int value;

    cin >> m >> n;

    for (int i = 0; i < m; ++i)
    {
        cin >> name >> value;
        skills1.emplace_back(name, value);
    }

    sort(begin(skills1), end(skills1),
        [](const Skill &s1, const Skill&s2)
        { return s1.mName < s2.mName; });

    for (int k = 0; k < n; ++k)
    {
        int total = 0;
        
        while (cin >> name && name != ".")
        {
            for (int j = 0; j < m; ++j)
            {
                if (name == skills1[j].mName)
                {
                    total += skills1[j].mValue;
                }
            }
        }

        cout << total << endl;
    }
}
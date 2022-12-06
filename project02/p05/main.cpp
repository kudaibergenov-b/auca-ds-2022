#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct Pair
{
    int mAsci;
    int mValue;
    Pair(const int &asci, int value)
        : mAsci(asci), mValue(value)
    {
    }
};

int main()
{
    iostream::sync_with_stdio(false);

    vector<Pair> pairs;
    string line;
    int count = 0;

    while (getline(cin, line))
    {
        if (count > 0)
        {
            cout << endl;
        }

        count++;

        vector<int> frequences(127);

        for (auto c : line)
        {
            ++frequences[c];
        }

        for (int i = 0; i < sz(frequences); ++i)
        {
            if (frequences[i] > 0)
            {
                pairs.emplace_back((char)i, frequences[i]);
            }
        }

        sort(begin(pairs), end(pairs),
            [](const Pair &p1, const Pair &p2)
            { 
                if (p1.mValue != p2.mValue)
                {
                    return p1.mValue < p2.mValue;
                }
                else
                {
                    return p1.mAsci > p2.mAsci;
                }
            });

        for (auto p : pairs)
        {
            cout << p.mAsci << " " << p.mValue << "\n";
        }

        pairs = vector<Pair>();
    }
}
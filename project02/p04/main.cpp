#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct SpecialString 
{
    string mLetters;
    int mCount;
    SpecialString(const string &letters)
        : mLetters(letters), mCount(0)
        {
            for (int i = 0; i < (int)letters.length() - 1; ++i)
            {
                for (int j = i + 1; j < (int)letters.length(); ++j)
                {
                    if (letters[i] > letters[j])
                    {
                        ++mCount;
                    }
                }
            }
        } 
};

int main()
{
    iostream::sync_with_stdio(false);

    vector<SpecialString> ss;
    int M;
    cin >> M;

    for (int i = 0; i < M; ++i)
    {
        int n, m;
        cin >> n >> m;

        for (int j = 0; j < m; ++j)
        {
            string letters;

            for (int k = 0; k < n; ++k)
            {
                char ch;
                cin >> ch;
                letters += ch;
            }

            ss.emplace_back(letters);
        }

        stable_sort(begin(ss), end(ss),
            [](const SpecialString &ss1, const SpecialString &ss2)
            { return ss1.mCount < ss2.mCount; });

        for (int t = 0; t < m; ++t)
        {
            cout << ss[t].mLetters << "\n";
        }

        ss = vector<SpecialString>();
        
        if (i < M - 1)
        {
            cout << "\n";
        }
    }
}
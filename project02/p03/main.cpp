#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct Freq
{
    char mLetter;
    int mCount;
    Freq(const char &letter, int count)
        : mLetter(letter), mCount(count)
        {
        }
};

int main()
{
    iostream::sync_with_stdio(false);
    
    char letter;
    int x, r, c, m, n;
    cin >> x;

    for (int i = 1; i <= x; ++i)
    {
        vector<Freq> frequences;
        vector<int> alphabet(26);

        cin >> r >> c >> m >> n;

        for (int j = 0; j < r; ++j)
        {
            for (int k = 0; k < c; ++k)
            {
                cin >> letter;
                ++alphabet[letter - 65];
            }
        }

        for (int j = 0; j < 26; ++j)
        {
            if (alphabet[j] > 0)
            {
                frequences.emplace_back((char)(j + 65), alphabet[j]);
            }
        }

        sort(begin(frequences), end(frequences),
            [](const Freq &f1, const Freq &f2)
            { return f1.mCount > f2.mCount; });

        int max = frequences[0].mCount;
        int size = 0;

        for (int j = 0; j < sz(frequences); ++j)
        {
            if (frequences[j].mCount == max)
            {
                size += frequences[j].mCount * m;
            }
            else 
            {
                size += frequences[j].mCount * n;
            }
        } 

        cout << "Case " << i << ": " << size << endl;   
    }
}
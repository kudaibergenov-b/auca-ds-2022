#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    string words[16] = {"Happy", "birthday", "to", "you",
                        "Happy", "birthday", "to", "you",
                        "Happy", "birthday", "to", "Rujia",
                        "Happy", "birthday", "to", "you"};
    
    int num;
    cin >> num;
    bool everyoneSang = false;
    vector<string> names(num);
    
    for (int i = 0; i < num; i++)
    {
        cin >> names[i];
    }
        
    for (int a = 0, word = 0; word < 16 || !everyoneSang; ++a, ++word)
    {
        word %= 16;
        cout << names[a] << ": " << words[word] << endl;
        
        if (a + 1 == num)
        {
            everyoneSang = true;
            a = -1;
        }
    }
}
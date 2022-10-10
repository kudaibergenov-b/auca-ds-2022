#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int n, length;
    bool ordered;
    bool title = true;
    cin >> n;

    while (n--)
    {
        vector<int> lumberjacks;
        for (int i = 0; i < 10; i++)
        {
            cin >> length;
            lumberjacks.push_back(length);
        }

        if (lumberjacks[0] < lumberjacks[1])
        {
            for (int i = 1; i < sz(lumberjacks) - 1; i++)
            {
                if (lumberjacks[i] < lumberjacks[i + 1])
                {
                    ordered = true;
                } else {
                    ordered = false;
                    break;
            }
            }
        } 
        else if (lumberjacks[0] > lumberjacks[1])
        {
            for (int i = 1; i < sz(lumberjacks) - 1; i++)
            {
                if (lumberjacks[i] > lumberjacks[i + 1])
                {
                    ordered = true;
                } else {
                    ordered = false;
                    break;
            }
            }
        }
        
        if (title)
        {
            cout << "Lumberjacks:" << endl;
            title = false;
        }
        
        cout << (ordered ? "Ordered" : "Unordered") << endl;
    }
}
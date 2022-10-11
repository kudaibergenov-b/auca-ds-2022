#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int t, r, m, res, s[505];
	cin >> t;

	while (t--) 
    {
		cin >> r;

		for (int i = 0; i < r; i++) 
        {
			cin >> s[i];
		}

		sort(s, s + r);
		m = s[r / 2];
		res = 0;

		for (int i = 0; i < r; i++) 
        {
			res += abs(m - s[i]);
		}

		cout << res << endl;
	}
}
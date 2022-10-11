#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int t, n, a[1001];
	int i, j;
	cin >> t;

	while (t--)
    {
		cin >> n;
		int ds, res = 0;

		for (i = 0; i < n; i++)
        {
			cin >> ds;

			for (j = i - 1; j >= 0; j--)
            {
                if (ds < a[j])
                {
					a[j + 1] = a[j];
                }
				else
                {
					break;
                }
            }
				
			a[j + 1] = ds;
			res += j + 1;
		}

		cout << res << endl;
	}
}
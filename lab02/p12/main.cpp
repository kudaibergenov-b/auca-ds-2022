#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

void computeDigits(int n, int &sum, int &count)
{
    sum = 0;
    count = 0;
    while (n != 0) 
    {
        sum += n % 10;
        count++;
        n /= 10;
    }
}

int main()
{
    iostream::sync_with_stdio(false);

    for (int n; cin >> n && n != 0;)
    {
        int sumOfDigits;
        int countOfDigits;
        do {
            computeDigits(n, sumOfDigits, countOfDigits);
            n = sumOfDigits;
        } while (countOfDigits != 1);

        cout << n << "\n";
    }
}
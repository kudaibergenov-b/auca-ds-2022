#include <bits/stdc++.h>

class BigInt
{
    friend std::ostream &operator<<(std::ostream &out, const BigInt &x);
    friend std::istream &operator>>(std::istream &inp, const BigInt &x);
    friend BigInt operator+(const BigInt &x, const BigInt &y);
    std::vector<int> mDigits;
    bool mIsNegative;
public:
    BigInt()
        : mIsNegative(false)
    {
        mDigits.push_back(0);
    }

    BigInt(const std::string &s)
        : mIsNegative(false)
    {
        if (s.empty())
        {
            throw std::runtime_error("BigInteger value cannot be empty");
        }

        int i = 0;
        if (s[i] == '-' || s[i] == '+')
        {
            if (s[i] == '-')
            {
                mIsNegative = true;
            }
            ++i;
        }

        while (i < (int)s.size())
        {
            if (!isdigit(s[i]))
            {
                throw std::runtime_error("Incorrect format of BigInteger");
            }

        mDigits.push_back(s[i] - '0');
        ++i;
        }

        if (mDigits.empty())
        {
            throw std::runtime_error("Incorrect format of BigInteger");
        }
    }

    BigInt(long long x)
        : BigInt(std::to_string(x))
    {
    }
private:
    static BigInt addAbsValues(const BigInt &x, const BigInt &y)
    {
        auto itX = x.mDigits.rbegin();
        auto itY = y.mDigits.rbegin();

        BigInt z;
        z.mDigits.resize(std::max(x.mDigits.size(), y.mDigits.size()) + 1);
        auto itZ = z.mDigits.rbegin();

        int carry = 0;

        while (itX != x.mDigits.rend() || itY != y.mDigits.rend())
        {
            int s = carry;
            if (itX != x.mDigits.rend())
            {
                s += *itX;
                ++itX;
            }
            if (itY != y.mDigits.rend())
            {
                s += *itY;
                ++itY;
            }
            *itZ = s % 10;
            carry = (s > 9) ? 1 : 0;
            ++itZ;
        }
        if (carry != 0)
        {
            *itZ = carry;
        }
        if (z.mDigits.size() > 1 && z.mDigits.front() == 0)
        {
            z.mDigits.erase(z.mDigits.begin());
        }

        return z;
    }
};

inline BigInt operator+(const BigInt &x, const BigInt &y)
{   
    BigInt z = BigInt::addAbsValues(x, y);
    return z;
}

inline std::ostream &operator<<(std::ostream &out, const BigInt &x)
{
    if (x.mIsNegative)
    {
        out << "-";
    }

    for (auto digit : x.mDigits)
    {
        out << digit;
    }

    return out;
}

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    vector<BigInt> v(5001);
    v[0] = 0;
    v[1] = 1;
    
    for (int i = 2; i < 5001; ++i)
    {
        v[i] = v[i - 1] + v[i - 2];
    }

    int x;
    while (cin >> x)
    {
        cout << "The Fibonacci number for " << x << " is " << v[x] << "\n";
    }
}
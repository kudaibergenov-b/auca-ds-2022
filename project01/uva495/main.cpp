#include <bits/stdc++.h>

class BigInt
{
    friend std::ostream &operator<<(std::ostream &out, const BigInt &x);
    friend std::istream &operator>>(std::istream &inp, const BigInt &x);
    friend BigInt operator+(const BigInt &x, const BigInt &y);
    friend BigInt operator-(const BigInt &x, const BigInt &y);
    friend bool operator==(const BigInt &x, const BigInt &y);
    friend bool operator!=(const BigInt &x, const BigInt &y);
    friend bool operator<(const BigInt &x, const BigInt &y);
    friend bool operator>(const BigInt &x, const BigInt &y);
    friend bool operator>=(const BigInt &x, const BigInt &y);
    friend bool operator<=(const BigInt &x, const BigInt &y);
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

    BigInt &operator+=(const BigInt &x)
    {
        *this = *this + x;
        return *this;
    }

    BigInt &operator-=(const BigInt &x)
    {
        *this = *this - x;
        return *this;
    }

    BigInt &operator-()
    {
        if (*this == 0 || *this == -0)
        {
            *this = 0;
            return *this;
        }

        if (this->mIsNegative)
        {
            this->mIsNegative = false;
            return *this;
        }
        else
        {
            this->mIsNegative = true;
            return *this;
        }
    }

    BigInt &operator+()
    {
        return *this;
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

    static BigInt subAbsValues(const BigInt &x, const BigInt &y)
    {
        BigInt z;
        z.mDigits.clear();

        auto itX = x.mDigits.rbegin();
        auto itY = y.mDigits.rbegin();

        int borrow = 0;
        while (itX != x.mDigits.rend())
        {
            int d = *itX - borrow;
            ++itX;

            if (itY != y.mDigits.rend())
            {
                d -= *itY;
                ++itY;
            }

            if (d < 0)
            {
                d += 10;
                borrow = 1;
            }
            else
            {
                borrow = 0;
            }

            z.mDigits.push_back(d);
        }

        while (z.mDigits.size() > 1 && z.mDigits.back() == 0)
        {
            z.mDigits.pop_back();
        }

        std::reverse(z.mDigits.begin(), z.mDigits.end());
        return z;
    }

    static int compAbsValues(const BigInt &x, const BigInt &y)
    {
        if (x.mDigits.size() < y.mDigits.size())
        {
            return -1;
        }

        if (x.mDigits.size() > y.mDigits.size())
        {
            return 1;
        }

        for (int i = 0; i < (int)x.mDigits.size(); ++i)
        {
            if (x.mDigits[i] != y.mDigits[i])
            {
                return x.mDigits[i] - y.mDigits[i];
            }
        }
        return 0;
    }
};

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

inline std::istream &operator>>(std::istream &inp, BigInt &x)
{
    char ch;
    if (!(inp >> ch))
    {
        return inp;
    }

    if (!(isdigit(ch) || ch == '+' || ch == '-'))
    {
        inp.putback(ch);
        inp.setstate(std::ios_base::failbit);
        return inp;
    }

    std::string s;
    s += ch;

    while (inp.get(ch) && isdigit(ch))
    {
        s += ch;
    }

    if (inp)
    {
        inp.putback(ch);
    }

    if (s.size() == 1 && (s[0] == '+' || s[0] == '-'))
    {
        inp.setstate(std::ios_base::failbit);
        return inp;
    }

    x = BigInt(s);

    return inp;
}

inline BigInt operator+(const BigInt &x, const BigInt &y)
{   
    if (x.mIsNegative == y.mIsNegative)
    {
        BigInt z = BigInt::addAbsValues(x, y);
        z.mIsNegative = x.mIsNegative;
        return z;
    }

    int c = BigInt::compAbsValues(x, y);
    if (c == 0)
    {
        return BigInt();
    }
    else if (c > 0)
    {
        BigInt z = BigInt::subAbsValues(x, y);
        z.mIsNegative = x.mIsNegative;
        return z;
    }
    else 
    {
        BigInt z = BigInt::subAbsValues(y, x);
        z.mIsNegative = y.mIsNegative;
        return z;
    }
}

inline BigInt operator-(const BigInt &x, const BigInt &y)
{
    if (!(x.mIsNegative) && y.mIsNegative)
    {
        BigInt z = BigInt::addAbsValues(x, y); 
        z.mIsNegative = false;
        return z;
    }

    if (x.mIsNegative && !(y.mIsNegative))
    {
        BigInt z = BigInt::addAbsValues(x, y); 
        z.mIsNegative = true;
        return z;
    }

    if (x.mIsNegative == y.mIsNegative)
    {
        int c = BigInt::compAbsValues(x, y); 
        if (c == 0)
        {
            return BigInt();
        }
        else if (c > 0)
        {
            BigInt z = BigInt::subAbsValues(x, y);
            z.mIsNegative = x.mIsNegative;
            return z;
        }
        else
        {
            BigInt z = BigInt::subAbsValues(y, x);
            z.mIsNegative = !y.mIsNegative;
            return z;
        }
    }

    return BigInt();
}

BigInt &operator++(BigInt &x) 
{
    x += 1;
    return x;
}

BigInt operator++(BigInt &x, int) 
{
    BigInt z = x;
    z += 1;
    return z;
}

BigInt &operator--(BigInt &x)
{
    x -= 1;
    return x;
}

BigInt operator--(BigInt &x, int)
{
    BigInt z = x;
    z -= 1;
    return z;
}

inline bool operator==(const BigInt &x, const BigInt &y)
{
    return x.mIsNegative == y.mIsNegative && x.mDigits == y.mDigits;
}

inline bool operator!=(const BigInt &x, const BigInt &y)
{
    return !(x == y);
}

inline bool operator<(const BigInt &x, const BigInt &y)
{
    if (!x.mIsNegative && !y.mIsNegative)
    {
        return x.mDigits < y.mDigits;
    }
    else if (x.mIsNegative && y.mIsNegative)
    {
        return x.mDigits > y.mDigits;
    }
    else if (x.mIsNegative && !y.mIsNegative)
    {
        return true;
    }
    else
    {
        return false;
    }
}

inline bool operator>(const BigInt &x, const BigInt &y)
{
    return (y < x);
}

inline bool operator>=(const BigInt &x, const BigInt &y)
{
    return !(x < y);
}

inline bool operator<=(const BigInt &x, const BigInt &y)
{
    return !(x > y);
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
#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>

class BigInt
{
    friend std::ostream &operator<<(std::ostream &out, const BigInt &x);
    friend BigInt operator+(const BigInt &x, const BigInt &y);
    std::vector<int> mDigits;
    bool mIsNegative;

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

        bool isSign(true);
        bool isZero(true);

        for (auto d : s)
        {
            if (d == '-' && isSign)
            {
                mIsNegative = true;
                isSign = false;
            }
            else if (d == '+' && isSign)
            {
                isSign = false;
            }
            else if (d == '0' && isZero)
            {
                isZero = true;
            }
            else if (isdigit(d))
            {
                mDigits.push_back(d - '0');
                isSign = false;
                isZero = false;
            }
            else
            {
                throw std::runtime_error("Incorrect format of BigInteger");
            }
        }
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

inline BigInt operator+(const BigInt &x, const BigInt &y)
{
    if (!x.mIsNegative && !y.mIsNegative)
    {
        return BigInt::addAbsValues(x, y);
    }

    throw std::runtime_error("not implemented yet");
}
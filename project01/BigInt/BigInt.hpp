#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>

class BigInt
{
    friend std::ostream &operator<<(std::ostream &out, const BigInt &x);
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

        int index = 0;
        
        if (s.at(index) == '+')
        {
            index++;
        } 
        else if (s.at(index) == '-')
        {
            mIsNegative = true;
            index++;
        } else if (isdigit(s.at(index))) 
        {
            mDigits.push_back((int)s.at(index));
            index++;
        }

        for (int i = 0; i < (int)s.length(); i++)
        {
            if (isdigit(s.at(i)))
            {
                mDigits.push_back((int)s.at(i));
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
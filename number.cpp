#include "number.h"

#include <algorithm>

Number operator+(const std::string& str, const Number& num)
{
    Number res;
    res._number = str + num._number;
    return res;
}

Number Number::operator+(const std::string& n2)
{
    _number += n2;
    return *this;;
}

Number Number::operator+(const Number& num2)
{
    if (num2._number == "0")
        return  *this;

    int n = _number.length(), m = num2.length();

    Number n2(num2);
    if(n < m)
        _number = std::string(m - n, '0') + _number; // adding zeroes

    else if (n > m)
        n2 = std::string(n - m, '0') + n2; // adding zeroes

    Number res;
    UShort k = 0;

    for (int i = n2.length() - 1; i >= 0; --i)
    {

        int n3 = k + (_number[i] - '0') + n2[i];
        k = 0;

        if (n3 > 9)
            k = 1;

        n3 %= 10;
        res = std::to_string(n3) + res;
    }

    if (k)
        res = std::to_string(k) + res;


    while (res[0] == 0 && res._number != "0")
        res = res._number.substr(1);

    return res;
}

Number Number::operator-(const Number &b)
{
    if (b._number == "0")
        return  *this;

    Number a(_number);

    int k = 0;
    int j = a.length() - 1;

    for (int i = b.length() - 1; i >= 0; --i)
    {
        int c = k - b[i];
        k = 0;

        if ((a[j] + c) < 0)
        {
            c += 10;
            k = -1;
        }

        a._number[j] += c;
        --j;
    }
    while (j >= 0 && k != 0)
    {
        int c = k;
        k = 0;

        if ((a[j] + c) < 0)
        {
            c += 10;
            k = -1;
        }

        a._number[j] += c;
        --j;
    }
    while (a[0] == 0 && a._number != "0")
        a = a._number.substr(1);

    return a;
}

std::pair<Number, Number> Number::split(UShort n) const
{
    int l = _number.length() - n/2;

    Number n1 = _number.substr(0, l);
    Number n2 = _number.substr(l);

    return std::make_pair(n1, n2);
}
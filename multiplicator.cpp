#include "multiplicator.h"

#include <random>
#include <iostream>
#include <ctime>
#include <fstream>

Number Multiplicator::randomValue(const UShort& k)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    Number res;

    for (size_t i = 0; i < k; ++i)
    {
        if (i != 0)
        {
            std::uniform_int_distribution<> d(0, 9);
            res = res + std::to_string(d(gen));
        }

        else {
            std::uniform_int_distribution<> d1(1, 9); // first digit should not be zero
            res = res + std::to_string(d1(gen));
        }
    }

    return res;
}


Number GrSchMult::multiply(const Number &n1, const Number &n2)
{
    Number answer;

    UShort i1 = 0; // parameter for shifting position in result
    UShort l = n1.length(), m = n2.length();

    for (int i = l - 1; i > -1; --i) // Go from right to left in n1
    {
        UShort k = 0;
        Number res0;

        for (int j = m - 1; -1 < j; --j)  // Go from right to left in num2
        {
            UShort sum = (n1[i] * n2[j]) + k;
            k = sum / 10; // the remainder that is needed to add it in new sum
            res0 = std::to_string(sum % 10) + res0;
        }

        if (k > 0) // store the remainder
            res0 = std::to_string(k) + res0;

        res0 = res0 + std::string(i1, '0'); // shifting by adding zeroes in the end
        answer = answer + res0; // addition of two big-hw2020-1-AnikaDzhkha
        i1++;
    }

    return answer;
}

Number DivideAndConquer::multiply(const Number& n1, const Number& n2)
    // xy = ac * 10^n + (ad + bc) * 10^(n/2) + bd
{
    if(n1.length() == 1 && n2.length() == 1) // base case
        return  Number(n1[0] * n2[0]);

    Number answer;
    Number x(n1), y(n2);

    size_t n = std::max(n1.length(), n2.length());

    while (x.length() < n)
        x = "0" + x;

    while (y.length() < n)
        y = "0" + y;

    Number a = x.split(n).first, b = x.split(n).second,
            c = y.split(n).first, d = y.split(n).second;

    Number ac = multiply(a, c), ad = multiply(a, d),
           bd = multiply(b, d), bc = multiply(b, c);

    n /= 2;
    answer = (ac + std::string(n * 2, '0')) + ((ad + bc) + std::string(n, '0')) + bd;

    return answer;
}

Number Karatsuba::multiply(const Number& n1, const Number& n2)
    // xy = ac * 10^n + ((a+b)(c+d) - ac -bd) * 10^(n/2) + bd
{
    if(n1.length() == 1 && n2.length() == 1) // base case
        return  Number(n1[0] * n2[0]);

    Number answer;
    Number x(n1), y(n2);

    size_t n = std::max(n1.length(), n2.length());

    while (x.length() < n)
        x = "0" + x;

    while (y.length() < n)
        y = "0" + y;

    Number a = x.split(n).first, b = x.split(n).second,
           c = y.split(n).first, d = y.split(n).second;

    Number ac = multiply(a, c), bd = multiply(b, d),
           res0 = multiply((a + b), (c + d)),
           middle = res0 - ac - bd;

    n /= 2;
    answer = (ac + std::string(n * 2, '0')) + (middle + std::string(n, '0')) + bd;

    return answer;
}

void Multiplicator::testMethod(size_t n, std::ofstream& out)
{
    double  res1 = 0, res2 = 0, res3 = 0;
    Number x = randomValue(n), y = randomValue(n);
    GrSchMult sch;
    DivideAndConquer dac;
    Karatsuba k;
    for (size_t i = 0; i < 3;  ++i) {
        clock_t start1 = clock();
        sch.multiply(x, y);
        clock_t stop1 = clock();

        res1 += (double) (stop1 - start1) / CLOCKS_PER_SEC;

        clock_t start2 = clock();
        dac.multiply(x, y);
        clock_t stop2 = clock();

        res2 += (double) (stop2 - start2) / CLOCKS_PER_SEC;

        clock_t start3 = clock();
        k.multiply(x, y);
        clock_t stop3 = clock();
        res3 += (double) (stop3 - start3) / CLOCKS_PER_SEC;
    }

    out << n << ','
    << (res1 / 3) << ','
    << (res2 / 3) << ','
    << (res3 / 3) << "\n";

}

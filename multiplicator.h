#ifndef NUMBERS_MULTIPLICATOR_H
#define NUMBERS_MULTIPLICATOR_H

#include "number.h"
#include <vector>


class Multiplicator
{
public:
    Multiplicator() { };

    static Number randomValue(const UShort& k);
    static void testMethod(size_t n, std::ofstream& out);

    virtual Number multiply(const Number& n1, const Number& n2) = 0; // pure virtual
    virtual ~Multiplicator() { };
};

class GrSchMult : public Multiplicator
{
public:
    virtual Number multiply(const Number &n1, const Number &n2) override;
};

class DivideAndConquer : public Multiplicator
{
public:
    virtual Number multiply(const Number& n1, const Number& n2) override;
};

class Karatsuba : public Multiplicator
{
public:
    virtual Number multiply(const Number& n1, const Number& n2) override;
};


#endif //NUMBERS_MULTIPLICATOR_H

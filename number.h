#ifndef NUMBERS_NUMBER_H
#define NUMBERS_NUMBER_H

#include <string>
#include <utility>

typedef unsigned short UShort;

class Number
{
public:
    Number() : _number() { } // default constructor
    Number(std::string num) : _number(std::move(num)) { }
    Number(UShort num) : _number(std::to_string(num)) { }
    ~Number() { } // default destructor
public:
    size_t length() const { return _number.length(); }
    UShort operator[] (const UShort& index) const { return _number[index] - '0'; }

public:
    friend Number operator+(const std::string& str, const Number& num);
    Number operator+(const std::string& n2);
    Number operator+(const Number& n2);
    Number operator-(const Number& b);
    std::pair<Number, Number> split(UShort n) const;

private:
    std::string _number;

};


#endif //NUMBERS_NUMBER_H

#include "Fraction.h"
#include <iostream>

Fraction::Fraction(int num, int denom)
{
    numerator = num;
    denominator = denom;
}

Fraction Fraction::operator+(const Fraction& obj) const
{
    Fraction result;
    result.numerator = (numerator * obj.denominator) + (denominator * obj.numerator);
    result.denominator = denominator * obj.denominator;
    return result;
}

Fraction Fraction::operator-(const Fraction& obj) const
{
    Fraction result;
    result.numerator = (numerator * obj.denominator) - (denominator * obj.numerator);
    result.denominator = denominator * obj.denominator;
    return result;
}

Fraction Fraction::operator*(const int& n) const
{
    Fraction result;
    result.numerator = numerator * n;
    result.denominator = denominator * n;
    return result;
}

std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
    os << obj.numerator << "/" << obj.denominator;
    return os;
}
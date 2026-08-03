#pragma once

#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int num = 0, int denom = 1);
    Fraction operator+(const Fraction& obj) const;
    Fraction operator-(const Fraction& obj) const;
    Fraction operator*(const int& n) const;
    friend Fraction operator*(const int& n, const Fraction& obj) {return obj*n;}
    friend std::ostream& operator<<(std::ostream& os, const Fraction& obj);
    void show() const {std::cout << numerator << "/" << denominator << std::endl;};
};
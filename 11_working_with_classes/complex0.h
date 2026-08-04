#pragma once

#include <iostream>

class complex {
private:
    double real;
    double imaginative;

public:
    complex(double rl = 0.0, double im = 0.0);

    complex operator+(const complex& obj) const;
    complex operator-(const complex& obj) const;
    complex operator*(const complex& obj) const;
    complex operator*(double n) const;
    complex operator~() const;

    friend complex operator*(double n, const complex& obj);
    friend std::ostream& operator<<(std::ostream& os, const complex& obj);
    friend std::istream& operator>>(std::istream& is, complex& obj);
};
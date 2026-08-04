#include "complex0.h"

complex::complex(double rl, double im)
{
    real = rl;
    imaginative = im;
}

complex complex::operator+(const complex& obj) const
{
    return complex(real + obj.real, imaginative + obj.imaginative);
}

complex complex::operator-(const complex& obj) const
{
    return complex(real - obj.real, imaginative - obj.imaginative);
}

complex complex::operator*(const complex& obj) const
{
    double nw_rl = real * obj.real - imaginative * obj.imaginative;
    double nw_im = real * obj.imaginative + imaginative * obj.real;
    return complex(nw_rl, nw_im);
}

complex complex::operator*(double n) const
{
    return complex(n * real, n * imaginative);
}

complex complex::operator~() const
{
    return complex(real, -imaginative);
}

complex operator*(double n, const complex& obj)
{
    return obj * n;
}

std::ostream& operator<<(std::ostream& os, const complex& obj)
{
    os << "(" << obj.real << ", " << obj.imaginative << "i)";
    return os;
}

std::istream& operator>>(std::istream& is, complex& obj)
{
    double rl, im;
    std::cout << "real: ";
    is >> rl;
    if (is.fail())
        return is;
    std::cout << "imaginative: ";
    is >> im;
    obj = complex(rl, im);
    return is;
}
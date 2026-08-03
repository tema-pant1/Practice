#include "Vector.h"

#include <cmath>
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR
{
    const double Rad_to_deg = 45.0 / atan(1.0);

    double Vector::magval() const
    {
        return sqrt((x * x) + (y * y));
    }

    double Vector::angval() const
    {
        if (x == 0.0 && y == 0.0)
            return 0.0;
        else return atan2(y, x);
    }

    void Vector::set_x(double n1, double n2)
    {
        x = n1 * cos(n2 / Rad_to_deg);
    }

    void Vector::set_y(double n1, double n2)
    {
        y = n1 * sin( n2 / Rad_to_deg);
    }

    Vector::Vector()
    {
        x = y = 0.0;
        mode = RECT;
    }

    Vector::Vector(double n1, double n2, Mode form)
    {
        mode = form;
        if (form == RECT)
        {
            x = n1;
            y = n2;
        }
        else if (form == POL)
        {
            set_x(n1, n2);
            set_y(n1, n2);
        }
        else
        {
            cout << "Uncorrect 3rd argument to Vector() --";
            cout << "vector set to 0\n";
            *this = Vector();
        }
    }

    void Vector::reset(double n1, double n2, Mode form)
    {
        *this = Vector(n1, n2, form);
    }

    Vector::~Vector()
    {
    }

    Vector Vector::operator+(const Vector& obj) const
    {
        return Vector(x + obj.x, y + obj.y);
    }

    Vector Vector::operator-(const Vector& obj) const
    {
        return Vector(x - obj.x, y - obj.y);
    }

    Vector Vector::operator-() const
    {
        return Vector(-x, -y);
    }

    Vector Vector::operator*(double n) const
    {
        return Vector(n * x, n * y);
    }

    Vector operator*(double n, const Vector& obj)
    {
        return obj*n;
    }

    std::ostream& operator<<(std::ostream& os, const Vector& obj)
    {
        if (obj.mode == Vector::RECT)
            os << "(x, y) = (" << obj.x << ", " << obj.y << ")";
        else if (obj.mode == Vector::POL)
            os << "(m, a) = (" << obj.magval() << ", " << obj.angval()*Rad_to_deg << ")";
        else
            os << "vector object mode is invalid.";
        return os;
    }
}
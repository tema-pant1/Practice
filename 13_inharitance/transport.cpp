#include "transport.h"
#include <iostream>

vehicle::vehicle(double f, double sp)
{
    fuel = f;
    speed = sp;
}

void vehicle::show() const
{
    formating format = SetFormat();
    std::cout << "Fuel: " << fuel << '\n';
    std::cout << "Speed: " << speed << '\n';
    restore(format);
}

void SportsCar::show() const
{
    vehicle::show();
    std::cout << "Type: Sports Car\n";
}

void SportsCar::boost()
{
    if (fuel >= 10)
    {
        fuel -= 10;
        speed += 100;
    }
    else 
        std::cout << "Not enougth fuel. Boost canceled.\n";
}

vehicle::formating vehicle::SetFormat(std::ostream& os) const
{
    formating format;
    format.flags = os.setf(std::ios_base::fixed, std::ios_base::floatfield);
    format.prec = os.precision(2);
    return format;
}

void vehicle::restore(formating& f, std::ostream& os) const
{
    os.setf(f.flags, std::ios_base::floatfield);
    os.precision(f.prec);
}


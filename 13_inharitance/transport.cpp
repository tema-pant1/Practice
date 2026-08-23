#include "transport.h"
#include <iostream>

vehicle::vehicle(double f, double sp)
{
    fuel = f;
    speed = sp;
}

void vehicle::show() const
{
    std::cout << "Fuel: " << fuel << '\n';
    std::cout << "Speed: " << speed << '\n';
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

formatting 
#include "shape.h"
#include <iostream>

void shape::move(double nx, double ny)
{
    x = nx;
    y = ny;
}

void rectangle::info() const
{
    using std::cout;
    using std::endl;
    cout << "Coordinates rectnagle - (" << x << ", " << y << ")\n";
    cout << "Width: " << width << endl;
    cout << "Height: " << height << endl;
    cout << "Area: " << area() << endl;
}

void triangle::info() const
{
    using std::cout;
    using std::endl;
    cout << "Coordinates triangle - (" << x << ", " << y << ")\n";
    cout << "Base: " << base << endl;
    cout << "Height: " << height << endl;
    cout << "Area: " << area() << endl;
}




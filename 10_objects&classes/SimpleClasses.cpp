#include "SimpleClasses.h"
#include <iostream>

Rect::Rect()
{
    width = 0;
    height = 0;
    area = 0;
    std::cout << "Default constructor called.\n";
}

Rect::Rect(double w, double h)
{
    width = w;
    height = h;
    area = CalcArea();
    std::cout << "Custom constructor called.\n";
}

Rect::Rect(double side)
{
    width = side;
    height = side;
    area = CalcArea();
    std::cout << "Square constructor called.\n";
}

Rect::~Rect()
{
    std::cout << "Rect object destroyed.\n";
}

void Rect::Show() const
{
    using std::cout; 
    using std::endl;
    cout << "Width: " << width << endl;
    cout << "Height: " << height << endl;
    cout << "Area: " << area << endl;
}


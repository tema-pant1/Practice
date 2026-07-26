#pragma once

class Rect
{

private:
    double width;
    double height;
    double area;
    double CalcArea() { return width*height; };

public:
    Rect();
    Rect(double w, double h);
    Rect(double side);
    ~Rect();
    void Show() const;
    double GetArea() const {return area;}


};


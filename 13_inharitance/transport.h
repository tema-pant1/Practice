#pragma once
#include <iostream>

class vehicle {
protected:
    double fuel;
    double speed;
    struct formating {
        std::ios_base::fmtflags flags;
        std::streamsize prec;
    };      
    formating SetFormat(std::ostream& os = std::cout) const;
    void restore(formating& f, std::ostream& os = std::cout) const;
    
public:
    vehicle(double f = 0.0, double sp = 0.0);
    virtual void show() const;
    virtual ~vehicle() {}
};

class SportsCar : public vehicle {
public:
    SportsCar(double f = 0.0, double sp = 0.0) : vehicle(f, sp) {};
    SportsCar(const vehicle& v): vehicle(v) {};
    virtual ~SportsCar() {}
    virtual void show() const;
    void boost();
};
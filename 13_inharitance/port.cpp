#include <cstring>
#include <iostream>
#include "port.h"

port::port(const char* br, const char* st, int b) : bottles(b)
{
    brand = new char[std::strlen(br) + 1];
    std::strcpy(brand, br);
    std::strcpy(style, st);
}

port::port(const port& p) : bottles(p.bottles)
{
    brand = new char[std::strlen(p.brand) + 1];
    std::strcpy(brand, p.brand);
    std::strcpy(style, p.style);
}

port& port::operator=(const port& p)
{
    if (this == &p)
        return *this;

    delete[] brand;
    brand = new char[std::strlen(p.brand) + 1];
    std::strcpy(brand, p.brand);
    std::strcpy(style, p.style);
    bottles = p.bottles;
    return *this;
}

port& port::operator+=(int b)
{
    bottles += b;
    return *this;
}

port& port::operator-=(int b)
{
    if (bottles - b >= 0)
        bottles -= b;
    else
        std::cout << "Bottles count cannot negative!\n";
    return *this;
}

void port::show() const
{
    using std::cout; using std::endl;
    cout << "Brand: " << brand << endl;
    cout << "Kind: " << style << endl;
    cout << "Bottles: " << bottles << endl;
}

ostream& operator<<(ostream& os, const port& p)
{
    os << p.brand << ", " << p.style << ", " << p.bottles;
    return os;
}

vintagePort::vintagePort() : port("none", "vintage", 0)
{
    nickname = new char[5];
    std::strcpy(nickname, "none");
    year = 0;
}

vintagePort::vintagePort(const char* br, int b, const char* nn, int y) : port(br, "vintage", b), year(y)
{
    nickname = new char[std::strlen(nn) + 1];
    std::strcpy(nickname, nn);
}

vintagePort::vintagePort(const vintagePort& vp) : port(vp)
{
    nickname = new char[std::strlen(vp.nickname) + 1];
    std::strcpy(nickname, vp.nickname);
    year = vp.year;
}

vintagePort& vintagePort::operator=(const vintagePort& vp)
{
    if (this == &vp)
        return *this;

    port::operator=(vp);
    delete[] nickname;
    nickname = new char[std::strlen(vp.nickname) + 1];
    std::strcpy(nickname, vp.nickname);
    year = vp.year;
    return *this;
}

void vintagePort::show() const
{
    port::show();
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Year: " << year << std::endl;
}

ostream& operator<<(ostream& os, const vintagePort& vp)
{
    os << (port)vp;
    os << ", " << vp.nickname << ", " << vp.year;
    return os;
}
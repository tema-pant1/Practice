#pragma once
#include <iostream>

using namespace std;

class port {
private:
    char* brand;
    char style[20];
    int bottles;

public:
    port(const char* br = "none", const char* st = "none", int b = 0);
    port(const port& p);
    virtual ~port() {delete[] brand;}
    port& operator=(const port& p);
    port& operator+=(int b);
    port& operator-=(int b);
    int bottleCount() const {return bottles;}
    virtual void show() const;
    friend ostream& operator<<(ostream& os, const port& p);
};

class vintagePort : public port {
private:
    char* nickname;
    int year;

public:
    vintagePort();
    vintagePort(const char* br, int b, const char * nn, int y);
    vintagePort(const vintagePort& vp);
    virtual ~vintagePort() {delete[] nickname;};
    vintagePort& operator=(const vintagePort& vp);
    virtual void show() const;
    friend ostream& operator<<(ostream& os, const vintagePort& vp);
};
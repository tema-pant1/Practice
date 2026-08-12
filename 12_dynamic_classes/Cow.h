#pragma once

class cow {
private:
    char name[20];
    char* hobby;
    double weight;

public:
    cow();
    cow(const char* nm, const char* ho, double wt);
    cow(const cow& c);
    ~cow();
    cow& operator=(const cow& c);
    void show() const;
};
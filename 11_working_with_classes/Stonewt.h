#pragma once

#include <iostream>

class stonewt {
public:
    enum Mode {STONE, LBS};

private:
    static const int Lbs_per_stn = 14;
    Mode mode;
    int stone;
    double pds_left;
    double pounds;

public:
    stonewt(double lbs, Mode form = LBS);
    stonewt(int stn, double lbs, Mode form = STONE);
    stonewt();
    ~stonewt();
    void set_stone() {mode = STONE;}
    void set_lbs() {mode = LBS;}

    stonewt operator+(const stonewt& obj) const;
    stonewt operator-(const stonewt& obj) const;
    stonewt operator*(const stonewt& obj) const;
    bool operator<(const stonewt& obj) const;
    bool operator<=(const stonewt& obj) const;
    bool operator>(const stonewt& obj) const;
    bool operator>=(const stonewt& obj) const;
    bool operator==(const stonewt& obj) const;
    bool operator!=(const stonewt& obj) const;

    friend std::ostream& operator<<(std::ostream& os, const stonewt& obj);
    friend std::istream& operator>>(std::istream& is, stonewt& obj);

};


#include "Stonewt.h"

using std::cout;

stonewt::stonewt(double lbs, Mode form)
{
    mode = form;
    stone = int (lbs) / Lbs_per_stn;
    pds_left = int (lbs) % Lbs_per_stn + lbs - int (lbs);
    pounds = lbs;
}

stonewt::stonewt(int stn, double lbs, Mode form)
{
    mode = form;
    stone = stn;
    pds_left = lbs;
    pounds = stone * Lbs_per_stn + lbs;
}

stonewt::stonewt()
{
    mode = LBS;
    stone = pounds = pds_left = 0;
}

stonewt::~stonewt()
{    
}

stonewt stonewt::operator+(const stonewt& obj) const
{
    return stonewt(pounds + obj.pounds);
}

stonewt stonewt::operator-(const stonewt& obj) const
{
    return stonewt(pounds - obj.pounds);
}

stonewt stonewt::operator*(const stonewt& obj) const
{
    return stonewt(pounds*obj.pounds);
}

bool stonewt::operator<(const stonewt& obj) const
{
    return pounds < obj.pounds;
}

bool stonewt::operator<=(const stonewt& obj) const
{
    return pounds <= obj.pounds;
}

bool stonewt::operator>(const stonewt& obj) const
{
    return pounds > obj.pounds;
}

bool stonewt::operator>=(const stonewt& obj) const
{
    return pounds >= obj.pounds;
}

bool stonewt::operator==(const stonewt& obj) const
{
    return pounds == obj.pounds;
}

bool stonewt::operator!=(const stonewt& obj) const
{
    return pounds != obj.pounds;
}

std::ostream& operator<<(std::ostream& os, const stonewt& obj)
{
    if (obj.mode == stonewt::STONE)
        os << obj.stone << " stone, " << obj.pds_left << " pounds.";
    else if (obj.mode == stonewt::LBS)
        os << obj.pounds << " pounds.";
    else
        cout << "Incorrect mode for operator <<.";
    return os;
}

std::istream& operator>>(std::istream& is, stonewt& obj)
{
    double lbs;
    is >> lbs;
    obj = lbs;
    return is;
}
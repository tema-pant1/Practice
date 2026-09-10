#pragma once
#include <string>
#include <valarray>
#include <iostream>

class playlist {
private:
    typedef std::valarray<double> dblArray;
    std::string owner;
    dblArray durations;

    std::ostream& showArray(std::ostream& os) const;

public:
    playlist() : owner("none."), durations() {}
    explicit playlist(const std::string& own) : owner(own), durations() {}
    explicit playlist(int n): owner("none."), durations(n) {}
    playlist(const std::string& own, int n) : owner(own), durations(n) {}

    double total() const {return durations.sum();}
    const std::string& getOwner() const {return owner;}

    friend std::ostream& operator<<(std::ostream& os, const playlist& p);
};
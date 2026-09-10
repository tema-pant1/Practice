#pragma once
#include <string>
#include <valarray>
#include <iostream>

class playlist : private std::string, private std::valarray<double> {
private:
    typedef std::valarray<double> dblArray;
    std::ostream& showArray(std::ostream& os) const;
    void arrayIn(std::istream& is, std::ostream& os = std::cout);

public:
    using std::valarray<double>::operator[];
    using std::valarray<double>::min;
    using std::valarray<double>::max;

    playlist() : std::string("none."), dblArray() {}
    explicit playlist(const std::string& own) : std::string(own), dblArray() {}
    explicit playlist(int n): std::string("none."), dblArray(n) {}
    playlist(const std::string& own, int n) : std::string(own), dblArray(n) {}

    double total() const {return dblArray::sum();}
    const std::string& getOwner() const {return (const std::string&)*this;}
    void input(std::istream& is = std::cin, std::ostream& os = std::cout);

    friend std::ostream& operator<<(std::ostream& os, const playlist& p);
    friend std::istream& operator>>(std::istream& is, playlist& p);
};
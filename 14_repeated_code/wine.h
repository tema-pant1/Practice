#pragma once
#include <valarray>
#include <string>
#include <iostream>

class wine {
private:
    using arrayInt = std::valarray<int>;
    using pairArray = std::pair<arrayInt, arrayInt>;
    using string = std::string;
    
    string label;
    pairArray bottles;
    int size;
    static const int YEAR;
    inline static const int DEFAULT_SIZE = 10;

    void inputReset(std::istream& is = std::cin);

public:
    wine();
    wine(const char* l, int y, const int yr[], const int bot[]);
    wine(const char* l, int y = DEFAULT_SIZE);
    
    static int getYear();
    void getBottles();
    const string& getLabel() const {return label;};
    int sum() const {return bottles.second.sum();};
    void show() const;
};
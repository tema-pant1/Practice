#pragma once

#include <iostream>

class word {
private:
    char* str;
    int len;
    static int count;

public:
    word();
    word(const char* wrd);
    word(const word& obj);
    ~word();
    word& operator=(const word& obj);
    friend std::ostream& operator<<(std::ostream& os, const word& obj);
};
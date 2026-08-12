#pragma once

#include <iostream>

class word {
private:
    char* str;
    int len;
    static int count;
    static const int CINLIM = 91;

public:
    word();
    word(const char* wrd);
    word(const word& obj);
    ~word();
    
    int length() const {return len;};
    word& operator=(const word& obj);
    
    char& operator[](int i);
    const char& operator[](int i) const;
    void wordlow();
    void wordup();
    int find(char ch);

    friend const word& longer(const word& w1, const word& w2);
    friend word concat(const word& w1, const word& w2);
    friend bool operator<(const word& wrd1, const word& wrd2);
    friend bool operator>(const word& wrd1, const word& wrd2);
    friend bool operator==(const word& wrd1, const word& wrd2);
    friend word operator+(const word& w1, const word& w2);
    friend std::ostream& operator<<(std::ostream& os, const word& obj);
    friend std::istream& operator>>(std::istream& is, word& input);

    static int how_many() {return count;}
};
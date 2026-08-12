#include <cstring>
#include <limits>
#include <cctype>
#include "Word.h"

int word::count = 0;

word::word()
{
    len = 5;
    str = new char[len + 1];
    std::strcpy(str, "Pant1");
    count++;
    //std::cout << "Object " << str << " created. " << count << " total.\n";
}

word::word(const char* wrd)
{
    len = std::strlen(wrd);
    str = new char[len + 1];
    std::strcpy(str, wrd);
    count++;
    //std::cout << "Object " << str << " created. " << count << " total.\n";
}

word::word(const word& obj)
{
    len = obj.len;
    str = new char[len + 1];
    std::strcpy(str, obj.str);
    count++;
    //std::cout << "Object " << str << " created. " << count << " total.\n";
}

word::~word()
{
    char* temp = new char[len + 1];
    std::strcpy(temp, str);
    delete [] str;
    count--;
    //std::cout << "Object " << temp << " deleted. " << count << " left.\n";
    delete [] temp;
}

const word& longer(const word& w1, const word& w2)
{
    if (w1.length() > w2.length())
        return w1; 
    else
        return w2;
}

word concat(const word& w1, const word& w2)
{
    char* temp = new char[w1.len + w2.len + 1];
    std::strcpy(temp, w1.str);
    std::strcat(temp, w2.str);
    word result(temp);
    delete [] temp;
    return result;
}

word& word::operator=(const word& obj)
{
    if (this == &obj)
        return *this;
    delete [] str;
    len = obj.len;
    str = new char[len+1];
    std::strcpy(str, obj.str);
    return *this;
}

char& word::operator[](int i)
{
    return str[i];
}

void word::wordlow()
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (std::isalpha(str[i]) && std::isupper(str[i]))
            str[i] = std::tolower(str[i]);
    }
}

void word::wordup()
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (std::isalpha(str[i]) && std::islower(str[i]))
            str[i] = std::toupper(str[i]);  
    }  
}

int word::find(char ch)
{
    int cnt = 0;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == ch)
            cnt++;
    return cnt;
}

const char& word::operator[](int i) const
{
    return str[i];
}

bool operator<(const word& wrd1, const word& wrd2)
{
    return (std::strcmp(wrd1.str, wrd2.str) < 0);
}

bool operator>(const word& wrd1, const word& wrd2)
{
    return wrd2 < wrd1;
}

bool operator==(const word& wrd1, const word& wrd2)
{
    return (std::strcmp(wrd1.str, wrd2.str) == 0);
}

word operator+(const word& w1, const word& w2)
{
    char* temp = new char[w1.len + w2.len + 1];
    std::strcpy(temp, w1.str);
    std::strcat(temp, w2.str);
    word result(temp);
    delete [] temp;
    return result; 
}


std::ostream& operator<<(std::ostream& os, const word& obj)
{
    os << obj.str;
    return os;
}

std::istream& operator>>(std::istream& is, word& input) 
{
    char temp[word::CINLIM];
    is.get(temp, word::CINLIM);
    if (is)
        input = temp;
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return is;
}
#include <cstring>
#include "Word.h"

int word::count = 0;

word::word()
{
    len = 5;
    str = new char[len + 1];
    std::strcpy(str, "Pant1");
    count++;
    std::cout << "Object " << str << " created. " << count << " total.\n";
}

word::word(const char* wrd)
{
    len = std::strlen(wrd);
    str = new char[len + 1];
    std::strcpy(str, wrd);
    count++;
    std::cout << "Object " << str << " created. " << count << " total.\n";
}

word::word(const word& obj)
{
    len = obj.len;
    str = new char[len + 1];
    std::strcpy(str, obj.str);
    count++;
    std::cout << "Object " << str << " created. " << count << " total.\n";
}

word::~word()
{
    char* temp = new char[len + 1];
    std::strcpy(temp, str);
    delete [] str;
    count--;
    std::cout << "Object " << temp << " deleted. " << count << " left.\n";
    delete [] temp;
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

std::ostream& operator<<(std::ostream& os, const word& obj)
{
    os << obj.str;
    return os;
}
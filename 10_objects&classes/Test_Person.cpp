#include "Person.h"
#include <iostream>

int main()
{
    Person one;
    Person two("Smythecraft");
    Person three("Dimwiddy", "Sam");
    one.Show();
    std::cout << std::endl;
    one.FormalShow();
    two.Show();
    std::cout << std::endl;
    two.FormalShow();
    three.Show();
    std::cout << std::endl;
    three.FormalShow();
    return 0;
}
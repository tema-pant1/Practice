#include "SimpleClasses.h"
#include <iostream>

void test_rect()
{
    Rect rect1(1.43, 2.32);
    rect1.Show();
    Rect rect2 = Rect(23, 4.4); 
    rect2.Show();
    Rect r1 = Rect(5, 10);
    Rect r2(3, 4);
    r1 = Rect(7 ,8);
    const Rect r3(4, 5);
    std::cout << "Aera r3: " << r3.GetArea() << std::endl;
    r3.Show();
    Rect r4 = {6, 7}; 
    Rect r5{8, 9};
    Rect r7 = 9.5; 
}

int main()
{
    test_rect(); 
    return 0;
}
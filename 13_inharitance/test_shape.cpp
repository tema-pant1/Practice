#include "shape.h"
#include <iostream>

using namespace std;

const int SIZE = 5;

int main()
{
    rectangle r1(2, 4, 5, 2);
    r1.info();
    r1.move(1, 1);
    r1.info();

    triangle t1(1, 2, 3, 4);
    t1.info();
    t1.move(1, 1);
    t1.info();

    shape* shapes[SIZE];
    double x, y, width, rec_height, base, tr_height;
    short choise;
    double total_area = 0;

    for (int i = 0; i < SIZE; i++)
    {
        choise = -1;
        cout << "Enter 1 to create rectangle, 2 - triangle\n>>";
        while (choise != 1 && choise != 2)  
            cin >> choise;
        switch (choise)
        {
            case 1:
                cout << "Enter x and y coordinates:\nx: ";
                cin >> x;
                cout << "y: ";
                cin >> y;
                cout << "Width: "; 
                cin >> width;
                cout << "Height: ";
                cin >> rec_height;
                shapes[i] = new rectangle(x, y, width, rec_height);
                break;
            case 2:
                cout << "Enter x and y coordinates:\nx: ";
                cin >> x;
                cout << "y: ";
                cin >> y;
                cout << "Base: ";
                cin >> base;
                cout << "Height: ";;
                cin >> tr_height;
                shapes[i] = new triangle(x, y, base, tr_height);
                break;
            default:
                break;
        }        
    }

    for (int i = 0; i < SIZE; i++)
    {
        cout << "#" << (i+1) << endl;
        shapes[i]->info();
        total_area += shapes[i]->area();
    }

    cout << "Total area: " << total_area << endl;

    for (int i = 0; i < SIZE; i++)
        delete shapes[i];

    return 0;  
}
#include "ticket.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

const int SIZE = 4;

inline void skip();

int main()
{
    ticket* tickets[SIZE];
    for(int i = 0; i < SIZE; i++)
    {
        cout << "#" << i+1 << endl;
        cout << "Enter event: ";
        string event;
        getline(cin, event);
        cout << "Enter event price: ";
        double price;
        cin >> price;
        int choise;
        cout << "If you want create VIP ticket enter 2, else 1: ";
        while (cin >> choise && (choise != 1 && choise != 2))
            cout << "Enter either 1 or 2: ";
        if (choise == 1)
            tickets[i] = new ticket(event, price);
        else 
        {
            skip();
            cout << "Enter perk: ";
            string perk;
            getline(cin, perk);
            cout << "Enter surcharge: ";
            double surcharge;
            cin >> surcharge;
            tickets[i] = new VIPticket(event, price, surcharge, perk);
        }
        skip();
    }
    cout << endl;
    for (int i = 0; i < SIZE; i++)
    {
        tickets[i]->ShowInfo();
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < SIZE; i++)
    {
        delete tickets[i];
        cout << endl;
    }
    return 0;
}


inline void skip()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
#include "Customer.h"
#include <iostream>
#include <limits>
#include <cstring>

using namespace std;

int entering(Stack& stack)
{
     char name[35] = "1";
     double salary;
     int cnt(0);
     customer smone;
     while (!stack.is_full())
    {
        
        cout << "Enter data about customer (max 10, press Enter to quit)\n";
        cout << "Name: ";
        cin.getline(name, 35);
        if (name[0] == '\0') break;
        else if (cin.fail())
        {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "Salary: ";
        cin >> salary;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;
        strcpy(smone.fullname, name);
        smone.payment = salary;
        stack.push(smone);
        cnt++;
    }
    return cnt;
}

void extraction(Stack& stack)
{
    customer smone;
    double total = 0;
    int cnt = 0;
    while (stack.pop(smone)) 
    {
        cout << "Extracted: " << smone.fullname << ", salary: " << smone.payment << endl;
        total += smone.payment;
        cout << "Total: " << total << endl;
        cout << "\n";
        cnt++;
    }
    cout << endl;
    cout << "Processed customers: " << cnt << endl;
    cout << "Total amount: " << total << endl;
}

int main()
{
    int cnt(0);
    double total(0);
    Stack customers;
    cnt = entering(customers);
    cout << "Entering is complete. Customers in stack: " << cnt << endl;
    cout << "\n\n";
    extraction(customers);

}

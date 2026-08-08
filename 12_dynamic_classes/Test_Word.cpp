#include "Word.h"


const int NAMESIZE = 5;

void func1(word& obj)
{
    std::cout <<"string passed by reference: " <<  obj << std::endl;
}

void func2(word obj)
{
    std::cout << "string passed by value: " << obj << std::endl;
}

int main()
{
    using namespace std;
    word names[NAMESIZE];
    cout << "Enter " << NAMESIZE << " names (empty name to stop):\n";
    int i;
    for (i = 0; i < NAMESIZE; i++)
    {
        cout << i+1 << ": ";
        cin >> names[i];
        if (!cin || names[i][0] == '\0')
            break;
    }
    
    int total = i;
    cout << "You input " << total << " names. " << word::how_many() << " objects created.\n"; 
    word len_min = names[0];
    word alpha_max = names[0];

    for (i = 0; i < total; i++)
    {
        cout << names[i][0] << ": " << names[i] << endl;
        if (names[i].length() < len_min.length()) len_min = names[i];
        if (names[i] > alpha_max) alpha_max = names[i];
    }

    cout << "The shortiest name: " << len_min << endl;
    cout << "Max name: " << alpha_max << endl;

    word s("Sergey"), n("Bob");
    word lnger = longer(s, n);
    cout << "Longer name: " << lnger << endl;
    lnger = concat(s, n);
    cout << "s + n = " << lnger << endl;

}
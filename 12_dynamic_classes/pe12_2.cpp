#include <iostream>
using namespace std;
#include "Word.h"

int main()
{
    word s1(" and I am a C++ student.");
    word s2 = "Please enter your name: ";
    word s3;
    cout << s2;
    cin >> s3;
    s2 = "My name is " + s3;
    cout << s2 << ".\n";
    s2 = s2 + s1;
    s2.wordup();
    cout << "The string\n" << s2 << "\ncontains " << s2.find('A') << " 'A' characters in it.\n";
    s1 = "red";
    word rgb[3] = {word(s1), word("green"), word("blue")};
    cout << "Enter the name of primary color for mixing light: ";
    word ans;
    bool success = 0;
    while (cin >> ans)
    {
        ans.wordlow();
        for (int i = 0; i < 3; i++)
        {
            if (ans == rgb[i])
            {
                cout << "That's right!\n";
                success = 1;
                break;
            }
        }
        if (success)
            break;
        else
            cout << "Try again!\n";
    }
    cout << "Bye!\n";
    return 0;
} 
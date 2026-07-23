#include <iostream>
#include "golf.h"

static int len = 3;

int main()
{
   
    // golf test;
    // setgolf(test);
    // showgolf(test);
    using std::cout, std::cin, std::endl;
    golf players[len];
    int i(0), real_len(0);
    cout << "Enter " << len << " Players:\nPlayer #1\n";
    while((i < len) && (setgolf(players[i])))
    {
        real_len++;
        i++;
        cout << "Player #" << (i+1) << endl;
    }

    for (int i = 0; i < real_len; i++)
    {
        cout << "Player #" << (i+1) << endl;
        showgolf(players[i]);
    }
}
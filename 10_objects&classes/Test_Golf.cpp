#include <iostream>
#include "Golf.h"

const int len = 3;

int main()
{
    using std::cout, std::cin, std::endl;
    golf players[len];
    int i(0), real_len(0);
    cout << "Enter " << len << " Players:\nPlayer #1\n";
    while((i < len) && (players[i].SetGolf()))
    {
        real_len++;
        i++;
        cout << "Player #" << (i+1) << endl;
    }

    for (int i = 0; i < real_len; i++)
    {
        cout << "Player #" << (i+1) << endl;
        players[i].Show();
    }
}
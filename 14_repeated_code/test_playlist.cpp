#include "playlist_private.h"
#include <iostream>

using namespace std;

const int SIZE = 3;

int main()
{
    playlist playlists[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        playlists[i] = playlist(SIZE);
        playlists[i].input();
        cout << endl;
    }

    for (int i = 0; i < SIZE; i++)
    {
        cout << playlists[i] << endl;
        cout << "Fisrt timing: " << playlists[i][0] << endl;
        cout << "Max: " << playlists[i].max() << endl;
        cout << "Min: " << playlists[i].min() << endl;  
        cout << "Total: " << playlists[i].total() << endl;
        cout << endl;
    }
    return 0;
}
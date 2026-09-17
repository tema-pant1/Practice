#include "person.h"
#include <limits>

using namespace std;

const int SIZE = 3;

int main()
{
    person* cast[SIZE];
    int choise = -1;
    for (int i = 0; i < SIZE; i++)
    {
        cout << "\n#" << i+1 << endl;
        cout << "Choose person to create:\n";
        cout << "1 - teacher    2 - coach\n";
        cout << "3 - teacher&coach\n";
        cout << ">> ";
        while (!(cin >> choise) || (choise < 1) || (choise > 3))
        {
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            cout << ">>";
        }    

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choise)
        {
            case 1:
                cast[i] = new teacher;
                cast[i]->set();
                break;
            
            case 2:
                cast[i] = new coach;
                cast[i]->set();
                break;

            case 3:
                cast[i] = new teacherCoach;
                cast[i]->set();
                break;
            
            default:
                cout << "Invalid choise!\n";
                cout << "Program will create teacher...";
                cast[i] = new teacher;
                cast[i]->set();
                break;
        }
    }

    cout << endl;

    for (int i = 0; i < SIZE; i++)
    {
        cout << "#" << i+1 << endl;
        cast[i]->show();
        cout << endl;
    }    
    
    for (int i = 0; i < SIZE; i++)
        delete cast[i];

    return 0;
}
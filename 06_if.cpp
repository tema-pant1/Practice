#include <iostream>
#include <cctype>
#include <vector>
#include <fstream>
#include <cstdlib>


using namespace std;

void read_ch()
{
    char sym;
    vector<char> text;
    cout << "Enter anything and program will print it.";
    cout << " To end enter @\n";
    cout << "(Program will skip digits, ";
    cout << "and transform upper register symbols to lower and lower to upper)\n";
    cin.get(sym);
    while (sym != '@')
    {
        if (isdigit(sym)) {cin.get(sym); continue;}
        else if (islower(sym)) text.push_back(toupper(sym));
        else if (isupper(sym)) text.push_back(tolower(sym));
        else text.push_back(sym);
        cin.get(sym);
    }
    for (char x: text) cout << (char)x;
    cout << endl;
}

void average_donats()
{
    int size(10), majors(0);
    vector<double> donats;
    double donat, average = 0;
    cout << "Enter every donats (max 10):\n";
    while (donats.size() < 10)
    {
        cin >> donat;
        if (cin.fail()) 
        {
            cout << "You enter uncorrect data! Input stopped.\n";
            break;
        }
        donats.push_back(donat);
        average += donat;
    }
    average /= donats.size();
    for (double i: donats) if (i > average) majors++;
    cout << "Average donat: " << average << endl;
    cout << "Dontas highier than average donat: " << majors << endl;
}

void simple_menu()
{
    cout << "Please enter on of the following choices:\n";
    cout << "a)Harry Potter    b)Ron Uizly\n";
    cout << "c)Volan de Mort   d)Dumbldor\n";
    char choice;
    cin >> choice;
    while (true)
    {
        if (choice == 'a') {cout << "Harry Potter has a ligtning bolt scar\n"; break;}
        else if (choice == 'b') {cout << "Ron Uizly is a best friend of Harry Potter\n"; break;}
        else if (choice == 'c') {cout << "Volan de Mort want to kill Harry Potter\n"; break;}
        else if (choice == 'd') {cout << "Dumbldor is a director of Hogwards\n"; break;}
        else {cout << "Plese enter a,b,c or d: "; cin >> choice;};
    }
}

const int strsize = 100;

struct bop 
{
    char fullname[strsize];
    char title[strsize];
    char bopname[strsize];
    int preference;
};

void BOP()
{
    vector<bop> participants = 
    {
     {"Artem Pantikhovskiy","CEO", "Sex machine", 2},
     {"Varya Sotskaya", "CEO wife", "Tigritca", 0}, 
     {"Nikita Gubanov", "Ingener", "Iron man", 1}
    };
    cout << "a)Display by name     b)Display by title\n";
    cout << "c)Display by bopname  d)Display by preference\n";
    cout << "q)Quit\n";
    char choice;
    while ((choice = (char)cin.get()) != 'q')
    {
        switch (choice)
        {
            case 'a': for (bop elem: participants) cout << elem.fullname << endl; break;
            case 'b': for (bop elem: participants) cout << elem.title << endl; break;
            case 'c': for (bop elem: participants) cout << elem.bopname << endl; break;
            case 'd': 
            for (bop elem: participants) 
            {
                switch (elem.preference)
                {
                    case 0: cout << elem.fullname << endl; break;
                    case 1: cout << elem.title << endl; break;
                    case 2: cout << elem.bopname << endl; break;
                    default: cout << "error!" << endl; break;
                } 
            }; break;
            default: cout << "Please, enter one of the variants: "; break;
        }
        cin.get();
    }
    cout << "Bye!\n";
}

void Kingdom_tax()
{
    float salary;
    cout << "Enter your salary: ";
    cin >> salary;

    while (!cin.fail() && salary >= 0)
    {
        float tax;
        if (salary > 35000) tax = 10000*0.1+20000*0.15+(salary-35000)*0.2;
        else if (salary <= 35000 && salary > 15000) tax = 10000*0.1+(salary-15000)*0.15;
        else if (salary <= 15000 && salary > 5000) tax = (salary - 5000)*0.1;
        else tax = 0;
        cout << "Your tax: " << tax << endl << ">> ";
        cin >> salary;
    }
}

struct patron
{
    string name;
    float donat;
};

void OZVL()
{
    int size;
    fstream file("Patrons.txt");
    if (!file.is_open())
    {
        cout << "Error of openning file!\nProgram is terminating";
        exit(EXIT_FAILURE);
    }
    file >> size; file.get();
    patron* patrons = new patron[size];
    patron participant;
    for (int i = 0; i < size; i++)
    {
        getline(file, participant.name);
        file >> participant.donat;
        file.get();
        patrons[i] = participant;
    }
    int cnt = 0;
    cout << "\nGrand Patrons:\n";
    for (int i = 0; i < size; i++) 
    {
        if(patrons[i].donat >= 10000) cout << patrons[i].name << endl;
        cnt++;
    }
    if (!cnt) cout << "none\n"; 
    cout << "\nPatrons:\n";
    cnt = 0;
    for (int i = 0; i < size; i++) 
    {
        if(patrons[i].donat < 10000) cout << patrons[i].name << endl;
        cnt++;
    }
    if (!cnt) cout << "none\n"; 
}

void words()
{
    int vowels(0), consonats(0), others(0);
    char first;
    cout << "Enter words (q to quit) : \n";
    string word;
    cin >> word;
    while (word != "q")
    {
        first = tolower(word[0]);
        if (isalpha(first))
        {
            if (first == 'a' || first == 'e' || first == 'i' || first == 'o' || first == 'u' || first == 'y')
            vowels++;
            else consonats++;
        } else others++;
        cin >> word;
    }
    cout << vowels << " words beginning with vowels\n";
    cout << consonats << " words beginning with consonants\n";
    cout << others << " others\n";
}

void cnt_symbols()
{
    fstream file("cnt_symbols.txt");
    if (!file.is_open())
    {
        cout << "Error of oppeing file!\n";
        cout << "Program terminating\n";
        exit(EXIT_FAILURE);
    }
    char symbol;
    int cnt;
    while ((symbol = file.get()) != EOF) cnt++;
    cout << "Amount of symbols: " << cnt << endl;;
}

int main()
{
    OZVL();
    return 0;
}
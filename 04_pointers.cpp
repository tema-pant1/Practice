#include <iostream>
#include <string>
#include <array>

using namespace std;

void name()
{
    string name, surname;
    char grade;
    int age;
    cout << "What is your first name? ";
    getline(cin, name);
    cout << "What is your last name? ";
    getline(cin, surname);
    cout << "What letter grade do you deserve? ";
    cin >> grade;
    cout << "What is your age? ";
    cin >> age;

    cout << "Name: " << name << ", " << surname << endl;
    cout << "Grade: " << char(grade+1) << endl;
    cout << "Age: " << age << endl;
}

void dessert()
{
    string name, dessert;
    cout << "Enter your name:\n";
    getline(cin, name);
    cout << "Enter your favorite dessert:\n";
    getline(cin, dessert);
    cout << "I have some delicious " << dessert << " for you, " << name << ".\n";
}

void name2()
{
    string name, surname, info;
    cout << "Enter your first name: ";
    getline(cin, name);
    cout << "Enter your last name: ";
    getline(cin, surname);
    info = name + ", " + surname;
    cout << "Here's the information in a single string: " << info << endl;
}

struct CandyBar
{
    string name;
    float weight;
    int calories;
};

void candy()
{
    CandyBar snack = {"Mocha Munch", 2.3, 350};
    cout << "name - " << snack.name << endl;
    cout << "weight - " << snack.weight << endl;
    cout << "calories - " << snack.calories << endl;
}

void candyes()
{
    CandyBar candyes[3] = 
    {{"cake", 23.2, 3500},
     {"skittles", 2.5, 250},
     {"snikers", 20.3, 500}};
    for (int i=0; i<3; i++)
    {
        cout << "name - " << candyes[i].name << endl;
        cout << "weight - " << candyes[i].weight << endl;
        cout << "calories - " << candyes[i].calories << endl;
    }
}   

struct pizza
{
    string company;
    int diameter;
    float weigth;
};

void pizza_analitic()
{
    pizza* dodo = new pizza;
    cout << "Enter manufacturer: ";
    getline(cin, dodo->company);
    cout << "Enter diameter of pizza: ";
    cin >> dodo->diameter;
    cout << "Enter weight of pizza: ";
    cin >> dodo->weigth;

    cout << "\npizza from: " << dodo->company << "\ndiameter: " << dodo->diameter;
    cout << "\nweight: " << dodo->weigth << endl;
}

void runs()
{
    array<float, 3> runs;
    for (int i=0; i<3; i++) cin >> runs[i];
    cout << "first run: " << runs[0];
    cout << "\nseecond run: " << runs[1];
    cout << "\nthird run: " << runs[2];
    cout << "\naverage: " << (runs[0]+runs[1]+runs[2])/3 << endl;
}

int main()
{
    runs();
    return 0;
}
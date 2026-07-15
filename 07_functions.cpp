#include <iostream>
#include <vector>
#include <array>
#include <cstdlib>


typedef long long lg;

using namespace std;

double harmonic_mean(const double x, const double y)
{
    return (2.0*x*y)/(x+y);
}

void calculate_harmonic()
{
    vector<array<double, 3>> results;
    double a, b, harmonic;
    array<double, 3> current;
    cout << "Enter couple of numbers. (to stop one of the number must be a 0):\n";
    cin >> a; cin >> b;
    while (a*b != 0)
    {
        current[2] = harmonic_mean(a, b);
        current[0] = a; current[1] = b;
        results.push_back(current);
        cin >> a; cin >> b;
    }
    cout << "harmonic mean of numbers:\n";
    for (auto elem: results)
        cout << elem[0] << ", " << elem[1] << " - " << elem[2] << endl;
}   

vector<int> golf_entering()
{
    vector<int> results;
    int game(0);
    cout << "Enter results of your golf games (max 10).\n";
    cout << "To stop entering enter -1\n";
    cin >> game;
    while (results.size() < 10 && !cin.fail() && game >= 0)
    {
        results.push_back(game);
        if (results.size() < 10) cin >> game;
    }
    return results;
}

double golf_average(const vector<int> results)
{
    double average;
    for (int elem: results) average+=elem;
    average /= results.size();
    return average;
}

void golf_output(vector<int> results, double average)
{
    cout << "Your results:\n";
    for (int i = 0; (i+1) < results.size(); i++)
        cout << results[i] << ", ";
    cout << results[results.size()-1] << endl;
    cout << "Average result: " << average << endl;
}

void golf()
{
    vector<int> results = golf_entering();
    double average = golf_average(results);
    golf_output(results, average);

}

struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void print_box(box a)
{
    cout << "maker: " << a.maker << endl;
    cout << "height: " << a.height << endl;
    cout << "width: " << a.width << endl;
    cout << "length: " << a.length << endl;
    cout << "volume: " << a.volume << endl;
}

void set_volume(box& a)
{
    a.volume = a.height * a.width * a.length;
}

void box_function()
{
    box a = {"Peter Griffin", 174.3, 53.2, 12.5, 0};
    print_box(a);
    set_volume(a);
    print_box(a);
}

long double probability(unsigned numbers, unsigned picks)
{
    long double result(1.0), n;
    unsigned p;
    for (p = picks, n = numbers; p > 0; p--, n--)
        result = result * n / p;
    return result;
}

void lottery()
{
    double total, choices, supergame;
    cout << "Enter the total number of choices on the game card,\n"
            "the number of picks allowed and the number of choice on the supergame:\n";
    while ((cin >> total >> choices >> supergame) && choices <= total)
    {
        cout << "You have one chance in ";
        cout << probability(total, choices)*probability(supergame, 1);
        cout << " of winning.\n";
        cout << "Next numbers (q to quit): ";
    }
    cout << "Bye!\n";
}

lg factorial(int n)
{
    if (n < 0) 
    {
        cout << "Uncorrect input! Program is terminating!\n";
        exit(EXIT_FAILURE);
    }
    else if (n == 0) return 1;
    else return n*factorial(n-1);
}

void calculate_factorial()
{
    cout << "Enter a number and program calculate factorial of this number:\n";
    lg fact;
    int n;
    while (cin >> n)
    {
        fact = factorial(n);
        cout << "factorial " << n << " is " << fact << endl;
        cout << "Enter next number (q to quit):\n";
    }
    cout << "Bye!\n";
}

int Fill_array(double array[], int size)
{
    int i(0);
    double current;
    cout << "Please, enter " << size << " numbers:\n";
    while ((i < size) && (cin >> current)) 
        array[i++] = current;
    cout << "The data has been read.\n";
    return i;
}

void show_array(double array[], int size)
{
    cout << "[";
    for (int i = 0; (i+1) < size; i++) 
        cout << array[i] << ", ";
    cout << array[size-1] << "]\nSize: " << size << endl;
    
}

void reverse_array(double array[], int size)
{
    int temp;
    for (int begin = 0, end = (size-1); begin < end; begin++, end--)
    {
        temp = array[begin];
        array[begin] = array[end];
        array[end] = temp;
    }
}

void my_array()
{
    int size;
    cout << "Enter array size: ";
    cin >> size;
    double* array = new double[size];
    size = Fill_array(array, size);
    reverse_array(array+1, size-2);
    show_array(array, size);
}

const int SLEN = 30;
struct student 
{
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};

int getinfo(student array[], int size)
{
    cout << "Enter information about students.\n1 - fullname\n2 - hobby\n3 - ooplevel\n";
    student current;
    int cur_size(0);
    for (int i = 0; i < size; i++)
    {
        cout << "Student #" << (i+1) <<"\n1: ";
        cin.getline(current.fullname, SLEN);
        if (current.fullname[0] == '\0') break;
        cout << "2: ";
        cin.getline(current.hobby, SLEN);
        cout << "3: ";
        cin >> current.ooplevel; 
        array[i] = current;
        while (cin.get() != '\n') continue;
        cur_size++;
    }
    cout << "Reading successful.\n";
    return cur_size;
}

void display1(student st)
{
    cout << "Student: " << st.fullname << endl;
    cout << "Hobby: " << st.hobby << endl;
    cout << "Ooplevel: " << st.ooplevel << endl;
}

void display2(const student* ps)
{
    cout << "Student: " << ps->fullname << endl;
    cout << "Hobby: " << ps->hobby << endl;
    cout << "Ooplevel: " << ps->ooplevel << endl;
}

void display3(const student array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "#" << (i+1) << endl;
        cout << "Student: " << array[i].fullname << endl;
        cout << "Hobby: " << array[i].hobby << endl;
        cout << "Ooplevel: " << array[i].ooplevel << endl;
    }
}


void student_func()
{
    cout << "Enter class size: ";
    int class_size;
    cin >> class_size;
    while (cin.get() != '\n') continue;
    student* ptr_stu = new student[class_size];
    int entered = getinfo(ptr_stu, class_size);
    for (int i = 0; i < entered; i++)
    {
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
    }
    display3(ptr_stu, entered);
    delete [] ptr_stu;
    cout << "Done.\n";
}

double add(double x, double y)
{
    return x+y;
}

double mult(double x, double y)
{
    return x*y;
}

double subtraction(double x, double y)
{
    return x-y;
}

double calculate(double x, double y, double (*op)(double, double))
{
    return op(x, y);
}

void calculator()
{
    double (*operations[3])(double, double) = {add, mult, subtraction};
    cout << "Enter 2 numbers (to stop enter q):\n";
    double x,y;

    while (cin >> x >> y)
    {
        for (int i = 0; i < 3; i++) cout << calculate(x, y, operations[i]) << endl;
    }

    cout << "Bye!\n";
}

int main()
{
    calculator();
    return 0;
}
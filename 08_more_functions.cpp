
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const double pi = 3.1415926535;

int cnt_str = 0;

void print_str(const string* str, int cnt = 0)
{
    if (!cnt)
    {
        cout << *str << endl;
        cnt_str++;
        return;
    }
    else 
    {
        for (int i = 0; i < cnt_str; i++) cout << *str << endl;
        cnt_str += cnt_str;
    }
}

void unused_str()
{
    string p = "Pant1";
    string* ptr_p = &p;
    print_str(ptr_p);
    print_str(ptr_p, 67);
    print_str(ptr_p, 123);
}

inline int max_value(int a, int b)
{
    return (a >= b)?a:b;
}

inline double max_value(double a, double b)
{
    return (a >= b)?a:b;
}

void maximums()
{
    int a, b;
    double c, d;
    cout << "Enter two int numbers:\n";
    cin >> a >> b;
    cout << "Enter two double numbers:\n";
    cin >> c >> d;
    cout << "Max int - " << max_value(a, b) << endl;
    cout << "Max double - " << max_value(c, d) << endl;
}

inline int absolute(int x)
{
    return (x >= 0) ? x : (-x);
}

inline double absolute(double x)
{
    return (x >= 0)?x:(-x);
}

inline double area(double side)
{
    return side*side;
}

inline double area(double width, double height)
{
    return width*height;
}

inline double area(int radius)
{
    return pi*radius*radius;
}

inline void print(int a)
{
    cout << "Integer: " << a << endl;
}
inline void print(double a)
{
    cout << "Double: " << a << endl;
}

inline void print(char a)
{
    cout << "Char: " << a << endl;
}

inline void print(bool a)
{
    cout << "Bool: " << a << endl;
}

inline int add(int a, int b)
{
    return a+b;
}

inline double add(double a, double b)
{
    return a+b;
}

inline int subtract(int a, int b)
{
    return a-b;
}

inline double subtract(double a, double b)
{
    return a-b;
}

inline int multiply(int a, int b)
{
    return a*b;
}

inline double multiply(double a, double b)
{
    return a*b;
}

void task_0105()
{
    int a(3), b(2);
    double c(2.4), d(6.7);
    cout << "Sum: " << add(a, b) << " " << add(c, d) << endl;
    cout << "Subtract: " << subtract(a, b) << " " << subtract(c, d) << endl;
    cout << "Multiply: " << multiply(a, b) << " " << multiply(c, d) << endl;
}

void test(int a)
{
    cout << "int " << a;
}

void test(double a)
{
    cout << "double " << a;
}

template <typename T>
inline T Max(const T& a, const T& b)
{
    return (a >= b) ? a : b;
}

void MaxValue()
{
    int a(2), b(6);
    double c(4.32), d(3.45);
    char e('A'), f('B');
    cout << Max(a, b) << endl;
    cout << Max(c, d) << endl;
    cout << Max(e, f) << endl;

}

template <typename T>
T FindMax(const T array[], const int& size) //Предполагается, что входные данные корректны и их проверять не надо
{
    T max = array[0];
    for (int i = 0; i < size; i++) 
        if (array[i] > max) max = array[i];
    return max;
}

const int Size = 7;

void MaxValArr()
{
    int a[Size] = {2 , 3, 5, 6, 67 ,3, 1};
    double b[Size] = {1.23, 4.25, 6.123, 123,34, 6767.45, 52.2};
    cout << FindMax(a, Size) << endl;
    cout << FindMax(b, Size) << endl;
}

struct Point 
{
    int x, y;
};

template <typename T>
void Show(const T& x)
{
    cout << x << endl;
}

template <> void Show(const Point& x)
{
    cout << "(" << x.x << ", " << x.y << ")\n";
}

void TestShow()
{
    Point a = {2 , 4};
    Show(a);
}

template <typename T>
void Swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

void Swap(char str1[], char str2[])
{
    char temp;
    int i = 0;
    while ((str1[i] != '\0') && (str2[i] != '\0')) //меняем местами, пока не закончится одна из строк
    {                                              //Иначе для соответствия длины строки пришлось бы выделять 
        temp = str1[i];                            //новую память и менять указатели
        str1[i] = str2[i];                         
        str2[i] = temp;
        i++;
    }
}

void SwapStr()
{
    char a[] = "123";
    char b[] = "98765";
    cout << "a = " << a << ",  b = " << b << endl;
    Swap(a, b);
    cout << "a = " << a << ",  b = " << b << endl;
}

template <class T1, class T2>
void TwiceShow(T1 a, T2 b)
{
    cout << a << ", size - " << sizeof(a) << endl;
    cout << b << ", size - " << sizeof(b) << endl;
}

void TestTwiceShow()
{
    int a = 5;
    double b = 87.34;
    TwiceShow(a, b);
}

template <typename T>
inline T Sum(T a, T b)
{
    return a+b;
}

void TestSum()
{
    int a(4), b(8);
    double c(3.45), d(2.12);
    cout << Sum(a, b) << endl; //Вызовется Sum(int, int)
    cout << Sum(c, d) << endl; //Вызовется Sum(double, double)
    cout << Sum<int>(a, c) << endl; //Вызовется Sum(int, int) и с приведется к int (результат 7)
    cout << Sum<double>(3, 4) << endl; //Вызовется Sum(double, double) (результат 7 хз почему не 7.0)
}

int main()
{
    
    return 0;
}
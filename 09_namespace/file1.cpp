#include <iostream>
#include <new>

int total = 100;
static int secret = 42;//если в file2 написать extern int secret, то он выдаст ошибку, так как область видимости secret только в file1

static void Helper()
{
    std::cout << "Message\n";
}

void ShowTotal();
//static функции нужны, если нужны две функции с одним именем в разных файлах и не хочется перегрузок например

char buffer[sizeof(int) * 2];

struct Point {int x,y;};

void placement_new()
{
    using namespace std;
    int* pi = new (buffer) int(42);
    cout << pi << ": " << *pi << endl;
    Point* pp = new (buffer) Point {3, 2};
    cout << pp << ":\nx - " << pp->x << "\ny - " << pp->y << endl;
}

int main()
{
    using namespace std;
    cout << "(Main function in file1) total: " << total << endl;
    ShowTotal();
    placement_new();
    return 0;
}
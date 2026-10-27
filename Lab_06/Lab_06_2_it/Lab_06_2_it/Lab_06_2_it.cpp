#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

void Print(int* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

void SwapPairs(int* a, const int size)
{
    int tmp;
    for (int i = 0; i < size - 1; i += 2)
    {
        tmp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = tmp;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    const int n = 5;
    const int size = 2 * n;
    int a[size];

    int Low = -10;
    int High = 10;

    Create(a, size, Low, High);
    Print(a, size);

    SwapPairs(a, size);
    Print(a, size);

    return 0;
}

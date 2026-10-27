#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

void Print(int* a, const int size, int i)
{
    cout << setw(4) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

void SwapPairs(int* a, const int size, int i)
{
    if (i < size - 1)
    {
        int tmp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = tmp;

        SwapPairs(a, size, i + 2);
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

    Create(a, size, Low, High, 0);
    Print(a, size, 0);

    SwapPairs(a, size, 0);
    Print(a, size, 0);

    return 0;
}
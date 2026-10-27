#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* s, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        s[i] = Low + rand() % (High - Low + 1);
}

void Print(int* s, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << s[i];
    cout << endl;
}

int Count(int* s, const int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (!(s[i] % 2 != 0 && i % 3 == 0))
            count++;
    }
    return count;
}

int Sum(int* s, const int size)
{
    int S = 0;
    for (int i = 0; i < size; i++)
    {
        if (!(s[i] % 2 != 0 && i % 3 == 0))
            S += s[i];
    }
    return S;
}

void Zero(int* s, const int size)
{
    for (int i = 0; i < size; i++)
    {
        if (!(s[i] % 2 != 0 && i % 3 == 0))
            s[i] = 0;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    const int n = 23;
    int s[n];

    int Low = 4;
    int High = 16;

    Create(s, n, Low, High);
    Print(s, n);

    int count = Count(s, n);
    int sum = Sum(s, n);

    Zero(s, n);

    cout << "Count = " << count << endl;
    cout << "Sum   = " << sum << endl;

    Print(s, n);

    return 0;
}
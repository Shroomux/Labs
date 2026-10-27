#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* s, const int size, const int Low, const int High, int i)
{
    s[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(s, size, Low, High, i + 1);
}

void Print(int* s, const int size, int i)
{
    cout << setw(4) << s[i];
    if (i < size - 1)
        Print(s, size, i + 1);
    else
        cout << endl;
}

int Count(int* s, const int size, int i)
{
    if (i < size)
    {
        if (!(s[i] % 2 != 0 && i % 3 == 0))
            return 1 + Count(s, size, i + 1);
        else
            return Count(s, size, i + 1);
    }
    else
        return 0;
}

int Sum(int* s, const int size, int i)
{
    if (i < size)
    {
        if (!(s[i] % 2 != 0 && i % 3 == 0))
            return s[i] + Sum(s, size, i + 1);
        else
            return Sum(s, size, i + 1);
    }
    else
        return 0;
}

void Zero(int* s, const int size, int i)
{
    if (!(s[i] % 2 != 0 && i % 3 == 0))
        s[i] = 0;
    if (i < size - 1)
        Zero(s, size, i + 1);
}

int main()
{
    srand((unsigned)time(NULL));

    const int n = 23;
    int s[n];

    int Low = 4;
    int High = 16;

    Create(s, n, Low, High, 0);
    Print(s, n, 0);

    int count = Count(s, n, 0);
    int sum = Sum(s, n, 0);

    Zero(s, n, 0);

    cout << "Count = " << count << endl;
    cout << "Sum   = " << sum << endl;

    Print(s, n, 0);

    return 0;
}
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(double* a, const int size, const double Low, const double High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + (High - Low) * rand() / RAND_MAX;
}

void Print(double* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(8) << setprecision(2) << fixed << a[i];
    cout << endl;
}

double SumNegative(double* a, const int size)
{
    double S = 0.0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] < 0)
            S += a[i];
    }
    return S;
}

int IndexMax(double* a, const int size)
{
    int imax = 0;
    for (int i = 1; i < size; i++)
    {
        if (a[i] > a[imax])
            imax = i;
    }
    return imax;
}

int IndexMin(double* a, const int size)
{
    int imin = 0;
    for (int i = 1; i < size; i++)
    {
        if (a[i] < a[imin])
            imin = i;
    }
    return imin;
}

double ProductBetween(double* a, const int i1, const int i2)
{
    int left = i1;
    int right = i2;
    if (left > right)
    {
        int tmp = left;
        left = right;
        right = tmp;
    }

    if (right - left <= 1)
        return 0.0;

    double P = 1.0;
    for (int i = left + 1; i < right; i++)
        P *= a[i];
    return P;
}

void SortEven(double* a, const int size)
{
    for (int i = 0; i < size; i += 2)
    {
        for (int j = 0; j < size - 2 - i; j += 2)
        {
            if (a[j] > a[j + 2])
            {
                double tmp = a[j];
                a[j] = a[j + 2];
                a[j + 2] = tmp;
            }
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int n;
    do
    {
        cout << "n = ";
        cin >> n;
    } while (n < 2);

    double* a = new double[n];

    double Low = -10.0;
    double High = 10.0;

    Create(a, n, Low, High);

    cout << "a = " << endl;
    Print(a, n);

    cout << "S = " << SumNegative(a, n) << endl;

    int imax = IndexMax(a, n);
    int imin = IndexMin(a, n);
    cout << "a[max] = a[" << imax << "] = " << a[imax] << endl;
    cout << "a[min] = a[" << imin << "] = " << a[imin] << endl;
    cout << "P = " << ProductBetween(a, imax, imin) << endl;

    SortEven(a, n);

    cout << "a (sorted) = " << endl;
    Print(a, n);

    delete[] a;

    return 0;
}
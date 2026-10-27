#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(double* a, const int size, const double Low, const double High, int i)
{
    a[i] = Low + (High - Low) * rand() / RAND_MAX;
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

void Print(double* a, const int size, int i)
{
    cout << setw(8) << setprecision(2) << fixed << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

double SumNegative(double* a, const int size, int i)
{
    if (i < size)
    {
        if (a[i] < 0)
            return a[i] + SumNegative(a, size, i + 1);
        else
            return SumNegative(a, size, i + 1);
    }
    return 0.0;
}

int IndexMax(double* a, const int size, int i, int imax)
{
    if (a[i] > a[imax])
        imax = i;
    if (i < size - 1)
        return IndexMax(a, size, i + 1, imax);
    else
        return imax;
}

int IndexMin(double* a, const int size, int i, int imin)
{
    if (a[i] < a[imin])
        imin = i;
    if (i < size - 1)
        return IndexMin(a, size, i + 1, imin);
    else
        return imin;
}

double ProductBetween(double* a, const int left, const int right, int i)
{
    if (right - left <= 1)
        return 0.0;

    if (i < right)
        return a[i] * ProductBetween(a, left, right, i + 1);
    else
        return 1.0;
}

void SortEven(double* a, const int size, int i, int j)
{
    if (size <= 2)
        return;

    if (a[j] > a[j + 2])
    {
        double tmp = a[j];
        a[j] = a[j + 2];
        a[j + 2] = tmp;
    }

    if (j + 2 < size - 2 - i)
        SortEven(a, size, i, j + 2);
    else if (i + 2 < size - 2)
        SortEven(a, size, i + 2, 0);
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

    Create(a, n, Low, High, 0);

    cout << "a = " << endl;
    Print(a, n, 0);

    cout << "S = " << SumNegative(a, n, 0) << endl;

    int imax = IndexMax(a, n, 1, 0);
    int imin = IndexMin(a, n, 1, 0);
    cout << "a[max] = a[" << imax << "] = " << a[imax] << endl;
    cout << "a[min] = a[" << imin << "] = " << a[imin] << endl;

    int left = (imin < imax) ? imin : imax;
    int right = (imin < imax) ? imax : imin;

    cout << "P = " << ProductBetween(a, left, right, left + 1) << endl;

    SortEven(a, n, 0, 0);

    cout << "a (sorted) = " << endl;
    Print(a, n, 0);

    delete[] a;

    return 0;
}
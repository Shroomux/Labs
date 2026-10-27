#include <iostream>
#include <iomanip>

using namespace std;

void Print(int* a, const int size, int i)
{
    cout << setw(5) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

template <typename T>
void Print(T* a, const int size, int i)
{
    cout << setw(6) << a[i];
    if (i < size - 1)
        Print<T>(a, size, i + 1);
    else
        cout << endl;
}

bool IsSorted(int* a, const int size, int i)
{
    if (a[i] > a[i + 1])
        return false;

    if (i < size - 2)
        return IsSorted(a, size, i + 1);
    else
        return true;
}

template <typename T>
bool IsSorted(T* a, const int size, int i)
{
    if (a[i] > a[i + 1])
        return false;

    if (i < size - 2)
        return IsSorted<T>(a, size, i + 1);
    else
        return true;
}

int main()
{
    const int n = 5;

    int a[n] = { 2, 4, 4, 7, 9 };
    cout << "Array a:" << endl;
    Print(a, n, 0);

    cout << "IsSorted(a, n) = " << (IsSorted(a, n, 0) ? "true" : "false") << endl;
    cout << "IsSorted<int>(a, n) = " << (IsSorted<int>(a, n, 0) ? "true" : "false") << endl;

    cout << endl;

    double b[n] = { 1.2, 3.4, 2.1, 5.5, 8.0 };
    cout << "Array b:" << endl;
    Print<double>(b, n, 0);

    cout << "IsSorted<double>(b, n) = " << (IsSorted<double>(b, n, 0) ? "true" : "false") << endl;

    return 0;
}
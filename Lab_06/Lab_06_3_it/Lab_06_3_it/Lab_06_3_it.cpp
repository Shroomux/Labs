#include <iostream>
#include <iomanip>

using namespace std;

void Print(int* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(5) << a[i];
    cout << endl;
}

template <typename T>
void Print(T* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(6) << a[i];
    cout << endl;
}

bool IsSorted(int* a, const int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (a[i] > a[i + 1])
            return false;
    }
    return true;
}

template <typename T>
bool IsSorted(T* a, const int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (a[i] > a[i + 1])
            return false;
    }
    return true;
}

int main()
{
    const int n = 5;

    int a[n] = { 2, 4, 4, 7, 9 };
    cout << "Array a (int):" << endl;
    Print(a, n);

    bool res1 = IsSorted(a, n);
    cout << "IsSorted(a, n)      = " << (res1 ? "true" : "false") << endl;

    bool res2 = IsSorted<int>(a, n);
    cout << "IsSorted<int>(a, n) = " << (res2 ? "true" : "false") << endl;

    cout << endl;

    double b[n] = { 1.2, 3.4, 2.1, 5.5, 8.0 };
    cout << "Array b (double):" << endl;
    Print<double>(b, n);

    bool res3 = IsSorted<double>(b, n);
    cout << "IsSorted<double>(b, n) = " << (res3 ? "true" : "false") << endl;

    return 0;
}
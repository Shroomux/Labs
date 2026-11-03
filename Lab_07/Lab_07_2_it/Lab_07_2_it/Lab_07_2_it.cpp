#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int n, const int Low, const int High);
void Print(int** a, const int n);
int SearchMaxCol(int** a, const int rowNo, const int n);
void PlaceMaxOnDiagonal(int** a, const int n);

int main()
{
    srand((unsigned)time(NULL));

    int n;
    cout << "n = ";
    cin >> n;

    const int Low = -10;
    const int High = 25;

    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    Create(a, n, Low, High);
    cout << "Initial matrix:";
    Print(a, n);

    PlaceMaxOnDiagonal(a, n);

    cout << "Modified matrix:";
    Print(a, n);

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int n, const int Low, const int High)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(5) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

// Пошук індексу стовпця з максимальним значенням у вказаному рядку
int SearchMaxCol(int** a, const int rowNo, const int n)
{
    int maxCol = 0;
    for (int j = 1; j < n; j++)
    {
        if (a[rowNo][j] > a[rowNo][maxCol])
            maxCol = j;
    }
    return maxCol;
}

// Перестановка елементів парних рядків так, щоб максимум опинився на діагоналі
void PlaceMaxOnDiagonal(int** a, const int n)
{
    for (int i = 0; i < n; i += 2) // Лише парні рядки: 0, 2, 4, ...
    {
        int maxCol = SearchMaxCol(a, i, n);
        if (maxCol != i)
        {
            int tmp = a[i][i];
            a[i][i] = a[i][maxCol];
            a[i][maxCol] = tmp;
        }
    }
}
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void CreateRow(int** a, const int rowNo, const int n, const int Low, const int High, int colNo);
void CreateRows(int** a, const int n, const int Low, const int High, int rowNo);

void PrintRow(int** a, const int rowNo, const int n, int colNo);
void PrintRows(int** a, const int n, int rowNo);

int SearchMaxCol(int** a, const int rowNo, const int n, int colNo, int maxCol);
void PlaceMaxOnDiagonal(int** a, const int n, int rowNo);

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

    CreateRows(a, n, Low, High, 0);
    cout << "Initial matrix:" << endl;
    PrintRows(a, n, 0);

    PlaceMaxOnDiagonal(a, n, 0);

    cout << "Modified matrix:" << endl;
    PrintRows(a, n, 0);

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void CreateRow(int** a, const int rowNo, const int n, const int Low, const int High, int colNo)
{
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < n - 1)
        CreateRow(a, rowNo, n, Low, High, colNo + 1);
}

void CreateRows(int** a, const int n, const int Low, const int High, int rowNo)
{
    CreateRow(a, rowNo, n, Low, High, 0);
    if (rowNo < n - 1)
        CreateRows(a, n, Low, High, rowNo + 1);
}

void PrintRow(int** a, const int rowNo, const int n, int colNo)
{
    cout << setw(5) << a[rowNo][colNo];
    if (colNo < n - 1)
        PrintRow(a, rowNo, n, colNo + 1);
    else
        cout << endl;
}

void PrintRows(int** a, const int n, int rowNo)
{
    PrintRow(a, rowNo, n, 0);
    if (rowNo < n - 1)
        PrintRows(a, n, rowNo + 1);
    else
        cout << endl;
}

// Рекурсивний пошук індексу стовпця з максимальним значенням у рядку
int SearchMaxCol(int** a, const int rowNo, const int n, int colNo, int maxCol)
{
    if (a[rowNo][colNo] > a[rowNo][maxCol])
        maxCol = colNo;

    if (colNo < n - 1)
        return SearchMaxCol(a, rowNo, n, colNo + 1, maxCol);
    else
        return maxCol;
}

// Рекурсивний обхід рядків матриці
void PlaceMaxOnDiagonal(int** a, const int n, int rowNo)
{
    if (rowNo % 2 == 0) // Перевірка парності рядка
    {
        int maxCol = SearchMaxCol(a, rowNo, n, 1, 0);
        if (maxCol != rowNo)
        {
            int tmp = a[rowNo][rowNo];
            a[rowNo][rowNo] = a[rowNo][maxCol];
            a[rowNo][maxCol] = tmp;
        }
    }

    if (rowNo < n - 1)
        PlaceMaxOnDiagonal(a, n, rowNo + 1);
}
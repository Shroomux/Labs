#include <iostream>
#include <iomanip>
#include <Windows.h>
#include "student.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "Введіть кількість студентів N: ";
    cin >> N;

    Student* p = new Student[N];

    Create(p, N);
    Print(p, N);

    // Завдання 1
    PrintExcellentStudents(p, N);

    // Завдання 2
    double proc = CalcPercentAvgAbove(p, N, 4.5);
    cout << "Процент студентів із середнім балом > 4.5: "
        << fixed << setprecision(2) << proc << "%" << endl;

    delete[] p;
    return 0;
}
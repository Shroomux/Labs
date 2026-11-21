#include <iostream>
#include <Windows.h>
#include "student.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N = ReadInt("Введіть кількість студентів N (1-100): ", 1, 100);
    Student* p = new Student[N]{};
    bool isCreated = false;

    int ispec;
    Spec spec;
    unsigned kurs;
    string prizv;
    int found;
    int* I = nullptr;

    int menuItem;
    do
    {
        cout << endl;
        cout << "Виберіть дію:" << endl << endl;
        cout << " [1] - введення даних з клавіатури" << endl;
        cout << " [2] - вивід даних на екран" << endl;
        cout << " [3] - фізичне впорядкування даних" << endl;
        cout << " [4] - індексне впорядкування та вивід даних" << endl;
        cout << " [5] - бінарний пошук студента" << endl << endl;
        cout << " [0] - вихід та завершення роботи програми" << endl << endl;

        menuItem = ReadInt("Введіть значення: ", 0, 5);
        cout << endl;

        switch (menuItem)
        {
        case 1:
            Create(p, N);
            isCreated = true;
            break;

        case 2:
            if (!isCreated)
                cout << "Спочатку введіть дані (пункт [1])!" << endl;
            else
                Print(p, N);
            break;

        case 3:
            if (!isCreated)
                cout << "Спочатку введіть дані (пункт [1])!" << endl;
            else
            {
                Sort(p, N);
                cout << "Масив фізично впорядковано." << endl;
            }
            break;

        case 4:
            if (!isCreated)
                cout << "Спочатку введіть дані (пункт [1])!" << endl;
            else
            {
                I = IndexSort(p, N);
                PrintIndexSorted(p, I, N);
                delete[] I;
                I = nullptr;
            }
            break;

        case 5:
            if (!isCreated)
            {
                cout << "Спочатку введіть дані (пункт [1])!" << endl;
                break;
            }
            cout << "Введіть ключі пошуку:" << endl;
            ispec = ReadInt("  спеціальність (0 - КН, 1 - Інф, 2 - МЕ, 3 - ФІ, 4 - ТН): ", 0, 4);
            spec = (Spec)ispec;
            kurs = (unsigned)ReadInt("  курс (1-6): ", 1, 6);

            cin.ignore(1000, '\n');
            do
            {
                cout << "  прізвище: ";
                getline(cin, prizv);
                if (prizv.empty())
                    cout << "Помилка! Прізвище не може бути порожнім." << endl;
            } while (prizv.empty());

            cout << endl;
            found = BinSearch(p, N, prizv, spec, kurs);
            if (found != -1)
                cout << "Знайдено студента в позиції " << found + 1 << endl;
            else
                cout << "Шуканого студента не знайдено (переконайтеся, що масив впорядковано пунктом [3])." << endl;
            break;

        case 0:
            break;
        }
    } while (menuItem != 0);

    delete[] p;
    return 0;
}
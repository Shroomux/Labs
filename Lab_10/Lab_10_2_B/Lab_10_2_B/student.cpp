#include "student.h"
#include <iostream>
#include <iomanip>

std::string SpecToStr(Spec s)
{
    switch (s)
    {
    case KN:  return "Комп'ютерні науки";
    case INF: return "Інформатика";
    case ME:  return "Математика та економіка";
    case FI:  return "Фізика та інформатика";
    case TN:  return "Трудове навчання";
    default:  return "";
    }
}

int ReadInt(const char* prompt, int minVal, int maxVal)
{
    int value;
    while (true)
    {
        std::cout << prompt;
        std::cin >> value;
        if (!std::cin.fail() && value >= minVal && value <= maxVal)
            return value;

        std::cout << "Помилка вводу! Введіть ціле число від "
            << minVal << " до " << maxVal << "." << std::endl;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
}

void Create(Student* p, const int N)
{
    for (int i = 0; i < N; i++)
    {
        std::cout << "Студент № " << i + 1 << ":" << std::endl;
        std::cin.ignore(1000, '\n');

        do
        {
            std::cout << "  прізвище: ";
            std::getline(std::cin, p[i].prizv);
            if (p[i].prizv.empty())
                std::cout << "Помилка! Прізвище не може бути порожнім." << std::endl;
        } while (p[i].prizv.empty());

        p[i].kurs = (unsigned)ReadInt("  курс (1-6): ", 1, 6);

        int ispec = ReadInt(
            "  спеціальність (0 - КН, 1 - Інф, 2 - МЕ, 3 - ФІ, 4 - ТН): ", 0, 4);
        p[i].spec = (Spec)ispec;

        p[i].fiz = ReadInt("  оцінка з фізики (1-5): ", 1, 5);
        p[i].mat = ReadInt("  оцінка з математики (1-5): ", 1, 5);

        switch (p[i].spec)
        {
        case KN:
            p[i].prog = ReadInt("  оцінка з програмування (1-5): ", 1, 5);
            break;
        case INF:
            p[i].chysMet = ReadInt("  оцінка з чисельних методів (1-5): ", 1, 5);
            break;
        case ME:
        case FI:
        case TN:
            p[i].pedag = ReadInt("  оцінка з педагогіки (1-5): ", 1, 5);
            break;
        }
        std::cout << std::endl;
    }
}

void Print(const Student* p, const int N)
{
    std::cout << "Таблиця успішності студентів:" << std::endl;
    std::cout << "=====================================================================================================" << std::endl;
    std::cout << "| " << std::setw(2) << std::left << "№" << " "
        << "| " << std::setw(12) << std::left << "Прізвище" << " "
        << "| " << std::setw(4) << std::left << "Курс" << " "
        << "| " << std::setw(23) << std::left << "Спеціальність" << " "
        << "| " << std::setw(6) << std::left << "Фізика" << " "
        << "| " << std::setw(6) << std::left << "Матем." << " "
        << "| " << std::setw(6) << std::left << "Прогр." << " "
        << "| " << std::setw(8) << std::left << "Чис.мет." << " "
        << "| " << std::setw(6) << std::left << "Педаг." << " |" << std::endl;
    std::cout << "-----------------------------------------------------------------------------------------------------" << std::endl;

    for (int i = 0; i < N; i++)
    {
        std::cout << "| " << std::setw(2) << std::right << i + 1 << " "
            << "| " << std::setw(12) << std::left << p[i].prizv << " "
            << "| " << std::setw(4) << std::right << p[i].kurs << " "
            << "| " << std::setw(23) << std::left << SpecToStr(p[i].spec) << " "
            << "| " << std::setw(6) << std::right << p[i].fiz << " "
            << "| " << std::setw(6) << std::right << p[i].mat << " ";

        switch (p[i].spec)
        {
        case KN:
            std::cout << "| " << std::setw(6) << std::right << p[i].prog << " "
                << "| " << std::setw(8) << " " << " "
                << "| " << std::setw(6) << " " << " |" << std::endl;
            break;
        case INF:
            std::cout << "| " << std::setw(6) << " " << " "
                << "| " << std::setw(8) << std::right << p[i].chysMet << " "
                << "| " << std::setw(6) << " " << " |" << std::endl;
            break;
        case ME:
        case FI:
        case TN:
            std::cout << "| " << std::setw(6) << " " << " "
                << "| " << std::setw(8) << " " << " "
                << "| " << std::setw(6) << std::right << p[i].pedag << " |" << std::endl;
            break;
        }
    }
    std::cout << "=====================================================================================================" << std::endl;
    std::cout << std::endl;
}

void Sort(Student* p, const int N)
{
    Student tmp;
    for (int i0 = 0; i0 < N - 1; i0++) // метод "бульбашки"
    {
        for (int i1 = 0; i1 < N - i0 - 1; i1++)
        {
            std::string s1 = SpecToStr(p[i1].spec);
            std::string s2 = SpecToStr(p[i1 + 1].spec);

            if ((s1 > s2) ||
                (s1 == s2 && p[i1].kurs > p[i1 + 1].kurs) ||
                (s1 == s2 && p[i1].kurs == p[i1 + 1].kurs && p[i1].prizv > p[i1 + 1].prizv))
            {
                tmp = p[i1];
                p[i1] = p[i1 + 1];
                p[i1 + 1] = tmp;
            }
        }
    }
}

int* IndexSort(const Student* p, const int N)
{
    int* I = new int[N];
    for (int i = 0; i < N; i++)
        I[i] = i;

    int i, j, value;
    for (i = 1; i < N; i++) // метод вставки
    {
        value = I[i];
        std::string sVal = SpecToStr(p[value].spec);

        for (j = i - 1; j >= 0; j--)
        {
            std::string sJ = SpecToStr(p[I[j]].spec);
            if ((sJ > sVal) ||
                (sJ == sVal && p[I[j]].kurs > p[value].kurs) ||
                (sJ == sVal && p[I[j]].kurs == p[value].kurs && p[I[j]].prizv > p[value].prizv))
            {
                I[j + 1] = I[j];
            }
            else
                break;
        }
        I[j + 1] = value;
    }
    return I;
}

void PrintIndexSorted(const Student* p, const int* I, const int N)
{
    std::cout << "Індексно впорядкована таблиця студентів:" << std::endl;
    std::cout << "=====================================================================================================" << std::endl;
    std::cout << "| " << std::setw(2) << std::left << "№" << " "
        << "| " << std::setw(12) << std::left << "Прізвище" << " "
        << "| " << std::setw(4) << std::left << "Курс" << " "
        << "| " << std::setw(23) << std::left << "Спеціальність" << " "
        << "| " << std::setw(6) << std::left << "Фізика" << " "
        << "| " << std::setw(6) << std::left << "Матем." << " "
        << "| " << std::setw(6) << std::left << "Прогр." << " "
        << "| " << std::setw(8) << std::left << "Чис.мет." << " "
        << "| " << std::setw(6) << std::left << "Педаг." << " |" << std::endl;
    std::cout << "-----------------------------------------------------------------------------------------------------" << std::endl;

    for (int i = 0; i < N; i++)
    {
        std::cout << "| " << std::setw(2) << std::right << i + 1 << " "
            << "| " << std::setw(12) << std::left << p[I[i]].prizv << " "
            << "| " << std::setw(4) << std::right << p[I[i]].kurs << " "
            << "| " << std::setw(23) << std::left << SpecToStr(p[I[i]].spec) << " "
            << "| " << std::setw(6) << std::right << p[I[i]].fiz << " "
            << "| " << std::setw(6) << std::right << p[I[i]].mat << " ";

        switch (p[I[i]].spec)
        {
        case KN:
            std::cout << "| " << std::setw(6) << std::right << p[I[i]].prog << " "
                << "| " << std::setw(8) << " " << " "
                << "| " << std::setw(6) << " " << " |" << std::endl;
            break;
        case INF:
            std::cout << "| " << std::setw(6) << " " << " "
                << "| " << std::setw(8) << std::right << p[I[i]].chysMet << " "
                << "| " << std::setw(6) << " " << " |" << std::endl;
            break;
        case ME:
        case FI:
        case TN:
            std::cout << "| " << std::setw(6) << " " << " "
                << "| " << std::setw(8) << " " << " "
                << "| " << std::setw(6) << std::right << p[I[i]].pedag << " |" << std::endl;
            break;
        }
    }
    std::cout << "=====================================================================================================" << std::endl;
    std::cout << std::endl;
}

int BinSearch(const Student* p, const int N, const std::string& prizv, const Spec spec, const unsigned kurs)
{
    if (N <= 0)
        return -1;

    int L = 0, R = N - 1, m;
    std::string targetSpec = SpecToStr(spec);

    do
    {
        m = (L + R) / 2;
        if (p[m].prizv == prizv && p[m].spec == spec && p[m].kurs == kurs)
            return m;

        std::string midSpec = SpecToStr(p[m].spec);
        if ((midSpec < targetSpec) ||
            (midSpec == targetSpec && p[m].kurs < kurs) ||
            (midSpec == targetSpec && p[m].kurs == kurs && p[m].prizv < prizv))
        {
            L = m + 1;
        }
        else
        {
            R = m - 1;
        }
    } while (L <= R);

    return -1;
}
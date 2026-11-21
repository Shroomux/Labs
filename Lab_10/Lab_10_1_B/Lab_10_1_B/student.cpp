#include "student.h"
#include <iostream>
#include <iomanip>

void Create(Student* p, const int N)
{
    int spec;
    for (int i = 0; i < N; i++)
    {
        std::cout << "Студент № " << i + 1 << ":" << std::endl;
        std::cin.ignore(1000, '\n');

        std::cout << "  прізвище: ";
        std::getline(std::cin, p[i].prizv);

        std::cout << "  курс: ";
        std::cin >> p[i].kurs;

        std::cout << "  спеціальність (0 - КН, 1 - Інф, 2 - МЕ, 3 - ФІ, 4 - ТН): ";
        std::cin >> spec;
        p[i].spec = (Spec)spec;

        std::cout << "  оцінка з фізики: ";
        std::cin >> p[i].fiz;

        std::cout << "  оцінка з математики: ";
        std::cin >> p[i].mat;

        switch (p[i].spec)
        {
        case KN:
            std::cout << "  оцінка з програмування: ";
            std::cin >> p[i].prog;
            break;
        case INF:
            std::cout << "  оцінка з чисельних методів: ";
            std::cin >> p[i].chysMet;
            break;
        case ME:
        case FI:
        case TN:
            std::cout << "  оцінка з педагогіки: ";
            std::cin >> p[i].pedag;
            break;
        }
        std::cout << std::endl;
    }
}

void Print(const Student* p, const int N)
{
    const std::string specStr[] = {
        "Комп'ютерні науки",
        "Інформатика",
        "Математика та економіка",
        "Фізика та інформатика",
        "Трудове навчання"
    };

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
            << "| " << std::setw(23) << std::left << specStr[p[i].spec] << " "
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

int GetThirdGrade(const Student& s)
{
    switch (s.spec)
    {
    case KN:  return s.prog;
    case INF: return s.chysMet;
    default:  return s.pedag;
    }
}

bool IsExcellent(const Student& s)
{
    return s.fiz == 5 && s.mat == 5 && GetThirdGrade(s) == 5;
}

void PrintExcellentStudents(const Student* p, const int N)
{
    std::cout << "Студенти, які вчаться на \"відмінно\":" << std::endl;
    int k = 0;
    for (int i = 0; i < N; i++)
    {
        if (IsExcellent(p[i]))
        {
            k++;
            std::cout << std::setw(3) << std::right << k << ". " << p[i].prizv << std::endl;
        }
    }
    if (k == 0)
        std::cout << "  (таких студентів немає)" << std::endl;
    std::cout << std::endl;
}

double CalcAverage(const Student& s)
{
    return (s.fiz + s.mat + GetThirdGrade(s)) / 3.0;
}

double CalcPercentAvgAbove(const Student* p, const int N, const double threshold)
{
    if (N <= 0)
        return 0.0;

    int k = 0;
    for (int i = 0; i < N; i++)
    {
        if (CalcAverage(p[i]) > threshold)
            k++;
    }
    return 100.0 * k / N;
}
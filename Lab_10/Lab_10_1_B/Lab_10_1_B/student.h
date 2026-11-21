#pragma once
#include <string>

enum Spec { KN, INF, ME, FI, TN };

struct Student
{
    std::string prizv;
    unsigned kurs;
    Spec spec;
    int fiz;
    int mat;
    union
    {
        int prog;
        int chysMet;
        int pedag;
    };
};

void Create(Student* p, const int N);
void Print(const Student* p, const int N);

int GetThirdGrade(const Student& s);
bool IsExcellent(const Student& s);
void PrintExcellentStudents(const Student* p, const int N);

double CalcAverage(const Student& s);
double CalcPercentAvgAbove(const Student* p, const int N, const double threshold = 4.5);
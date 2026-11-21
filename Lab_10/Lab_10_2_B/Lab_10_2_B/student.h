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

std::string SpecToStr(Spec s);
int ReadInt(const char* prompt, int minVal, int maxVal);

void Create(Student* p, const int N);
void Print(const Student* p, const int N);

void Sort(Student* p, const int N);
int* IndexSort(const Student* p, const int N);
void PrintIndexSorted(const Student* p, const int* I, const int N);
int BinSearch(const Student* p, const int N, const std::string& prizv, const Spec spec, const unsigned kurs);
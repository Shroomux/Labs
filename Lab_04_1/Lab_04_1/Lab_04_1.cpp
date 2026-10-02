// Lab_04_1.cpp
// Паюк Максим
// Лабораторна робота № 4.1
// Цикли.
// Варіант 21

#include <iostream>
#include <cmath>

using namespace std;

int main()
{

	int N, i;
	double S;

	cout << "N = "; cin >> N;

	S = 0;
	i = 1;
	while (i <= N)
	{
		S += cos(sin(1. * i)) / (1.0 + sin(1. * i) * sin(1. * i));
		i++;
	}
	cout << S << endl;

	S = 0;
	i = 1;
	do {
		S += cos(sin(1. * i)) / (1.0 + sin(1. * i) * sin(1. * i));
		i++;
	} while (i <= N);
	cout << S << endl;

	S = 0;
	for (i = 1; i <= N; i++)
	{
		S += cos(sin(1. * i)) / (1.0 + sin(1. * i) * sin(1. * i));
	}
	cout << S << endl;

	S = 0;
	for (i = N; i >= 1; i--)
	{
		S += cos(sin(1. * i)) / (1.0 + sin(1. * i) * sin(1. * i));
	}
	cout << S << endl;

	return 0;
}
// Lab_04_6.cpp
// Паюк Максим
// Лабораторна робота № 4.6
// Вкладені цикли.
// Варіант 21

#include <iostream>


using namespace std;

int main()
{
	double P, S;
	int i, k;

	P = 1.0;
	i = 1;

	while (i <= 15)
	{
		S = 0.0;
		k = 1;
		while (k <= 20 - i)
		{
			S += (1.0 * i * k) / (i * i + k * k);
			k++;
		}
		P *= S;
		i++;
	}
	cout << "1) while-while:   P = " << P << endl;

	P = 1.0;
	i = 1;

	do {
		S = 0.0;
		k = 1;
		do {
			S += (1.0 * i * k) / (i * i + k * k);
			k++;
		} while (k <= 20 - i);
		P *= S;
		i++;
	} while (i <= 15);
	cout << "2) do-while:      P = " << P << endl;

	P = 1.0;
	i = 1;

	for (i = 1; i <= 15; i++)
	{
		S = 0.0;
		for (k = 1; k <= 20 - i; k++)
		{
			S += (1.0 * i * k) / (i * i + k * k);
		}
		P *= S;
	}
	cout << "3) for (i++, k++): P = " << P << endl;

	P = 1.0;
	i = 1;

	for (i = 15; i >= 1 ; i--)
	{
		S = 0.0;
		for (k = 20 - i; k >= 1; k--)
		{
			S += (1.0 * i * k) / (i * i + k * k);
		}
		P *= S;
	}
	cout << "4) for (i--, k--): P = " << P << endl;

	return 0;
}
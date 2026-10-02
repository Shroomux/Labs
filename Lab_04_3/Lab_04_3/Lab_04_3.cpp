// Lab_04_3.cpp
// Паюк Максим
// Лабораторна робота № 4.3
// Табуляція функції, заданої формулою: функція з параметрами
// Варіант 21

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{

	double a, b, c, x, xp, xk, dx, F;

	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b;
	cout << "c = "; cin >> c;
	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;

	cout << fixed;
	cout << "----------------------" << endl;
	cout << "|" << setw(7) << "x" << " |"
		<< setw(10) << "F" << " |" << endl;
	cout << "----------------------" << endl;
	
	x = xp;
	while (x <= xk)
	{
		if (x < 0 && b != 0)
			F = a * x * x + b;
		else
			if (x > 0 && b == 0)
				F = (x - a) / (x - c);
			else
				F = x / c;

		cout << "|" << setw(7) << setprecision(2) << x
			<< " |" << setw(10) << setprecision(3) << F
			<< " |" << endl;

		x += dx;
	}

	cout << "----------------------" << endl;

	return 0;
}
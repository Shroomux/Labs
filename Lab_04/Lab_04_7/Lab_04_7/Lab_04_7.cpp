// Lab_04_7.cpp
// Паюк Максим
// Лабораторна робота № 4.7
// Обчислення суми ряду Тейлора за допомогою ітераційних циклів та рекурентних співвідношень.
// Варіант 21

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{

	double xp, xk, x, dx, eps, a, R, S;
	int n;

	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;
	cout << "eps = "; cin >> eps;

	cout << fixed;
	cout << "----------------------------------------------" << endl;
	cout << "|" << setw(7) << "x" << " |"
		<< setw(15) << "ln((x+1)/(x-1))" << " |"
		<< setw(10) << "S" << " |"
		<< setw(5) << "n" << " |"
		<< endl;
	cout << "----------------------------------------------" << endl;

	x = xp;
	while (x <= xk)
	{
		n = 0;
		a = 2.0 / x;
		S = a;
		do {
			n++;
			R = (2.0 * n - 1.0) / ((2.0 * n + 1.0) * x * x);
			a *= R;
			S += a;
		} while (fabs(a) >= eps);
		cout << "|" << setw(7) << setprecision(2) << x << " |"
			<< setw(15) << setprecision(5) << log((x + 1.0) / (x - 1.0)) << " |"
			<< setw(10) << setprecision(5) << S << " |"
			<< setw(5) << n << " |"
			<< endl;

		x += dx;
	}
	cout << "----------------------------------------------" << endl;

	return 0;
}
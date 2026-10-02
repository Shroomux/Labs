// Lab_04_2.cpp
// Паюк Максим
// Лабораторна робота № 4.2
// Табуляція функції, заданої формулою: функція однієї змінної.
// Варіант 21

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{

	double x, xp, xk, dx, A, B, y;

	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;

	cout << fixed;
	cout << "----------------------" << endl;
	cout << "|" << setw(7) << "x" << " |"
		<< setw(10) << "y" << " |" << endl;
	cout << "----------------------" << endl;
	
	x = xp;
	while (x <= xk)
	{
		A = 2 + 1.0 / (fabs(1.0 + x));
		if (x < 1)
			B = sqrt(fabs(cos(x)) + 13);
		else
			if (x <= 5)
				B = 3 + 1.0 / tan((4.0 + x) / sqrt(2.0));
			else
				B = 8 + 0.7 * x;

		y = A - B;
		cout << "|" << setw(7) << setprecision(2) << x
			<< " |" << setw(10) << setprecision(3) << y
			<< " |" << endl;
		x += dx;
	}
	cout << "----------------------" << endl;

	return 0;
}
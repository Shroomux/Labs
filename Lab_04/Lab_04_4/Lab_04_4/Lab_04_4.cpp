// Lab_04_4.cpp
// Паюк Максим
// Лабораторна робота № 4.4
// Табуляція функції, заданої графіком.
// Варіант 21

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	double x, R, y, xp, xk, dx;

	cout << "R = "; cin >> R;
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
		if (x <= -6 - R)
			y = 0;
		else
			if (x <= -6)
				y = -sqrt(R * R - (x + 6.0) * (x + 6.0));
			else
				if (x <= -R)
					y = (R * (x + R)) / (6.0 - R);
				else
					if (x <= 0)
						y = sqrt(R * R - x * x);
					else
						if (x <= 3)
							y = R * (1 - x / 3.0);
						else
							y = (R * (x - 3)) / 6.0;

		cout << "|" << setw(7) << setprecision(2) << x
			<< " |" << setw(10) << setprecision(3) << y
			<< " |" << endl;

		x += dx;
	}

	cout << "----------------------" << endl;

	return 0;
}
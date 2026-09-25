// Lab_03_3.cpp
// Паюк Максим
// Лабораторна робота № 3.3
// Розгалуження, задане графіком функції.
// Варіант 21

#include <iostream>
#include <cmath>

using namespace std;

int main()
{

	double x, R, y;

	cout << "R = "; cin >> R;
	cout << "x = "; cin >> x;

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

	cout << endl;
	cout << "y = " << y << endl;

	cin.get();
	return 0;
}
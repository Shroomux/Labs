// Lab_03_4.cpp
// Паюк Максим
// Лабораторна робота № 3.4
// Розгалуження, задане плоскою фігурою.
// Варіант 21

#include <iostream>

using namespace std;

int main()
{

	double x, y, R;

	cout << "R = "; cin >> R;
	cout << "x = "; cin >> x;
	cout << "y = "; cin >> y;

	if ((x * x + y * y <= R * R) && ((x >= 0 && y >= x) || (x <= 0 && y <= x)))
		cout << "yes" << endl;
	else
		cout << "no" << endl;

	cin.get();
	return 0;
}
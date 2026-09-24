// Lab_03_1.cpp
// Паюк Максим
// Лабораторна робота № 3.1
// Розгалуження, задане формулою: функція однієї змінної.
// Варіант 21

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	
	double x, y, A, B;
	
	cout << "x = "; cin >> x;

	A = 2 + 1.0 / (fabs(1.0 + x));

	// спосіб 1: розгалуження в скороченій формі
	if (x < 1)
		B = sqrt(fabs(cos(x)) + 13);
	if (x >= 1 && x <= 5)
		B = 3 + 1.0 / tan((4.0 + x) / sqrt(2.0));
	if (x > 5)
		B = 8 + 0.7 * x;

	y = A - B;

	cout << endl;
	cout << "1) y = " << y << endl;

	// спосіб 2: розгалуження в повній формі
	if (x < 1)
		B = sqrt(fabs(cos(x)) + 13);
	else
		if (x <= 5)
			B = 3 + 1.0 / tan((4.0 + x) / sqrt(2.0));
		else
				B = 8 + 0.7 * x;

	y = A - B;
	
	cout << endl;
	cout << "2) y = " << y << endl;


	cin.get();
	return 0;
}
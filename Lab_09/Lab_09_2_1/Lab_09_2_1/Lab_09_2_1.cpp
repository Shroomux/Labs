// головний файл проєкту – функція main

#include <iostream>
#include "Lab_09_2_1.h"

using namespace std;

int main()
{
	cout << "Lab 9.2.1. Using macros and preprocessing directives" << endl;

	double x, y, w;
	char ch;

	do
	{
		cout << "z = " << Z << " (defined by preprocessor)" << endl;
#if IS_IN_RANGE(Z)
		cout << "Active branch: 0 < z < 5 (max)" << endl;
#else
		cout << "Active branch: z <= 0 or z >= 5 (min)" << endl;
#endif

		cout << "Input x, y: ";
		cin >> x >> y;

		w = calc_w(x, y);
		PRINTR(w); // макрос виведення результату

		cout << "Repeat? y/n: ";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');

	return 0;
}
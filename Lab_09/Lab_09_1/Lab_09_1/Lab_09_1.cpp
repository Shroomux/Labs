// головний файл проєкту – функція main

#include <iostream>
#include <math.h>
#include <iomanip>

#include "dod.h"
#include "sum.h"
#include "var.h"

using namespace std;
using namespace nsDod;
using namespace nsSum;
using namespace nsVar;

int main()
{
	cout << "x_p = "; cin >> x_p;
	cout << "x_k = "; cin >> x_k;
	cout << "dx  = "; cin >> dx;
	cout << "e   = "; cin >> e;
	cout << endl;

	// заголовок та шапка таблиці
	cout << "Table of values for ln((x+1)/(x-1))" << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << "|    x     | ln((x+1)/(x-1)) |        S        |   n   |" << endl;
	cout << "--------------------------------------------------------" << endl;

	cout << fixed;
	x = x_p;
	while (x <= x_k)
	{
		if (fabs(x) > 1)
		{
			sum(); // виклик процедури обчислення суми

			cout << "| " << setw(8) << setprecision(4) << x << " |"
				<< " " << setw(15) << setprecision(6) << log((x + 1) / (x - 1)) << " |"
				<< " " << setw(15) << setprecision(6) << s << " |"
				<< " " << setw(5) << n << " |" << endl;
		}
		else
		{
			cout << "| " << setw(8) << setprecision(4) << x << " |"
				<< " " << setw(41) << "Out of domain (|x| <= 1)" << " |" << endl;
		}

		x += dx;
	}
	cout << "--------------------------------------------------------" << endl;

	cin.get();
	return 0;
}
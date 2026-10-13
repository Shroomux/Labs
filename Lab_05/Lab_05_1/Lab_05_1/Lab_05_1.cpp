// Lab_05_1
#include <iostream>
#include <cmath>

using namespace std;

double g(const double a, const double b, const double c);

int main()
{
	double x, y;

	cout << "x = "; cin >> x;
	cout << "y = "; cin >> y;

	double z = (g(x * x, 1.0, y) - g(y * y, x, 1.0)) / (1.0 + g(sqrt(x), y, 1.0));

	cout << "z = " << z << endl;

	return 0;
}

double g(const double a, const double b, const double c)
{
	return (a * a + sin(b) + 1.0) / (1.0 + c * c);
}
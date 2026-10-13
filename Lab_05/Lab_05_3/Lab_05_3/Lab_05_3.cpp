// Lab_05_3.cpp

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double r(const double x);

int main()
{
    double hp, hk, h, dh, z;
    int n;

    cout << "hp = "; cin >> hp;
    cout << "hk = "; cin >> hk;
    cout << "n = ";  cin >> n;

    dh = (hk - hp) / n;

    cout << fixed;
    cout << "---------------------------------" << endl;
    cout << "|" << setw(10) << "h" << " |"
        << setw(18) << "z" << " |" << endl;
    cout << "---------------------------------" << endl;

    h = hp;
    while (h <= hk)
    {
        double r1 = r(1.0 + h * h - 2.0 * h);
        double r_one = r(1.0);
        double r2 = r(1.0 + r(h * h) - 2.0 * r_one * r_one);

        z = r1 + 2.0 * r2;

        cout << "|" << setw(10) << setprecision(2) << h << " |"
            << setw(18) << setprecision(5) << z << " |"
            << endl;

        h += dh;
    }
    cout << "---------------------------------" << endl;

    return 0;
}

double r(const double x)
{
    if (abs(x) >= 1.0)
    {
        return (1.0 - sin(x) * sin(x)) / exp(x);
    }
    else
    {
        double S = 0.0;
        double a = x;
        S = a;

        for (int j = 1; j <= 7; ++j)
        {
            double R = x / (2.0 * j * (2.0 * j + 1.0));
            a *= R;
            S += a;
        }

        return S / (1.0 + x);
    }
}
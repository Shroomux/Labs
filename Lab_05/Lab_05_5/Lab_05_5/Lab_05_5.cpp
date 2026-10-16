// Lab_05_5.cpp

#include <iostream>

using namespace std;

int f(const int m, const int a, const int c, const int level, int& depth)
{
    if (level > depth)
        depth = level;
    cout << "level = " << level << endl;

    int g = ((a - m + c) % 10 + 10) % 10;
    if (m >= 0 && m <= 9)
        return m;
    else
        return g * f(m - 1 - g, a, c, level + 1, depth) + m;
        
}

int main()
{
    int m, a, c;
    cout << "m = "; cin >> m;
    cout << "a = "; cin >> a;
    cout << "c = "; cin >> c;
    int depth = 0;
    int res = f(m, a, c, 1, depth);
    cout << "f(m) = " << res << endl;
    cout << "depth = " << depth << endl;
}

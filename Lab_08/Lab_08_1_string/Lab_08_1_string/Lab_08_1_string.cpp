#include <iostream>
#include <string>

using namespace std;

// Перевірка наявності підрядків "no" або "on"
bool Include(const string& s)
{
    return (s.find("no") != string::npos || s.find("on") != string::npos);
}

// Заміна підрядків "no" на "***"
string Change(string& s)
{
    size_t pos = 0;
    while ((pos = s.find("no", pos)) != string::npos)
    {
        s.replace(pos, 2, "***");
        pos += 3; // Пропускаємо додані зірочки
    }
    return s;
}

int main()
{
    string str;

    cout << "Enter string: ";
    getline(cin, str);

    if (Include(str))
        cout << "String contains 'no' or 'on'" << endl;
    else
        cout << "String does NOT contain 'no' or 'on'" << endl;

    string dest = Change(str);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    return 0;
}
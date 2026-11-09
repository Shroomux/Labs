#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

// Перевірка наявності пари "no" або "on"
bool Include(const char* str)
{
    if (str == nullptr)
        return false;

    for (int i = 0; str[i] != '\0' && str[i + 1] != '\0'; i++)
    {
        if ((str[i] == 'n' && str[i + 1] == 'o') ||
            (str[i] == 'o' && str[i + 1] == 'n'))
        {
            return true;
        }
    }
    return false;
}

// Заміна пар "no" на "***"
char* Change(char* str)
{
    if (str == nullptr)
        return nullptr;

    size_t len = strlen(str);
    if (len < 2)
        return str;

    char* tmp = new char[len * 3 / 2 + 1];
    char* t = tmp;
    tmp[0] = '\0';

    size_t i = 0;
    while (i < len && str[i + 1] != '\0')
    {
        if (str[i] == 'n' && str[i + 1] == 'o')
        {
            strcat(t, "***");
            t += 3;
            i += 2;
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';
        }
    }

    while (i < len)
    {
        *t++ = str[i++];
        *t = '\0';
    }
    *t = '\0';

    strcpy(str, tmp);
    return tmp;
}

int main()
{
    // Запас пам'яті
    char str[151];

    cout << "Enter string: ";
    cin.getline(str, 100);

    if (Include(str))
        cout << "String contains 'no' or 'on'" << endl;
    else
        cout << "String does NOT contain 'no' or 'on'" << endl;

    char* dest = Change(str);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    delete[] dest;
    return 0;
}
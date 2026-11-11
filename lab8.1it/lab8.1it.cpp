#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#pragma warning(disable : 4996)

using namespace std;

// Функція пошуку індексу 3-ї коми
int ThirdCommaIndex(const char* str)
{
    int k = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ',')
        {
            k++;
            if (k == 3)
                return i;
        }
    }
    return -1; // повертає -1, якщо ком менше 3
}

// Функція заміни кожної коми парою зірочок "**"
char* Change(char* str)
{
    size_t len = strlen(str);
    // Виділяємо пам'ять із запасом (кожна кома ',' розгортається у 2 символи '**')
    char* tmp = new char[len * 2 + 1];
    char* t = tmp;
    size_t i = 0;

    while (str[i] != '\0')
    {
        if (str[i] == ',')
        {
            *t++ = '*';
            *t++ = '*';
            i++;
        }
        else
        {
            *t++ = str[i++];
        }
    }
    *t = '\0';
    strcpy(str, tmp);
    return tmp;
}

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    int index = ThirdCommaIndex(str);
    if (index != -1)
        cout << "Index of 3rd comma: " << index << endl;
    else
        cout << "String contains less than 3 commas" << endl;

    char* dest = Change(str);
    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    return 0;
}
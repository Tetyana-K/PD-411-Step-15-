//#pragma warning(disable :4996) // якщо хочемо використовувати не дуже безпечні (старіші) функції
#include <iostream>
#include <cstring>

using namespace std;
int main()
{
    const int SIZE = 200;
    char str[SIZE] = "C style  string - Standard function strcpy()...";
    cout << "Str = " << str << endl;
    //cout << str + 1 << endl; // будемо бачити рядок, починаючи з символа з індексом 1
    //cout << str + 2 << endl;  // будемо бачити рядок , починаючи з символа з індексом 2
    //cout << str + 3 << endl; // будемо бачити рядок, починаючи з символа з індексом 3

    char copyStr[SIZE]{}; // 
    //strcpy(copyStr, str ); // копіюємо усі символим рядка str у рядок copyStr
    //strcpy(copyStr, str + 18); //  копіюємо  символи рядка починаючи із 18-го (з індексом 18) символа рядка str у рядок copyStr

    strcpy_s(copyStr, str); // safe, secure function, безпечніша функція
    cout << "Copy of Str = " << copyStr << endl;

    //  str1 + str2 

    strcat_s(copyStr, "!!!! ****"); // add  "!!!! ****" to the end, приєднуємо  рядок "!!!! ****" у хвіст рядка copyStr
    strncat_s(copyStr, "NEW TEXT", 3); // add "NEW TEXT" to the end but only 3 letters
    cout << "Copy of Str after concat = " << copyStr << endl;

    // C++ style string == != > < >=
    // C style
    const int LEN = 20;
    char one[LEN], two[LEN];

    cout << "\nEnter two words : ";
    cin >> one >> two;
    // порівняння рядків
    //int result = strcmp(one, two ); //повертається  0, якщо рядки однакові,   > 0 якщо перший рядок більший другого   one > two,  < 0 якщо  one < two
   // int result = strncmp(one, two, 4 ); // при порівнянні береться доувани не більше чим 4 символи 
    //int result = _stricmp(one, two ); // ignore case of letters при порівнянні ігнорується регістр букв
    int result = _strnicmp(one, two, 4); // ignore case of letters ігнорується регістр букв і порівнюється не більш чим 4 символи
    if (result == 0)
    {
        cout << one << "==" << two << endl;
    }
    else if (result > 0)
    {
        cout << one << ">" << two << endl;
    }
    else
    {
        cout << one << "<" << two << endl;
    }
}



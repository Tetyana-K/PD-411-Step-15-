//#pragma warning(disable :4996) // ���� ������ ��������������� �� ���� ������� (������) �������
#include <iostream>
#include <cstring>

using namespace std;
int main()
{
    const int SIZE = 200;
    char str[SIZE] = "C style  string - Standard function strcpy()...";
    cout << "Str = " << str << endl;
    //cout << str + 1 << endl; // ������ ������ �����, ��������� � ������� � �������� 1
    //cout << str + 2 << endl;  // ������ ������ ����� , ��������� � ������� � �������� 2
    //cout << str + 3 << endl; // ������ ������ �����, ��������� � ������� � �������� 3

    char copyStr[SIZE]{}; // 
    //strcpy(copyStr, str ); // ������� �� �������� ����� str � ����� copyStr
    //strcpy(copyStr, str + 18); //  �������  ������� ����� ��������� �� 18-�� (� �������� 18) ������� ����� str � ����� copyStr

    strcpy_s(copyStr, str); // safe, secure function, ��������� �������
    cout << "Copy of Str = " << copyStr << endl;

    //  str1 + str2 

    strcat_s(copyStr, "!!!! ****"); // add  "!!!! ****" to the end, ��������  ����� "!!!! ****" � ���� ����� copyStr
    strncat_s(copyStr, "NEW TEXT", 3); // add "NEW TEXT" to the end but only 3 letters
    cout << "Copy of Str after concat = " << copyStr << endl;

    // C++ style string == != > < >=
    // C style
    const int LEN = 20;
    char one[LEN], two[LEN];

    cout << "\nEnter two words : ";
    cin >> one >> two;
    // ��������� �����
    //int result = strcmp(one, two ); //�����������  0, ���� ����� �������,   > 0 ���� ������ ����� ������ �������   one > two,  < 0 ����  one < two
   // int result = strncmp(one, two, 4 ); // ��� �������� �������� ������� �� ����� ��� 4 ������� 
    //int result = _stricmp(one, two ); // ignore case of letters ��� �������� ���������� ������ ����
    int result = _strnicmp(one, two, 4); // ignore case of letters ���������� ������ ���� � ����������� �� ���� ��� 4 �������
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



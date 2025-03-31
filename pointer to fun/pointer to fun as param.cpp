// pointer to fun.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cctype>
using namespace std;
using funType = int(int);

void transform(char* str, funType func )
{
	for (size_t i = 0; i <  strlen(str); i++)
	{
		str[i] = func(str[i]);
	}
}
int replaceDigitToDot(int symbol)
{
	if (isdigit(symbol))
		return '.';
	return symbol;
}
int main()
{
    
	char str[] = "Hello 12 friends!";
	transform(str, toupper);
	cout << str << endl;

	transform(str, tolower);
	cout << str << endl;

	transform(str, replaceDigitToDot);
	cout << str << endl;
}


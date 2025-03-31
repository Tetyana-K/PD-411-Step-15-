﻿// pointer to fun.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cctype>
using namespace std;

using funType = int(int); // визначили аліас (інше імя, синонім ) для типу вказівник ана функцію, яка приймає int та повертає int

//void transform(char* str, int func (int))
//{
//	for (size_t i = 0; i < strlen(str); i++)
//	{
//		str[i] = func(str[i]);
//	}
//}

void transform(char* str, funType func)
{
	for (size_t i = 0; i <  strlen(str); i++)
	{
		str[i] = func(str[i]); // для кожного символа рядка викликається функція func() і результат роботи функції (змінений симола) = у поточний символ
	}
}
int replaceDigitToDot(int symbol)
{
	if (isdigit(symbol)) // isdigit (int) - чи символ цифра
		return '.';
	return symbol;
}

int countByCriteria(const int arr[], int size, bool criteria(int))
{
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		if (criteria(arr[i])) // якщо поточний елемент масиву задовільняє критерію, який переданий у функцію
		{
			cout << "\t" << arr[i];
			++counter;
		}
	}
	cout << endl;
	return counter;
}

bool isNegative(int value) //цю функцію потім використаємо як критерій для ф.countByCriteria(arr,7, isNegative)
{
	return value < 0;
}
bool isEven(int value) //цю функцію потім використаємо як критерій для ф.countByCriteria(arr,7, isNegative)
{
	return value % 2 ==  0;
}
int main()
{
    
	char str[] = "Hello 1245 friends!";
	transform(str, toupper); // int toupper(int symbol)  -- станд функція, яка повертає символ у верхньому регістрі 
	cout << str << endl;

	transform(str, tolower);  // int tolower(int symbol)  -- станд функція, яка повертає символ у нижньому регістрі 
	cout << str << endl;

	transform(str, replaceDigitToDot);
	cout << str << endl;

	cout << "____________________\n";
	const int SIZE = 7;
	int arr[SIZE] = { 10, 23, 4, 5, -33, -44, 100 };

	cout << "Count of negative elements : " << countByCriteria(arr, SIZE, isNegative) << endl;
	cout << "Count of even elements : " << countByCriteria(arr, SIZE, isEven) << endl;
	
}

// 1. Визначити функції обчислення суми, різниці, добутку, частки двох дробових чисел. Викликати функції через вказівник функції.
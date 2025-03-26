#include <iostream>
#include "DynArray.h"
using std::cout;
using std::endl;

void printArray(const int* arr, int size) // const int * arr = масив не зможемо міняти 
{
	cout << "Array: ";
	for (int i = 0; i < size; i++)
	{
		cout << "\t" << arr[i];
	}
}

void fillArrayWithRand(int* arr, int size) // int * arr = масив можемо міняти 
{
	static bool firstTime = true;// static has global life time
	if (firstTime) {
		firstTime = false;
		srand(unsigned(time(0)));
	}
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100; // 0.. 99
	}
}

// функція доповнення динамічного масиву новим елементом
void addToEnd(int element, int* & arr, int& size)
{
	++size; // збільшуємо розмір 
	int* tmp = new int[size]; // створення нового дин масиву більшого розміру 
	
	// копіюємо елементи із старого масиву у новий
	for (int i = 0; i < size - 1; i++)
	{
		tmp[i] = arr[i];
	}
	// записуємо нове число у кінець нового масиву
	tmp[size - 1] = element;

	// видаляємо старий масив
	delete[] arr;
	
	// arr = адресу нового доповненого масиву
	arr = tmp;
}
// 1.Створити дин змінні різних числових типів. Знайти середнє арифметичне, результат сер. ар. записати у дробову змінну. Знайти максимальне значення
// 2. Створити динамічний масив. Ввести елементи масиву із клавіатури. Створити новий дин. масив, який буде містити елементи першого масиву, виключаючи останній елемент.


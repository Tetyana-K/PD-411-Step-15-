#include <iostream>
#include "DynArray.h"
using std::cout;
using std::endl;

void printArray(const int* arr, int size)
{
	cout << "Array: ";
	for (int i = 0; i < size; i++)
	{
		cout << "\t" << arr[i];
	}
}

void fillArrayWithRand(int* arr, int size)
{
	static bool firstTime = true;
	if (firstTime) {
		firstTime = false;
		srand(unsigned(time(0)));
	}
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
	}
}

// функція доповнення  динамічного масиву новим елементом, новий елемент додається у хвіст масиву
void addToEnd(int element, int*& arr, int& size)
{
	++size; // збільшили розмір, розмір передаєтья за посиланням, тому зовн. світ буде знати новий розмір
	int* tmp = new int[size]; // створили новий дин масив вже більшого розміру
	
	// копіюємо із старого масиву у новий значення
	for (int i = 0; i < size - 1; i++)
	{
		tmp[i] = arr[i];
	}
	// у кінець нового (розширеного) масиву записуємо нове дане
	tmp[size - 1] = element;

	// видаляємо старий масив (він нам вже не треба)
	delete[] arr;
	// присвоюємо вкказівнику arr адерсу нового розширегого масиву (доповненого новим елементом)
	// arr передаєтья за посиланням, тому зовн. світ буде знати новий вказівник
	arr = tmp;
}

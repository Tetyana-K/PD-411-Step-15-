// Dynamic array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "DynArray.h"
using std::cout;
using std::cin;
int main()
{
	cout << "---------Dynamic array demo-------------\n";
	int size;
	cout << "\nEnter size of array: ";
	cin >> size;

	int* arr = new int [size];
	fillArrayWithRand(arr, size);
	printArray(arr, size);

	int value;
	cout << "\n\nEnter a value for adding: ";
	cin >> value;
	addToEnd(value, arr, size);
	printArray(arr, size);

}


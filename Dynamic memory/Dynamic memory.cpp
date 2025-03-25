// Dynamic memory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	// new int- створили дин. змiнну цілого типу, адресу створеної ділянки присвоїли у  вказівник p,  p ----> Heap : [100]
	int* p = new int{ 100 };
	cout << "Dymanic int var = " << *p << endl;

	double* d = new double;
	cout << "\nEnter double value : ";
	cin >> *d;
	cout << "Dymanic double var = " << *p << endl;

	delete p; // вилучення дин змінної, на яке вказує p
	delete d; // вилучення дин змінної, на яке вказує d

	int size;
	cout << "\n\nEnter size of array: ";
	cin >> size;

	// new int[size]- створили дин. масив  цілого типу, адресу створеного масиву присвоїли у вказівник arr,  p ----> Heap : [0 0 0 0 ... 0]

	int* arr = new int[size] {}; // якщо вказати  {} обнулить масив

	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100; 
		cout << arr[i] << "\t";
	}
	cout << endl;

	delete[] arr; // вилучення дин масиву, на який вказує arr

}



// Dynamic memory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int global = 100; // global and static data

void fun(int a)
{
	// local var - STACK
	int b = ++a * global;
	cout << b << endl;
} // a,b  removed from stack

int main()
{
	// new int- виділяється динамічна ділянка на змінну цілого типу, повертає адресу створеної ділянки, p = адресту ств ділянки
	//,  p ----> Heap : [100]
	int* p = new int{ global };
	cout << "Address of int = " << p << endl;
	cout << "Dymanic int var = " << *p << endl;

	double* d = new double; // створили дин змінну дробового типу
	cout << "\nAddress of double = " << d << endl;
	cout << "\nEnter double value : ";
	cin >> *d;
	cout << "Dymanic double var = " << *p << endl;

	delete p; // видалення динамiчної змінної, на яку вказує вказівник p
	delete d; // видалення динамiчної змінної, на яку вказує вказівник d
	
	cout << "\nPointer d = " << d << endl;
	//cout << "\nPointer d = " << *d << endl; // memory error, run time error


	int size;
	cout << "\n\nEnter size of array: ";
	cin >> size;

	// arr = new int[size],  arr ----> Heap : [0 0 0 0 ... 0]

	int* arr = new int[size] {}; //   {} занулення масиву

	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100; 
		cout << arr[i] << "\t";
	}
	cout << endl;

	delete[] arr; // видалення динамічного масиву, на який вказує вказівник arr

}



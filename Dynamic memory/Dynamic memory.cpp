// Dynamic memory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	// new int- �������� ���. ��i��� ������ ����, ������ �������� ������ �������� �  �������� p,  p ----> Heap : [100]
	int* p = new int{ 100 };
	cout << "Dymanic int var = " << *p << endl;

	double* d = new double;
	cout << "\nEnter double value : ";
	cin >> *d;
	cout << "Dymanic double var = " << *p << endl;

	delete p; // ��������� ��� �����, �� ��� ����� p
	delete d; // ��������� ��� �����, �� ��� ����� d

	int size;
	cout << "\n\nEnter size of array: ";
	cin >> size;

	// new int[size]- �������� ���. �����  ������ ����, ������ ���������� ������ �������� � �������� arr,  p ----> Heap : [0 0 0 0 ... 0]

	int* arr = new int[size] {}; // ���� �������  {} �������� �����

	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100; 
		cout << arr[i] << "\t";
	}
	cout << endl;

	delete[] arr; // ��������� ��� ������, �� ���� ����� arr

}



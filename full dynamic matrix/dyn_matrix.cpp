#include <iostream>
#include "dyn_matrix.h"
using namespace std;

void printMatrix(int** m, int r, int c)
{
	if (m == nullptr)
	{
		cout << "Empty matrix!\n";
		return;
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << m[i][j] << "\t";
		}
		cout << endl;
	}
}

void removeMatrix(int**& m, int r)
{
	for (int i = 0; i < r; i++)
	{
		delete[] m[i]; // вилучаємо кожен рядок у циклі
	}
	delete[] m;  // вилучаємо масив вказівників
	
	m = nullptr;
}

void addRow(int**& m, int& r, int c, int value)
{
	++r; // збільшили кількість рядків + 1
	int** tmp = new int* [r]; // створили маси вказівників на рядки більшого розміру +1

	for (int i = 0; i < r - 1 ; i++)
	{
		tmp[i] = m[i]; // перечипили старі рядки у новий масив вказівників 
	}

	tmp[r - 1] = new int[c]; // створили новий рядок як останній у новій матриці
	for (int j = 0; j < c; j++)
	{
		tmp[r - 1][j] = value; //заповнили новий рядок однаковими значеннями value
	}

	delete[] m;
	m = tmp;
}


// dyn matrix demo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
void printMatrix(int** m, int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << m[i][j] << "\t";
		}
		cout << endl;
	}
}
int main()
{
	const int ROWS = 3;
	int* matrix[ROWS];
	int cols;

	cout << "Enter number of columns : ";
	cin >> cols;

	for (int i = 0; i < ROWS; i++)
	{
		matrix[i] = new int[cols] {};
	}
	matrix[0][0] = 5;
	matrix[1][2] = 7;

	printMatrix(matrix, ROWS, cols);
	
	//remove matrix
	for (int i = 0; i < ROWS; i++)
	{
		delete [] matrix [i] ;
	}
}


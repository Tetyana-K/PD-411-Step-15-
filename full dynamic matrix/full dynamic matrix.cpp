// full dynamic matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include "dyn_matrix.h"

int main()
{
	int rows;
	int cols;

	cout << "Enter number of rows : ";
	cin >> rows;

	cout << "Enter number of columns : ";
	cin >> cols;

	int** matrix = new int* [rows]; //matrix= вказівник на дин матрицю, створили масив вказівників на майбутні рядки


	///////////////////////////////////
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new int[cols] {}; // у циклі створюємо черговий (динамічни1) рядок довжини cols
	}

	matrix[0][0] = 5;
	matrix[1][2] = 7;

	printMatrix(matrix, rows, cols);

	cout << "Add new last row with value " << 1 << endl;
	addRow(matrix, rows, cols, 1);
	printMatrix(matrix, rows, cols);

	//remove matrix
	removeMatrix(matrix, rows);
	printMatrix(matrix, rows, cols);
	//for (int i = 0; i < rows; i++)
	//{
	//	delete[] matrix[i]; // вилучаємо кожен рядок у циклі
	//}
	//delete[] matrix;  // вилучаємо масив вказівників
}
// 1. Знайти суму та добуток трьох числових даних. Виконати через вказівники на вкаазівники.
// 2. Написати функцію створення динамічної матриці за двома розмірами.
// 3. Написати функцію, яка отримує вказівник та дин. матрицю, розміри матриці, деяке значення (value) та додає новий рядок, заповнений value як перший.
// preprocessor C.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Препроцесор - програма, яка працює ДО початку компіляції сpp-програми, виконує ТЕКСТОВІ заміни у коді. 

#include <iostream> // препроцесор вставить вміст файлу у цю точку
using namespace std;


#define SIZE 5 // визначили препроцесорну константу, препроцесор далі по коду позамінює SIZE на 5

#define MAX(a,b) ((a)> (b)? (a): (b)) // визначили макрос з іменем MAX, макрос має два параметри, у точку виклику макроса препроцесор підставить тіло макросу на фактичних параметрах

//#define INTEGER
#define DOUBLE


#define ROWS 2
#define COLS 3

int main()
{
	cout << "SIZE = " << SIZE << endl; // cout << "SIZE = " << 5 << endl;
	int arr[SIZE]{ 10, 20, 33, 50, 101 }; // int arr[5]{ 10, 20, 33, 50, 101 }; 

	int num1 = 12, num2 = 30;
	cout << "MAX = " << MAX(num1, num2) << endl;//  cout << "MAX = " << ((num1)> (num2)? (num1): (num2))  << endl;

#ifdef INTEGER // якщо визначено препроцесорне імя INTEGER, 
	int matrix[ROWS][COLS]{ 1,2,3,4 }; // то створюється матриця з цілих чисел
#elif defined(DOUBLE) // інакше, якщо визначено препроцесорне імя DOUBLE,
	double matrix[ROWS][COLS]{ 1.1,2.2,3.3, 4.4 }; // то створюється матриця з дробових  чисел
#else          //інакше
	char matrix[ROWS][COLS]{ 'a','b','c','d' };// то створюється матриця з символів
#endif
	// Виводимо на екран матрицю, зараз виведе матрицю дробову, бо є #define DOUBLE (#define INTEGER закоментований)
	for (int i =0; i < ROWS; ++i)
	{
		for (int j =0; j < COLS; ++j)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
	/*for (auto& row : matrix)
	{
		for (auto& elem : row)
		{
			cout << elem << "\t";
		}
		cout << endl;
	}*/

}


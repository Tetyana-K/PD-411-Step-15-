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

// ������� ����������  ���������� ������ ����� ���������, ����� ������� �������� � ���� ������
void addToEnd(int element, int*& arr, int& size)
{
	++size; // �������� �����, ����� ��������� �� ����������, ���� ����. ��� ���� ����� ����� �����
	int* tmp = new int[size]; // �������� ����� ��� ����� ��� ������� ������
	
	// ������� �� ������� ������ � ����� ��������
	for (int i = 0; i < size - 1; i++)
	{
		tmp[i] = arr[i];
	}
	// � ����� ������ (�����������) ������ �������� ���� ����
	tmp[size - 1] = element;

	// ��������� ������ ����� (�� ��� ��� �� �����)
	delete[] arr;
	// ���������� ���������� arr ������ ������ ����������� ������ (����������� ����� ���������)
	// arr ��������� �� ����������, ���� ����. ��� ���� ����� ����� ��������
	arr = tmp;
}

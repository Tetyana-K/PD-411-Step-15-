#include <iostream>
#include "DynArray.h"
using std::cout;
using std::endl;

void printArray(const int* arr, int size) // const int * arr = масив не зможемо міняти 
{
	cout << "Array: ";
	for (int i = 0; i < size; i++)
	{
		cout << "\t" << arr[i];
	}
}

void fillArrayWithRand(int* arr, int size) // int * arr = масив можемо міняти 
{
	static bool firstTime = true;// static has global life time
	if (firstTime) {
		firstTime = false;
		srand(unsigned(time(0)));
	}
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100; // 0.. 99
	}
}

// ôóíêö³ÿ äîïîâíåííÿ  äèíàì³÷íîãî ìàñèâó íîâèì åëåìåíòîì, íîâèé åëåìåíò äîäàºòüñÿ ó õâ³ñò ìàñèâó
void addToEnd(int element, int* & arr, int& size)
{
	++size; // çá³ëüøèëè ðîçì³ð, ðîçì³ð ïåðåäàºòüÿ çà ïîñèëàííÿì, òîìó çîâí. ñâ³ò áóäå çíàòè íîâèé ðîçì³ð
	int* tmp = new int[size]; // створення нового дин масиву більшого розміру 
	
	// копіюємо елементи із старого масиву у новий
	for (int i = 0; i < size - 1; i++)
	{
		tmp[i] = arr[i];
	}
	// записуємо нове число у кінець нового масиву
	tmp[size - 1] = element;

	// видаляємо старий масив
	delete[] arr;
	// ïðèñâîþºìî âêêàç³âíèêó arr àäåðñó íîâîãî ðîçøèðåãîãî ìàñèâó (äîïîâíåíîãî íîâèì åëåìåíòîì)
	// arr = адресу нового доповненого масиву
	arr = tmp;
}

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

const int NAME_SIZE = 100;
const int POSITION_SIZE = 50;
const int EMAIL_SIZE = 100;
const int PHONE_SIZE = 20;


struct Employee {
	//char fullName[NAME_SIZE];
	string fullName;
	char position[POSITION_SIZE];
	int age;

	struct Contacts {
		char email[EMAIL_SIZE];
		char phone[PHONE_SIZE];
	};

	Contacts contacts;
};

void printContacts(const Employee::Contacts contacts)
{
	cout << "Email: " << contacts.email << endl;
	cout << "Phone: " << contacts.phone << endl;
}

void printEmployee(const Employee& employee)
{
	cout << "Full Name: " << employee.fullName << endl;
	cout << "Position: " << employee.position << endl;
	cout << "Age: " << employee.age << endl;
	printContacts(employee.contacts);
}

void addEmployee(const Employee& empl, Employee*& company, int & actualSize, int& capacity)
{
	if (actualSize >= capacity)
	{
		cout << "Not enough space!\n";
		return;
	}
	++actualSize;
	Employee* tmp = new Employee[actualSize];
	for (int i = 0; i < actualSize - 1; i++)
	{
		tmp[i] = company[i];
	}
	tmp[actualSize - 1] = empl;

	delete[] company;
	company = tmp;
}
void printCompany(const Employee* company, int actualSize)
{
	for (int i = 0; i < actualSize; i++)
	{
		cout << "\t\tEmployee # " << i + 1 << endl;
		printEmployee(company[i]);
	}

}
int main()
{
	int capacity = 10; // capacity, ємність (максимальне число, скільки виділено памяті) для масиву товарів (нашого магазину)

	int actualSize = 0;
	Employee* company = new Employee[capacity];// nullptr

	Employee emp{ "Daria D.", "QA", 24, {"daria@gmail.com", "0908678565656"} };
	addEmployee(emp, company, actualSize, capacity);
	
	Employee emp2{ "Sergii S.", "BA", 34, {"sergii@gmail.com", "09086788888"} };
	addEmployee(emp2, company, actualSize, capacity);

	printCompany(company, actualSize);

	delete[] company;

}

// Визначити структуру Студент з полями імя студента, ід студента, оцінки (python, html, cplus). Оцінки подати у вигляді окремою структури типу Marks.
//Створити одного-двох студентів,заповнпти дані про них з клавіатури, вивести на екран. Написати для завдання відповідні функції 
/*
	void printMarks(const Marks & marks);
	void intputMarks( Marks & marks);

	void printStudent(const Student & marks);
	void intputStudent( Student & marks);
*/
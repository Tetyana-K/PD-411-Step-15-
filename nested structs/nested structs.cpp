#include <iostream>
#include <fstream>
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
	cout << "\n\nEmail: " << contacts.email << endl;
	cout << "Phone: " << contacts.phone << endl;
}

void printEmployee(const Employee& employee)
{
	cout << "Full Name: " << employee.fullName << endl;
	cout << "Position: " << employee.position << endl;
	cout << "Age: " << employee.age << endl;
	printContacts(employee.contacts);
}
void writeToFileEmployeeReport(const Employee& employee, string path = "employee_report.txt")
{
	ofstream file;
	file.open(path);
	 //if(file) // ok
	if (!file) // not  ok
	{
		cout << "Error file " << path << endl;
		return;
	}
	file << "Full Name: " << employee.fullName << endl;
	file << "Position: " << employee.position << endl;
	file << "Age: " << employee.age << endl;

	file << "Email: " << employee.contacts.email << endl;
	file << "Phone: " << employee.contacts.phone << endl;

}
void writeToFileEmployee(const Employee& employee, string path = "employee.txt")
{
	ofstream file;
	file.open(path);

	if (!file)
	{
		cout << "Error file " << path << endl;
		return;
	}

	file <<  employee.fullName << endl;
	file << employee.position << endl;
	file<<  employee.age << endl;

	file <<employee.contacts.email << endl;
	file <<employee.contacts.phone << endl;

}
void readFromFileEmployee( Employee& employee, string path = "employee.txt")
{
	ifstream file;
	file.open(path);
	
	if (!file) 
	{
		cout << "Error file " << path << endl;
		return;
	}
	getline(file, employee.fullName); // так читаємо рядкок С++ (string) із файлового потоку (якщо хочемо читати кілька слів до \n)
	file.getline( employee.position, POSITION_SIZE); // так читаємо рядкок С (масив символів) із файлового потоку
	file >> employee.age;

	file >> employee.contacts.email;
	file >> employee.contacts.phone;
}

int main() {

	Employee employee;

	//strcpy_s(employee.fullName, "Oleh Nerestiuk");
	employee.fullName = "Oleh Nerestiuk";
	strcpy_s(employee.position, "Developer");
	employee.age = 35;
	strcpy_s(employee.contacts.email, "oleh.nerestiuk@gmail.com");
	strcpy_s(employee.contacts.phone, "+380971234555");


	cout << "Full Name: " << employee.fullName << endl;
	cout << "Position: " << employee.position << endl;
	cout << "Age: " << employee.age << endl;
	/*cout << "Email: " << employee.contacts.email << endl;
	cout << "Phone: " << employee.contacts.phone << endl;*/
	printContacts(employee.contacts);
	

	// ми можемо також створити обєкт Контактів
	//Employee::Contacts contacts = { "noname@some.com", "+xxxxxxxxxxxx" };// employee.contacts;
	Employee::Contacts contacts =  employee.contacts;
	cout << "\n\nEmail: " << contacts.email << endl;
	cout << "Phone: " << contacts.phone << endl;

	writeToFileEmployeeReport(employee, "empl-report.txt");
	writeToFileEmployee(employee, "empl.txt");

	Employee readEmployee;
	readFromFileEmployee(readEmployee, "empl.txt");
	cout << "\n\nRead employee from file\n";
	printEmployee(readEmployee);

	return 0;
}
// 3) printToFile()  4) inputFromFile 
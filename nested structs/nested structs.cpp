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

	return 0;
}

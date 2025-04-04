#include <iostream>
#include <cstring>

using namespace std;

const int NAME_SIZE = 100;
const int POSITION_SIZE = 50;
const int EMAIL_SIZE = 100;
const int PHONE_SIZE = 20;

// Основна структура
struct Employee {
    char fullName[NAME_SIZE];
    char position[POSITION_SIZE];
    int age;

    // Вкладена структура
    struct Contacts {
        char email[EMAIL_SIZE];
        char phone[PHONE_SIZE];
    };

    Contacts contacts; // поле типу вкладеної структури
};

int main() {
    
    Employee employee;

    strcpy_s(employee.fullName, "Oleh Nerestiuk");
    strcpy_s(employee.position, "Developer");
    employee.age = 35;
    strcpy_s(employee.contacts.email, "oleh.nerestiuk@gmail.com");
    strcpy_s(employee.contacts.phone, "+380971234555");

    
    cout << "Full Name: " << employee.fullName << endl;
    cout << "Position: " << employee.position << endl;
    cout << "Age: " << employee.age << endl;
    cout << "Email: " << employee.contacts.email << endl;
    cout << "Phone: " << employee.contacts.phone << endl;
    
    Employee::Contacts contacts = { "noname@some.com", "+xxxxxxxxxxxx" };// employee.contacts;
    cout << "\n\nEmail: " << contacts.email << endl;
    cout << "Phone: " << contacts.phone << endl;

    return 0;
}

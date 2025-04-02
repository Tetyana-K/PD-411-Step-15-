#include <iostream>
using namespace std;

const int SIZE = 20;
struct Dog // опис (визначення) користувацького типу Dog, Dog - зразок,на основі якого можна створювати конкретні обєкти Собак
{
	char nick[SIZE] = "Noname";
	char size[SIZE] = "Unknown";
	int age = 0;
	char color[SIZE] = "Nocolor";

};

// структури у функції по замовчуванню передаються ЗА ЗНАЧЕННЯМ (by value), тобто приходить копія структури

void printDog(const Dog& dog)  // заради ефективності передачі обкиа структури - за посиланням, const -
{
	cout << "\nDog's nick : " << dog.nick << endl;
	cout << "Dog's size: " << dog.size << endl;
	cout << "Dog's age : " << dog.age << endl;
	cout << "Dog's color : " << dog.color << endl;
	cout << endl;
}
void inputDog(Dog& dog) // функція повинна змінювати поля параметра dog,тому передаємо за посиланням (або вказівником)
{
	cout << "Enter nick : ";
	cin >> dog.nick;
	cout << "Enter size : ";
	cin >> dog.size;
	cout << "Enter age : ";
	cin >> dog.age;
	cout << "Enter color : ";
	cin >> dog.color;
}
 Dog olderDog(const Dog& dog1, const Dog& dog2)
{
	 if (dog1.age >= dog2.age)
		 return dog1;
	 return dog2;
}

int main()
{
	Dog dog{ "Jack", "medium" }; // створили екземпляр типу Dog
	dog.age = 2;

	//age = 3; //

	cout << "Dog's nick : " << dog.nick << endl;
	cout << "Dog's size: " << dog.size << endl;
	cout << "Dog's age : " << dog.age << endl;
	cout << "Dog's color : " << dog.color << endl;
	cout << endl;

	Dog dog2; // // створили ще один екземпляр типу Dog

	inputDog(dog2);
	/*cout << "Enter nick : ";
	cin >> dog2.nick;
	cout << "Enter size : ";
	cin >> dog2.size;
	cout << "Enter age : ";
	cin >> dog2.age;
	cout << "Enter color : ";
	cin >> dog2.color;*/

	cout << "Dog's nick : " << dog2.nick << endl;
	cout << "Dog's size: " << dog2.size << endl;
	cout << "Dog's age : " << dog2.age << endl;
	cout << "Dog's color : " << dog2.color << endl;

	// = можна присвоювати обєкти однакових типів структур
	Dog cloneJack = dog; // всі поля (елементи) обєкта dog скопіюютьсяу обєкт cloneJack
	printDog(cloneJack);

	inputDog(cloneJack);

	cout << "\n--------We compared ages of dog and dog2 --------\n";
	Dog older = olderDog(dog, dog2);

	printDog(older);
	// . операція доступу до елемента структури через обєкт 
	// -> операція доступу до елемента структури через вказівник    

	Dog* dog3 = new Dog{ "Bobik", "big", 4, "black" };
	dog3->age = 5; // -> операція доступу до елемента структури через вказівник->
	printDog(*dog3);
}
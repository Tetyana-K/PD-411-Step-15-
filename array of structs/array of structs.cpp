// array of structs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "array of structs.h"
using namespace std;

const int MAX_LEN = 20;

struct Product
{
	char name[MAX_LEN];
	double price;
};
void printProduct(const Product & product);

void printShop(const Product  shop[], int actualSize);

void printProducts(const Product  shop[], int actualSize, const char * name);

void addProduct(Product product, Product shop[], int& actualSize, int maxSize)
{
	if (actualSize >= maxSize)
	{
		cout << "Shop is full!\n";
		return;
	}
	shop[actualSize] = product; // заносимо на місце після останнього Продукту новий продукт product
	++actualSize;
}

int main()
{
	const int MAX_SIZE = 10;

	int actualSize = 3;
	Product shop[MAX_SIZE]
	{
		{"Bread bread", 2.20},
		{"Bread white", 1.80},
		{"Yogurt", 3.10},
		{"Apple juice", 2.77},
	};

	printShop(shop, actualSize);
	cout << endl;

	printProducts(shop, actualSize, "Bread");
	cout << endl;
	Product milk{ "Milk", 2.45 };
	addProduct(milk, shop, actualSize, MAX_SIZE);
	addProduct(milk, shop, actualSize, MAX_SIZE);
	addProduct(milk, shop, actualSize, MAX_SIZE);
	addProduct(milk, shop, actualSize, MAX_SIZE);
	addProduct(milk, shop, actualSize, MAX_SIZE);
	addProduct(milk, shop, actualSize, MAX_SIZE);
	addProduct(milk, shop, actualSize, MAX_SIZE);
	addProduct(milk, shop, actualSize, MAX_SIZE);
	addProduct(milk, shop, actualSize, MAX_SIZE);
	addProduct(milk, shop, actualSize, MAX_SIZE);
	addProduct(milk, shop, actualSize, MAX_SIZE);
	addProduct(milk, shop, actualSize, MAX_SIZE);
	printShop(shop, actualSize);
}

void printProduct(const Product& product)
{
	cout << "Product: '" << product.name << "', price: " << product.price << endl;
}

void printShop(const Product  shop[], int actualSize)
{
	for (int i = 0; i < actualSize; i++)
	{
		cout << "#" << i + 1 << "\t";
		printProduct(shop[i]);
	}
}

void printProducts(const Product shop[], int actualSize, const char* name)
{
	cout << "Products with name like '" << name << "'\n";
	for (int i = 0; i < actualSize; i++)
	{
		//if (_stricmp(name, shop[i].name) == 0) // чи співпадають рядки?
		if (strstr(shop[i].name, name)!=nullptr) // чи name є частинрою назви товару shop[i].name
		{
			printProduct(shop[i]);
		}
	}
}


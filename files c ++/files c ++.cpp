﻿// files c ++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> // input-output stream
#include <fstream> // file stream
using namespace std;
int main()
{
    string fname = "my.txt";
    ofstream fout(fname); // створили обєкт файлового потоку f і повязали цей потік з фізичним файлом
    if (!fout.is_open()) // перевіряємо чи файл відкрився, якщо ні, то виводимо повідомлення про помилкута  виходимо з функції main()
    {
        cout << "Error opening file\n";
        return 0;
    }
    int value = 123;
    fout << "Hello from files!\n";   // пишемо у файл текст  "Hello from files!\n"
    fout <<  value * 2 << endl; // пишемо у файл 123*2, тобто 246

    fout.close(); // закрили файловий потік

    ifstream fin(fname);
    char readText[256];
    int readValue;

    //fin >> readText; // прочитає перше слово
    fin.getline(readText, 100); // прочитає рядок до \n, але не більше як 99 символів
    fin >> readValue; // читаємо ціле у змінну readValue із поточної позиції файлу

    cout << "Read text from file : " << readText << endl;
    cout << "Read value from file : " << readValue << endl;

}



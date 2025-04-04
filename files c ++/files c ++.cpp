// files c ++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> // input-output stream
#include <fstream> // file stream
using namespace std;
int main()
{
    string fname = "my.txt";
    ofstream fout(fname); // створили обєкт файлового потоку f і повязали цей потік з фізичним файлом
    if (!fout.is_open())
    {
        cout << "Error opening file\n";
        return 0;
    }
    int value = 123;
    fout << "Hello from files!\n";
    fout <<  value * 2 << endl;

    fout.close();

    ifstream fin(fname);
    char readText[256];
    int readValue;

    //fin >> readText; // прочитає перше слово
    fin.getline(readText, 100);
    fin >> readValue;

    cout << "Read text from file : " << readText << endl;
    cout << "Read value from file : " << readValue << endl;

}



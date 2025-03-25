#include <iostream>
using namespace std;

int main()
{
    const int SIZE = 200;
    char myStr[SIZE] = "C style  string - Standard function style strcpy(). style ..";
    cout << "Str = " << myStr << endl;

    // searcg func

    char symbol = 't';
    char* p = strchr(myStr, symbol); // search first occurence of symbol in string, return pointer to 
    if (p != nullptr) // nullptr - not found
    {
        cout << "Found symbol first occurence '" << symbol << "' in index " << p - myStr << endl; // 
        // *p = '$';

        p = strrchr(myStr, symbol);// search last occurence of symbol in string, return pointer to 
        cout << "Found symbol last ocuurence'" << symbol << "' in index " << p - myStr << endl; // 
    }
    else
    {
        cout << "Symbol not found\n";
    }

    const int LEN = 20;
    char word[LEN];
    cout << "\nEnter word : ";
    cin >> word;
    p = strstr(myStr, word);
    while (p != nullptr)
    {
        cout << "Found word '" << word << "' in index " << p - myStr << endl; // 
        p = strstr(p + strlen(word), word);

    }

}



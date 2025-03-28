// Pointer to pointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    int* p = new int{ 120 }; // stack  p------> heap:[123]
    cout << " p  = " <<  p << endl; 
    cout << "*p  = " << *p << endl; 
    cout << "address of p  = " << &p << endl; 

    int** p2 = &p; // p2 -----> p
    cout << " p2  = " <<  p2 << endl; 
    
    cout << **p2 << endl;

    cout << "\np[0] = " << p[0] << endl; // arr[i] ------  *(arr + i)
    cout << "\np2[0][0] = " << p2[0][0] << endl; // arr[i] ------  *(arr + i)

    cout << endl;


    int* arr = new int [3] {100, 200, 300};
    cout << arr[0] << "\t"<< *(arr + 0) << endl; // 100
    cout << arr[1] << "\t" << *(arr + 1) << endl; // 200
    cout << arr[2] <<  "\t" << *(arr + 2) << endl;

    delete p;  // delete from heap
    //delete p2; //logic error? because  p2 in stack

}


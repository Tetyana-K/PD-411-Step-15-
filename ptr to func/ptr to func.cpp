// ptr to func.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
using  std::cout;
using  std::swap;

double sqr(double x)
{
    return x * x;
}
double cube(double x)
{
    return sqr(x) * x;
}

double power4(double x)
{
    return sqr(sqr(x));
}


int main()
{
    cout << "Address of sqr : " << sqr << endl;
    cout << "Address of cube : " << cube << endl;
    cout << "Address of power4 : " << power4 << endl << endl;

    double (*ptrFun) (double); // 
    // 4     2  1        3      ptrFun - вказівник на  функцію, яка маж параметри типу double   і повертає double     
    cout << " ptrFun ------> sqr\n";
    ptrFun = sqr;//  ptrFun ------> sqr

    double value;
    cout << "\nEnter double value : ";
    cin >> value; //2
    cout << "PtrFun (" << value << ") = " << ptrFun(value) << endl; // 4  sqr(2)

    cout << "\nptrFun ------> cube\n";
    ptrFun = cube;//  ptrFun ------> cube
    cout << "PtrFun (" << value << ") = " << ptrFun(value) << endl; // 4  sqr(2)

    ptrFun = power4;
    cout << "PtrFun (" << value << ") = " << ptrFun(value) << endl; // 4  sqr(2)
    
    {
        using PtrIntType = int*;
        cout << "\n_______________Using for define alias of type_______________\n";
        int number = 100;
        PtrIntType ptr = &number;
        cout << *ptr << endl; // 100
    }

    using FunPtr = double (*) (double);
    FunPtr ptr2 = sqr;
    cout << "PtrFun 2 (" << value << ") = " << ptr2(value) << endl; // 4  sqr(2)
     
}
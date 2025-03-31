
#include <iostream>
using namespace std;

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
   
    const int SIZE = 3;
    double (*arrFun[SIZE]) (double) = { sqr, cube, power4 };// масив вказівників на функції, які отримують double та повертають double
  //  4        1      2       3
  
    int value;
    cout << "Enter a value : ";
    cin >> value;
    for (int i = 0; i < SIZE; i++)
    {
        cout << i << " func : " << arrFun[i](value) << endl; // i = 0 sqr(value), i = 1 cube(value) 
    }
    cout << endl;
    int choice;
    do {
        cout << "1. Sqr(x)\n2. Cube(x)\n3. Power(x)\n\n";
        cin >> choice;
        if (choice >= 1 and choice <= SIZE)
        {
            cout << "Result = " << arrFun[choice - 1](value) << endl;
        }
        else if (choice == 0)
        {
            cout << "Bye-bye!\n";
            break;
        }
    } while (true);
   /* switch (choice)
    {
    case 1:
        cout << sqr(value) << endl;
    default:
        break;
    }*/
}
#include <iostream>
#include <cmath>
using namespace std;

class Calculator
{
protected:
    int a, b;

public:
    void setCalc(int x, int y)
    {
        a = x;
        b = y;
    }
    void displayCalc()
    {
        cout << "addition : " << a + b << endl;
        cout << "subtraction : " << a - b << endl;
        cout << "multiplication : " << a * b << endl;
        cout << "division : " << a / b << endl;      //some problem in division
    }
};

class ScientificCalculator
{
protected:
    int a, b;

public:
    void setsciCalc(int x, int y)
    {
        a = x;
        b = y;
    }
    void displaysciCalc()
    {
        cout << "tan a : " << tan(a) << endl; //something went wrong
        cout << "sin a : " << sin(a) << endl;
        cout << "log a : " << log(a) << endl;
        cout << "exp a : " << exp(a) << endl;
    }
};

class hybridcalc : public Calculator, public ScientificCalculator
{
};

int main()
{
    hybridcalc z;
    z.setCalc(3, 4);
    z.displayCalc();
    z.setsciCalc(10, 5);
    z.displaysciCalc();
    return 0;
}
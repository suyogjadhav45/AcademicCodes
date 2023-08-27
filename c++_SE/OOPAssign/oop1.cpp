#include <iostream>
using namespace std;

class Complex
{
    int a, b;

public:
    Complex()
    {
        a = 0;
        b = 0;
    }
    Complex(int x)
    {
        a = x;
        b = 0;
    }
    Complex(int x, int y)
    {
        a = x;
        b = y;
    }
    Complex operator+(Complex obj)
    {
        Complex num;
        num.a = a + obj.a;
        num.b = b + obj.b;
        return num;
    }
    Complex operator-(Complex obj)
    {
        Complex num;
        num.a = a - obj.a;
        num.b = b - obj.b;
        return num;
    }
    Complex operator*(Complex obj)
    {
        Complex num;
        num.a = ((a * obj.a) - (b * obj.b));
        num.b = ((a * obj.b) + (b * obj.a));
        return num;
    }

    friend istream &operator>>(istream &input, Complex &obj);

    friend ostream &operator<<(ostream &output, Complex &obj);
};

istream &operator>>(istream &input, Complex &obj)
{
    cout << "Enter Real part of Complex number : " << endl;
    input >> obj.a;
    cout << "Enter Imaginary part of Complex number : " << endl;
    input >> obj.b;
    cout << "Your Complex number is : ";
    return input;
}

ostream &operator<<(ostream &output, Complex &obj)
{
    output << obj.a << "+" << obj.b << "i" << endl;
}

int main()
{
    int choice;

    Complex c1;
    cout << "Enter the First Complex Number" << endl;
    cin >> c1;
    cout << c1 << "\n\n";

    Complex c2;
    cout << "Enter the Second Complex Number" << endl;
    cin >> c2;
    cout << c2 << "\n\n";

    Complex c3;

    while (choice != 4)
    {
        cout << "----------MENU----------" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Substraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice from (1/2/3/4)" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            c3 = c1 + c2;
            cout << "Addition of two Complex Numbers is : " << c3 << endl;
            cout << "\n";
            break;
        }
        case 2:
        {
            c3 = c1 - c2;
            cout << "Substraction of two Complex Numbers is : " << c3 << endl;
            cout << "\n";
            break;
        }
        case 3:
        {
            c3 = c1 * c2;
            cout << "Multiplication of two Complex Numbers is : " << c3 << endl;
            cout << "\n";
            break;
        }
        case 4:
        {
            cout << "Thank you for using this program!!!" << endl;
            cout << "\n";
            break;
        }
        default:
        {
            cout << "Enter valid input";
            cout << "\n";
            break;
        }
        }
    }

    return 0;
}

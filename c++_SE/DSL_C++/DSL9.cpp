#include <iostream>
using namespace std;

const int MAX = 30;
class Stack
{
    char str[MAX];
    int top;

public:
    Stack()
    {
        top = -1;
    }
    void push(char ch);
    char pop();
    //	char getTop();
    bool isEmpty();
    bool isFull();
    void display();
    void check_Expression();
};

bool Stack::isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

bool Stack::isFull()
{
    if (top == MAX - 1)
        return 1;
    else
        return 0;
}

void Stack ::display()
{
    if (isEmpty() == 1)
        cout << "\nStack is empty";
    else
    {
        for (int i = 0; i <= top; i++)
        {
            cout << " " << str[i];
        }
    }
}
void Stack::push(char ch)
{
    if (!isFull())
    {
        top++;
        str[top] = ch;
    }
}

char Stack::pop()
{
    if (!isEmpty())
    {
        char ch = str[top];
        top--;
        return ch;
    }
    else
    {
        return '\0';
    }
}

void Stack::check_Expression()
{
    cout << "\nEnter the Expression -----> ";
    cin>>str;
    char ch;
    bool flag = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            push(str[i]);
        if (str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            ch = pop();
            if ((str[i] == ')' && ch != '(') || (str[i] == ']' && ch != '[') || (str[i] == '}' && ch != '{'))
            {
                //cout << "\nNot parenthesized At " << i << " = " << str[i] << endl;
                flag = 1;
                break;
            }
        }
    }
    if (isEmpty() == 1 && flag == 0)
        cout << "\nYour Expresseion is Well Parenthesized!!!"<<endl;
    else
        cout << "\nYour Expression is Not Well Parenthesized!!!"<<endl;
}

int main()
{

    int choice;
    while (choice != 2)
    {
        cout << "\n-------------MENU--------------" << endl;
        cout << "1) Check the Expression" << endl;
        cout << "2) Exit" << endl;
        cout << "\nEnter your Choice(1/2) -----> ";
        cin >> choice;
        if (choice == 1)
        {
            Stack Expression;
            Expression.check_Expression();
        }
        else{
            break;
        }
    }

    return 0;
}
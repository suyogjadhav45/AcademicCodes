#include <iostream>
#include <string>

using namespace std;

class Node
{
private:
    char data;
    Node *next;

public:
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }

    friend class stack;
};

class stack
{
public:
    Node *top = NULL;

    void push(char value)
    {
        Node *temp = new Node(value);
        temp->next = top;
        top = temp;
    }

    char pop()
    {
        if (top == NULL)
        {
            cout << "Stack is empty...\n";
            return 'O';
        }
        else
        {
            Node *temp = top;
            char value = top->data;
            top = top->next;
            delete (temp);
            return value;
        }
    }

    void display()
    {
        if (top == NULL)
        {
            cout << "Stack is empty...\n";
        }
        else
        {
            Node *temp = top;

            cout << "The stack is: \n | ";
            while (temp != NULL)
            {
                cout << temp->data << " | ";
                temp = temp->next;
            }
        }
    }

    void check()
    {
        string str;
        int i = 0, flag = 1;
        char temp;
        cout << "Enter the string: ";
        cin >> str;

        while (i < str.length())
        {
            if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            {
                push(str[i]);
            }

            if (str[i] == ')' || str[i] == ']' || str[i] == '}')
            {
                temp = pop();
                if (temp == 'O')
                {
                    flag = 0;
                    break;
                }
                else
                {
                    if (temp == '(' && str[i] != ')' || temp == '{' && str[i] != '}' || temp == '[' && str[i] != ']')
                    {
                        flag = 0;
                    }
                }
            }

            i++;
        }

        if (top != NULL)
        {
            flag = 0;
        }

        if (flag == 0)
        {
            cout << "The expression is not properly parathesized...\n";
        }
        else
        {
            cout << "The expression is properly parathesized....\n";
        }
    }
};

int main()
{

    stack obj;
    int choice;

    while (choice != 2)
    {
        cout << "********MENU*********\n";
        cout << "1. Check expression\n2. Exit\n";
        cout << "*********************\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            obj.check();
            break;

        case 2:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Enter a valid value....\n";
            break;
        }
    }

    return 0;
}

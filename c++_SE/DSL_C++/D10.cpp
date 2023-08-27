#include <iostream>
#include <string>
using namespace std;

class Node
{
private:
    char data;
    int num;
    Node *next;

public:
    Node(char x)
    {
        this->data = x;
        next = NULL;
    }
    Node(int y)
    {
        this->num = y;
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
    void push_num(int value)
    {
        Node *temp = new Node(value);
        temp->next = top;
        top = temp;
    }

    char pop()
    {
        if (top == NULL)
        {
            cout << "The stack is empty!" << endl;
            return 'O';
        }
        else
        {

            Node *temp = top;
            char value;
            value = top->data;
            top = top->next;
            delete temp;
            return value;
        }
    }

    int pop_num()
    {
        if (top == NULL)
        {
            cout << "The stack is empty!" << endl;
            return 'O';
        }
        else
        {

            Node *temp = top;
            int value;
            value = top->num;
            top = top->next;
            delete temp;
            return value;
        }
    }

    void display()
    {
        if (top == NULL)
        {
            cout << "The stack is empty!" << endl;
        }
        else
        {
            Node *temp = top;
            cout << "The stack is -> \n |";
            while (temp != NULL)
            {
                cout << temp->data << " |";
                temp = temp->next;
            }
        }
    }

    void display_num()
    {
        if (top == NULL)
        {
            cout << "The stack is empty!" << endl;
        }
        else
        {
            Node *temp = top;
            cout << "\nThe stack is -> \n |";
            while (temp != NULL)
            {
                cout << temp->num << " |";
                temp = temp->next;
            }
        }
    }

    int preference(char value)
    {
        switch (value)
        {
        case '*':
            return 4;
            break;
        case '/':
            return 3;
            break;
        case '+':
            return 2;
            break;
        case '-':
            return 1;
            break;
        case '(':
            return 0;

        default:
            return -1;
            break;
        }
    }

    // bool isoperat(char s)
    // {
    //     switch (s)
    //     {
    //     case '+':
    //         return 1;
    //         break;
    //     case '-':
    //         return 1;
    //         break;
    //     case '*':
    //         return 1;
    //         break;
    //     case '/':
    //         return 1;
    //         break;
    //     default:
    //         return 0;
    //         break;
    //     }
    // }

    // bool isEmpty()
    // {
    //     if (top == NULL)
    //         return 1;
    //     else
    //         return 0;
    // }

    // string Conver()
    // {
    //     string infix, postfix;
    //     char temp;
    //     int pr;
    //     cout << "Enter the infix expression : ";
    //     cin >> infix;
    //     for (int i = 0; i < infix.length(); i++)
    //     {
    //         if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
    //         {
    //             postfix += infix[i];
    //         }
    //         else if (infix[i] == '(')
    //         {
    //             push(infix[i]);
    //         }
    //         else if (infix[i] == ')')
    //         {
    //             while ((top->data != '(') && (!isEmpty()))
    //             {
    //                 char temp = top->data;
    //                 postfix += temp;
    //                 pop();
    //             }
    //             if (top->data == '(')
    //             {
    //                 pop();
    //             }
    //         }
    //         else if (isoperat(infix[i]))
    //         {
    //             if (!isEmpty())
    //             {
    //                 push(infix[i]);
    //             }
    //             else
    //             {
    //                 if (preference(infix[i]) > preference(top->data))
    //                 {
    //                     push(infix[i]);
    //                 }
    //                 else if ((preference(infix[i]) == preference(top->data)) && (infix[i] == '^'))
    //                 {
    //                     push(infix[i]);
    //                 }
    //                 else
    //                 {
    //                     while ((!isEmpty()) && (preference(infix[i]) <= preference(top->data)))
    //                     {
    //                         postfix += top->data;
    //                         pop();
    //                     }
    //                     push(infix[i]);
    //                 }
    //             }
    //         }
    //     }
    //     while (!isEmpty())
    //     {
    //         postfix += top->data;
    //         pop();
    //     }
    //     cout << "THe postfix expression is -> " << postfix << endl;
    //     return postfix;
    // }

    string conversion()
    {
        string infix, postfix;
        char temp;
        int pr;
        cout << "Enter the infix expression : ";
        cin >> infix;
        for (int i = 0; i < infix.length(); i++)
        {
            switch (infix[i])
            {
            case '(':
                push(infix[i]);
                break;
            case ')':
                while (top->data != '(')
                {
                    temp = pop();
                    postfix += temp;
                }
                pop();
                break;
            case '*':
            case '/':
            case '+':
            case '-':
                if (top == NULL || top->data == '(')
                {
                    push(infix[i]);
                }
                else
                {
                    pr = preference(top->data);
                    if (pr < preference(infix[i]))
                    {
                        push(infix[i]);
                    }
                    else
                    {
                        while (top != NULL)
                        {
                            if (preference(top->data) >= preference(infix[i]))
                            {
                                temp = pop();
                                postfix += temp;
                            }
                            else
                            {
                                break;
                            }
                        }
                        push(infix[i]);
                    }
                }
                break;

            default:
                postfix += infix[i];
                break;
            }
        }
        while (top != NULL)
        {
            temp = pop();
            postfix += temp;
        }
        cout << "THe postfix expression is -> " << postfix << endl;
        return postfix;
    }

    void evaluation(string postfix)
    {
        stack oper;
        int temp, s1, s2, s3;

        for (int i = 0; i < postfix.length(); i++)
        {
            switch (postfix[i])
            {
            case '*':
            case '/':
            case '+':
            case '-':
                break;

            default:
                cout << "Enter the value of the variables in order : ";
                cin >> temp;
                postfix[i] = temp;
                break;
            }
        }
        for (int i = 0; i < postfix.length(); i++)
        {
            switch (postfix[i])
            {
            case '+':
                s1 = oper.pop_num();
                s2 = oper.pop_num();
                s3 = s1 + s2;
                oper.push_num(s3);
                oper.display_num();
                break;
            case '-':
                s1 = oper.pop_num();
                s2 = oper.pop_num();
                s3 = s2-s1;
                oper.push_num(s3);
                oper.display_num();
                break;
            case '*':
                s1 = oper.pop_num();
                s2 = oper.pop_num();
                s3 = s1 * s2;
                oper.push_num(s3);
                oper.display_num();
                break;
            case '/':
                s1 = oper.pop_num();
                s2 = oper.pop_num();
                s3 = s2 / s1;
                oper.push_num(s3);
                oper.display_num();
                break;
            default:
                oper.push_num(postfix[i]);
                break;
            }
        }
        cout << "\nThe value of the expression is = " << oper.top->num;
    }
};

int main()
{
    stack obj;
    int choice;
    string temp;
    while (choice != 2)
    {
        cout << "\n**Main Menu**\n";
        cout << "1. Convert an expression from infix to postfix\n2. Exit\n";
        cout << "*****\n\n";

        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice)
        {
        case 1:
            temp = obj.conversion();
            obj.evaluation(temp);
            break;

        case 2:
            cout << "Exiting.....\nThank you!!!!!!!\n";
            break;

        default:
            cout << "Enter a valid choice from the menu....\n";
            break;
        }
    }
    return 0;
}

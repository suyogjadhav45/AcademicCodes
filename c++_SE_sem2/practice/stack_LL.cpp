#include <iostream>
using namespace std;

template <typename T>
class Node
{
private:
    Node<T> *next;
    T data;

public:
    Node()
    {
        next == NULL;
        // data = 0;
    }
    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
    template <typename S>
    friend class Stack;
};

template <typename T>
class Stack
{
    Node<T> *top;

public:
    Stack()
    {
        top = NULL;
    }

    void push(T d)
    {
        Node<T> *temp = new Node<T>(d);
        temp->next = top;
        top = temp;
    }

    bool isEmpty()
    {
        if (top == NULL)
        {
            // cout << "\nStack is empty!!\n";
            return true;
        }
        return false;
    }

    T pop()
    {
        if (!isEmpty())
        {
            Node<T> *temp = top;
            T value = top->data;
            top = top->next;
            delete (temp);
            // cout << "\n"<< value << " has been popped out successfully!!" << endl;
            return value;
        }
        return 0;
    }

    void display()
    {
        if (!isEmpty())
        {
            Node<T> *temp = top;
            cout << "\nThe Stack is : " << endl;
            while (temp != NULL)
            {
                cout << "\t" << temp->data << "\n";
                temp = temp->next;
            }
        }
    }
};

int main()
{
    Stack<int>s;
    s.pop();
    s.display();
    s.push(4);
    s.push(8);
    s.push(2);
    s.push(9);
    s.push(20);
    s.display();
    s.pop();
    s.display();
    
    return 0;
}
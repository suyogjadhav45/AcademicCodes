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

class BTNode
{
private:
    BTNode *lchild, *rchild;
    int d;

public:
    BTNode()
    {
        lchild = NULL;
        rchild = NULL;
        d = 0;
    }
    BTNode(int d)
    {
        this->d = d;
        lchild = NULL;
        rchild = NULL;
    }
    friend class Binary_Tree;
};

class Binary_Tree
{
    BTNode *root;

public:
    Binary_Tree()
    {
        root = NULL;
    }

    BTNode *create_bt_rec()
    {
        int c;
        cout << "\nEnter the Data -----> ";
        cin >> c;
        if (c == -1)
        {
            return NULL;
        }
        else
        {
            BTNode *p = new BTNode(c);
            cout << "Enter the value of left child of " << p->d << " :";
            p->lchild = create_bt_rec();
            cout << "Enter the value of right child of " << p->d << " :";
            p->rchild = create_bt_rec();
            return p;
        }
    }

    void set_root(BTNode *k)
    {
        root = k;
    }

    BTNode *getroot()
    {
        return root;
    }

    void preorder_iter()
    {
        Stack<BTNode *> s1;
        s1.push(root);
        while (!s1.isEmpty())
        {
            BTNode *temp = s1.pop();
            cout << " [ " << temp->d << " ] ";
            if (temp->rchild)
            {
                s1.push(temp->rchild);
            }
            if (temp->lchild)
            {
                s1.push(temp->lchild);
            }
        }
    }

    void inorder_iter()
    {
        Stack<BTNode *> s1;
        BTNode *current = root;
        while (!s1.isEmpty() || current != NULL)
        {
            while (current != NULL)
            {
                s1.push(current);
                current = current->lchild;
            }
            current = s1.pop();
            cout << " [ " << current->d << " ] ";
            current = current->rchild;
        }
    }

    void postorder_iter()
    {
        Stack<BTNode *> s1;
        Stack<BTNode *> s2;
        s1.push(root);
        while (!s1.isEmpty())
        {
            BTNode *temp = s1.pop();
            s2.push(temp);
            if (temp->lchild != NULL)
            {
                s1.push(temp->lchild);
            }
            if (temp->rchild != NULL)
            {
                s1.push(temp->rchild);
            }
        }
        while (!s2.isEmpty())
        {
            BTNode *temp2 = s2.pop();
            cout << " [ " << temp2->d << " ] ";
        }
    }
};

int main()
{
    Binary_Tree b;
    BTNode *l = b.create_bt_rec();
    b.set_root(l);
    // cout << "\n---------Preorder Iterative Representation-------------\n\n";
    // b.preorder_iter();
    // cout << "\n\n---------Inorder Iterative Representation-------------\n\n";
    // b.inorder_iter();
    // cout << "\n\n---------Postorder Iterative Representation-------------\n\n";
    // b.postorder_iter();
    int ch;
    while (ch != 4)
    {
        cout << "\n\n--------------------MAIN MENU (Iterative Traversal) --------------------\n\n";
        cout << "1) Inorder representation of Binary Tree" << endl;
        cout << "2) Postorder representation of Binary Tree" << endl;
        cout << "3) Preorder representation of Binary Tree" << endl;
        cout << "4) Exit" << endl;
        cout << "\nEnter your choice(1/2/3/4) -----> ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\n---------Inorder Iterative Representation-------------\n\n";
            b.inorder_iter();
            break;
        case 2:
            cout << "\n\n---------Postorder Iterative Representation-------------\n\n";
            b.postorder_iter();
            break;
        case 3:
            cout << "\n\n---------Preorder Iterative Representation-------------\n\n";
            b.preorder_iter();
            break;
        default:
            break;
        }
    }

    return 0;
}
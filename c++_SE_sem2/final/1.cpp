/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

template <typename T>
class Node
{
    Node<T> *next;
    T data;

public:
    Node()
    {
        next = NULL;
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
            return true;
        }
        return false;
    }
    T pop()
    {
        if (!isEmpty())
        {
            T value = top->data;
            top = top->next;
            return value;
        }
        return 0;
    }
};

class BTNode
{
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
        lchild = NULL;
        rchild = NULL;
        this->d = d;
    }
    friend class Binary_Tree;
};

class Binary_Tree
{
    BTNode *root;
    int count_leaf = 0;
    int count_int = 0;

public:
    Binary_Tree()
    {
        root = NULL;
    }
    BTNode *create_rec()
    {
        int c;
        cout << "\nEnter data : ";
        cin >> c;
        if (c == -1)
        {
            return NULL;
        }
        else
        {
            BTNode *p = new BTNode(c);
            cout << "\nEnter the value of left child of " << p->d << " : ";
            p->lchild = create_rec();
            cout << "\nEnter the value of right child of " << p->d << " : ";
            p->rchild = create_rec();
            return p;
        }
    }
    void preorder_iter()
    {
        Stack<BTNode *> s;
        BTNode *p = root;
        s.push(p);
        while (!s.isEmpty())
        {
            BTNode *k = s.pop();
            cout << k->d << " --> ";
            if (k->rchild)
            {
                s.push(k->rchild);
            }
            if (k->lchild)
            {
                s.push(k->lchild);
            }
        }
    }

    void inorder_iter()
    {
        Stack<BTNode *> s;
        BTNode *curr = root;
        while ((!s.isEmpty()) || curr != NULL)
        {
            while (curr != NULL)
            {
                s.push(curr);
                curr = curr->lchild;
            }
            curr = s.pop();
            cout << curr->d << " --> ";
            curr = curr->rchild;
        }
    }

    void post_iter()
    {
        Stack<BTNode *> s1, s2;
        s1.push(root);
        while (!s1.isEmpty())
        {
            BTNode *p = s1.pop();
            s2.push(p);
            if (p->lchild)
            {
                s1.push(p->lchild);
            }
            if (p->rchild)
            {
                s1.push(p->rchild);
            }
        }
        while (!s2.isEmpty())
        {
            BTNode *k = s2.pop();
            cout << k->d << " --> ";
        }
    }

    void setroot(BTNode *p)
    {
        root = p;
    }
    BTNode *getroot()
    {
        return root;
    }

    void preorder_rec(BTNode *k)
    {
        if (k)
        {
            cout << k->d << " --> ";
            preorder_rec(k->lchild);
            preorder_rec(k->rchild);
        }
    }
    void inorder_rec(BTNode *k)
    {
        if (k)
        {
            inorder_rec(k->lchild);
            cout << k->d << " --> ";
            inorder_rec(k->rchild);
        }
    }
    void postorder_rec(BTNode *k)
    {
        if (k)
        {
            postorder_rec(k->lchild);
            postorder_rec(k->rchild);
            cout << k->d << " --> ";
        }
    }
    void print_leaf(BTNode *k)
    {
        if (k == NULL)
        {
            return;
        }
        print_leaf(k->lchild);
        print_leaf(k->rchild);
        if (k->lchild == NULL && k->rchild == NULL)
        {
            cout << k->d << " --> ";
            count_leaf++;
        }
    }
    int noofleaf()
    {
        return count_leaf;
    }
    void print_interior(BTNode *k)
    {
        if (k == NULL)
        {
            return;
        }
        print_interior(k->lchild);
        print_interior(k->rchild);
        if (k->lchild != NULL || k->rchild != NULL)
        {
            cout << k->d << " --> ";
            count_int++;
        }
    }
    int noofinterior()
    {
        return count_int;
    }
    int height_rec(BTNode *k)
    {
        if (k != NULL)
        {
            int lh = height_rec(k->lchild);
            int rh = height_rec(k->rchild);
            return 1 + max(lh, rh);
        }
        return 0;
    }
    void operator=(const Binary_Tree &obj)
    {
        root = obj.root;
        root->lchild = obj.root->lchild;
        root->rchild = obj.root->rchild;
    }
    void mirror_bt(BTNode *k)
    {
        if (k == NULL)
        {
            return;
        }
        mirror_bt(k->lchild);
        mirror_bt(k->rchild);
        BTNode *t = k->lchild;
        k->lchild = k->rchild;
        k->rchild = t;
    }
    void delete_tree(BTNode *k)
    {
        if (k)
        {
            delete_tree(k->lchild);
            delete_tree(k->rchild);
            delete k;
        }
    }
};

int main()
{
    Binary_Tree b, b2;
    BTNode *l = b.create_rec();
    b.setroot(l);
    BTNode *k = b.getroot();
    cout << "\n---------Inorder Reccursive Representation-------------\n\n";
    b.inorder_rec(k);
    cout
        << "\n\n---------Postorder Reccursive Representation-------------\n\n";
    b.postorder_rec(k);
    cout << "\n\n---------Preorder Reccursive Representation-------------\n\n";
    b.preorder_rec(k);
    cout << "\n---------Inorder Iterative Representation-------------\n\n";
    b.inorder_iter();
    cout << "\n\n---------Postorder Iterative Representation-------------\n\n";
    b.post_iter();
    cout << "\n\n---------Preorder Iterative Representation-------------\n\n";
    b.preorder_iter();
    cout << "\n\n---------Mirror Image-------------\n\n";
    b.mirror_bt(k);
    cout << "\n---------Inorder of Mirrored Tree-------------\n\n";
    b.inorder_rec(k);
    cout << "\n---------Height Reccursively-------------\n\n";
    int sl = b.height_rec(k);
    cout << sl << endl;
    // // cout << "\n\n---------Height Iteratively-------------\n\n";
    // // int t = b.height_iter();
    // // cout << t << endl;

    cout << "\n\nPrint and count the Leaf Nodes\n\n";
    b.print_leaf(k);
    int p = b.noofleaf();
    cout << "\nCount : " << p << endl;

    cout << "\n\nPrint and count the Interior Nodes\n\n";
    b.print_interior(k);
    int m = b.noofinterior();
    cout << "\nCount : " << m << endl;
    // cout << "\n\nDelete all Nodes\n\n";
    // b.delete_tree(k);
    cout << "\nCOPY TREE\n";
    b.inorder_iter();
    cout << "\n";
    b2 = b;
    b2.inorder_iter();
    return 0;
}

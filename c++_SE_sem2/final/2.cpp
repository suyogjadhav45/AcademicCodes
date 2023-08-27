/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
// DSAL02---> BINARY SEARCH TREE

#include <iostream>
using namespace std;

class Node
{
    Node *lchild, *rchild;
    string w;

public:
    Node()
    {
        lchild = rchild = NULL;
        w = "";
    }
    Node(string w)
    {
        this->w = w;
        lchild = rchild = NULL;
    }
    friend class BST;
};

class BST
{
    Node *root;

public:
    BST()
    {
        root = NULL;
    }

    int search(string l, Node *&cur, Node *&par)
    {
        cur = par = NULL;
        Node *p = root;
        int count = 0;
        while (p)
        {
            if (p->w == l)
            {
                cur = p;
                count++;
                break;
            }
            else if (p->w > l)
            {
                par = p;
                p = p->lchild;
                count++;
            }
            else
            {
                par = p;
                p = p->rchild;
                count++;
            }
        }
        return count;
    }

    void insert(string l)
    {
        Node *cur, *par;
        cur = par = NULL;
        search(l, cur, par);
        if (root == NULL)
        {
            root = new Node(l);
        }
        else if (cur != NULL)
        {
            cout << "\nDuplicate Entry" << endl;
        }

        else if (par->w > l)
        {
            par->lchild = new Node(l);
        }

        else
        {
            par->rchild = new Node(l);
        }
    }

    void del1(string l)
    {
        Node *cur, *par;
        cur = par = NULL;
        search(l, cur, par);
        if (cur->lchild == NULL && cur->rchild == NULL)
        {
            if (par->lchild == cur)
            {
                par->lchild = NULL;
            }
            else
            {
                par->rchild = NULL;
            }
        }
        else
        {
            if (par->lchild == cur)
            {
                if (cur->lchild)
                {
                    par->lchild = cur->lchild;
                }
                else
                {
                    par->lchild = cur->rchild;
                }
            }
            else
            {
                if (cur->lchild)
                {
                    par->rchild = cur->lchild;
                }
                else
                {
                    par->rchild = cur->rchild;
                }
            }
        }
    }

    void del2(string l)
    {
        Node *cur, *par;
        cur = par = NULL;
        search(l, cur, par);
        Node *child = cur->rchild;
        while (child->lchild)
        {
            child = child->lchild;
        }
        string x = child->w;
        del1(x);
        cur->w = x;
    }

    void del_mn(string l)
    {
        Node *cur, *par;
        cur = par = NULL;
        search(l, cur, par);
        if (cur->lchild != NULL && cur->rchild != NULL)
        {
            del2(l);
        }
        else
        {
            del1(l);
        }
    }

    void disp(Node *r)
    {
        if (r)
        {
            disp(r->lchild);
            cout << r->w << " --> ";
            disp(r->rchild);
        }
    }

    Node *getroot()
    {
        return root;
    }
};

int main()
{
    // cout << "Hello World";
    BST b;
    b.insert("rohit");
    b.insert("last");
    b.insert("hii");
    b.insert("pk");
    b.insert("man");
    b.insert("que");
    //   b.insert();
    //   b.insert();
    b.disp(b.getroot());
    cout << endl;
    b.del_mn("last");
    b.disp(b.getroot());

    return 0;
}

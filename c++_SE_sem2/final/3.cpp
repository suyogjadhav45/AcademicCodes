/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

class Node
{
    Node *lchild, *rchild;
    bool lflag, rflag;
    int data;

public:
    Node()
    {
        lchild = rchild = NULL;
        lflag = rflag = 0;
        data = 0;
    }
    Node(int d)
    {
        lchild = rchild = NULL;
        lflag = rflag = 0;
        data = d;
    }
    friend class TBST;
};

class TBST
{
    Node *root, *header;

public:
    TBST()
    {
        root = NULL;
        header = new Node(-1);
        header->lchild = header;
        header->rchild = header;
    }

    void insert(int d)
    {
        Node *par, *curr;
        par = root;
        curr = new Node(d);
        if (root == NULL)
        {
            root = curr;
            header->lchild = root;
            header->lflag = 1;
            root->lchild = header;
            root->rchild = header;
        }
        else
        {
            while (true)
            {
                if (par->data == d)
                {
                    cout << "\nDuplicate Entry" << endl;
                    return;
                }
                else if (par->data > d)
                {
                    if (par->lflag == 1)
                    {
                        par = par->lchild;
                    }
                    else
                    {
                        curr->lchild = par->lchild;
                        par->lchild = curr;
                        par->lflag = 1;
                        curr->rchild = par;
                        break;
                    }
                }

                else
                {
                    if (par->rflag == 1)
                    {
                        par = par->rchild;
                    }
                    else
                    {
                        curr->rchild = par->rchild;
                        par->rchild = curr;
                        par->rflag = 1;
                        curr->lchild = par;
                        break;
                    }
                }
            }
        }
    }

    void disp_inorder()
    {
        Node *t = root;
        if (root == NULL)
        {
            return;
        }

        while (t->lflag == 1)
        {
            t = t->lchild;
        }
        while (t->rchild != header)
        {
            cout << t->data << "\t";
            if (t->rflag == 0)
            {
                t = t->rchild;
            }
            else
            {
                t = t->rchild;
                while (t->lflag == 1)
                {
                    t = t->lchild;
                }
            }
        }
        cout << t->data << "\t";
    }

    void disp_preorder()
    {
        Node *t = root;
        do
        {
            while (t->lflag == 1)
            {
                cout << t->data << "\t";
                t = t->lchild;
            }
            cout << t->data << "\t";
            while (t->rflag == 0)
            {
                t = t->rchild;
                if (t == header)
                {
                    return;
                }
            }
            t = t->rchild;
        } while (t != header);
    }
};

int main()
{
    TBST b;
    b.insert(10);
    b.insert(5);
    b.insert(7);
    b.insert(13);
    b.insert(17);
    // b.deleteNode(5);
    b.disp_inorder();
    // b.deleteNode(13);
    cout << "\n";
    // b.display_tbst_inorder();
    // cout << "\n";
    b.disp_preorder();
    cout << "\n";
    return 0;
}

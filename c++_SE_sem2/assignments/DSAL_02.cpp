//============================================================================
// Name        : DSAL_02.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
using namespace std;

class BTNode
{
private:
    BTNode *lchild, *rchild;
    string word, meaning;

public:
    BTNode()
    {
        lchild = NULL;
        rchild = NULL;
        word = "";
        meaning = "";
    }
    BTNode(string word)
    {
        this->word = word;
        lchild = NULL;
        rchild = NULL;
    }
    BTNode(string word, string meaning)
    {
        this->word = word;
        this->meaning = meaning;
        lchild = NULL;
        rchild = NULL;
    }

    friend class Binary_Search_Tree;
};

class Binary_Search_Tree
{
    BTNode *root;

public:
    Binary_Search_Tree()
    {
        root = NULL;
    }
    void search(string w)
    {
        BTNode *current, *parent;
        parent = current = NULL;
        search(w, current, parent);
    }

    int search(string l, BTNode *&current, BTNode *&parent)
    {
        parent = NULL;
        current = NULL;
        int count = 0;
        BTNode *p = root;
        while (p != NULL)
        {
            if (p->word == l)
            {
                current = p;
                count++;
                break;
            }
            else if (p->word > l)
            {
                parent = p;
                p = p->lchild;
                count++;
            }
            else
            {
                parent = p;
                p = p->rchild;
                count++;
            }
        }
        return count;
    }

    void insert()
    {
        string w, m;
        cout << "\nEnter Word -----> ";
        cin >> w;
        cout << "Enter Meaning of word -----> ";
        cin >> m;
        insert(w, m);
    }
    void insert(string w, string m)
    {
        BTNode *current, *parent;
        parent = current = NULL;
        search(w, current, parent);
        if (root == NULL)
        {
            root = new BTNode(w, m);
            return;
        }
        else if (current != NULL)
        {
            cout << w << " is already in the Binary Search Tree" << endl;
            return;
        }
        else if (parent->word > w)
        {
            parent->lchild = new BTNode(w, m);
            return;
        }
        else
        {
            parent->rchild = new BTNode(w, m);
            return;
        }
    }

    void display_bst(BTNode *r)
    {
        if (r != NULL)
        {
            display_bst(r->lchild);
            cout << " [ " << r->word << " , " << r->meaning << " ] ";
            display_bst(r->rchild);
        }
    }
    BTNode *getroot()
    {
        return root;
    }

    void delete_mn()
    {
        string w;
        cout << "Enter the word to delete it -----> ";
        cin >> w;
        delete_mn(w);
    }

    void delete_mn(string w)
    {
        BTNode *current, *parent;
        parent = current = NULL;
        search(w, current, parent);
        if (current->lchild != NULL && current->rchild != NULL)
        {
            delete_2(w);
        }
        else
        {
            delete_1(w);
        }
    }

    void delete_1(string w)
    {
        BTNode *current, *parent;
        parent = current = NULL;
        search(w, current, parent);
        if (current->lchild == NULL && current->rchild == NULL)
        {
            if (parent->lchild == current)
            {
                parent->lchild = NULL;
            }
            else
            {
                parent->rchild = NULL;
            }
        }
        else
        {
            if (parent->lchild == current)
            {
                if (current->lchild)
                {
                    parent->lchild = current->lchild;
                }
                else
                {
                    parent->lchild = current->rchild;
                }
            }
            else
            {
                if (current->lchild)
                {
                    parent->rchild = current->lchild;
                }
                else
                {
                    parent->rchild = current->rchild;
                }
            }
        }
    }

    void delete_2(string w)
    {
        BTNode *current, *parent, *child;
        parent = current = NULL;
        search(w, current, parent);
        child = current->rchild;
        while (child->lchild != NULL)
        {
            child = child->lchild;
        }
        string x, y;
        x = child->word;
        y = child->meaning;
        delete_mn(child->word);
        current->word = x;
        current->meaning = y;
    }
};

int main()
{
    Binary_Search_Tree b;
    b.insert("rohit", "captain");
    b.insert("last", "l");
    b.insert("hii", "greet");
    b.insert("pk", "s");
    b.insert("man", "f");
    b.insert("que", "k");
    //   b.insert();
    //   b.insert();
    b.display_bst(b.getroot());
    cout << endl;
    b.delete_mn("last");
    b.display_bst(b.getroot());
    return 0;
}

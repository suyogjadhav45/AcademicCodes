//============================================================================
// Name        : DSAL03.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class TBSTNode
{
private:
    TBSTNode *lchild, *rchild;
    bool lflag, rflag;
    int data;

public:
    TBSTNode()
    {
        lchild = NULL;
        rchild = NULL;
        lflag = rflag = false;
        data = 0;
    }
    TBSTNode(int data)
    {
        this->data = data;
        lflag = rflag = false;
        lchild = NULL;
        rchild = NULL;
    }
    friend class Threaded_BST;
};

class Threaded_BST
{
    TBSTNode *root, *header;

public:
    Threaded_BST()
    {
        root = header = NULL;
    }

    void insert(int d)
    {
        TBSTNode *current, *parent;
        parent = root;
        current = new TBSTNode(d);
        // search(d, current, parent);
        if (root == NULL)
        {
            root = new TBSTNode(d);
            header = new TBSTNode(-1);
            header->rchild = header;
            header->lchild = root;
            root->lchild = header;
            root->rchild = header;
        }
        else
        {
            while (true)
            {
                if (d == parent->data)
                {
                    cout << "Duplicate Data can not be added!!!" << endl;
                    return;
                }
                else if (d < parent->data)
                {
                    if (parent->lflag == 1)
                        parent = parent->lchild;
                    else
                    {
                        current->lchild = parent->lchild;
                        parent->lchild = current;
                        parent->lflag = 1;
                        current->rchild = parent;
                        break;
                    }
                }
                else
                {
                    if (parent->rflag == 1)
                        parent = parent->rchild;
                    else
                    {
                        current->rchild = parent->rchild;
                        current->lchild = parent;
                        parent->rchild = current;
                        parent->rflag = 1;
                        break;
                    }
                }
            }
        }
    }

    void display_tbst_inorder()
    {
        TBSTNode *temp = root;
        if (root == NULL)
        {
            return;
        }
        while (temp->lflag == 1)
        {
            temp = temp->lchild;
        }
        while (temp->rchild != header)
        {
            cout << temp->data << "\t";
            if (temp->rflag == 0)
            {
                temp = temp->rchild;
            }
            else
            {
                temp = temp->rchild;
                while (temp->lflag == 1)
                {
                    temp = temp->lchild;
                }
            }
        }
        cout << temp->data << "\t";
    }

    void display_tbst_preorder()
    {
        TBSTNode *temp = root;
        do
        {
            while (temp->lflag != 0)
            {
                cout << temp->data << "\t";
                temp = temp->lchild;
            }
            cout << temp->data << "\t";
            while (temp->rflag == 0)
            {
                temp = temp->rchild;
                if (temp == header)
                {
                    return;
                }
            }
            temp = temp->rchild;
        } while (temp != header);
    }

    TBSTNode *inSucc(TBSTNode *ptr)
    {
        if (ptr->rflag == 1)
            return ptr->rchild;
        ptr = ptr->rchild;
        while (ptr->lflag == 0)
            ptr = ptr->lchild;
        return ptr;
    }

    TBSTNode *inPred(TBSTNode *ptr)
    {
        if (ptr->lflag == 1)
            return ptr->lchild;
        ptr = ptr->lchild;
        while (ptr->rflag == 0)
            ptr = ptr->rchild;
        return ptr;
    }

    void deleteNode(int x)
    {
        if (header->lchild == NULL)
        {
            cout << "Tree is Empty!!" << endl;
            return;
        }
        TBSTNode *temp = header->lchild;
        TBSTNode *parent = header;
        int found = 0;
        while (temp != header)
        {
            if (temp->data == x)
            {
                found = 1;
                break;
            }
            else if (temp->data > x)
            {
                if (temp->lflag == 1)
                {
                    cout << "Element not found!!" << endl;
                    return;
                }
                parent = temp;
                temp = temp->lchild;
            }
            else if (temp->data < x)
            {
                if (temp->rflag == 1)
                {
                    cout << "Element not found!!" << endl;
                    return;
                }
                parent = temp;
                temp = temp->rchild;
            }
        }
        // node to be deleted has two children
        if (temp->lflag == 0 && temp->rflag == 0)
        {
            // find inorder successor
            TBSTNode *successor = temp->rchild;
            TBSTNode *p_successor = temp;
            TBSTNode *child = NULL;

            // find leftmost child of successor
            while (successor->lflag != 1)
            {
                p_successor = successor;
                successor = successor->lchild;
            }

            temp->data = successor->data;
            if (successor->lflag == 1 && successor->rflag == 1)
            {
                if (p_successor == temp)
                {
                    p_successor->rchild = successor->rchild;
                    p_successor->rflag = 1;
                    delete successor;
                    cout << "Node deleted!!" << endl;
                    return;
                }

                p_successor->lchild = successor->lchild;
                p_successor->lflag = 1;
            }
            else
            { // successor has a right child
                p_successor->lchild = successor->rchild;
                child = successor->rchild;
                child->lchild = successor->lchild;
            }
            delete successor;
            cout << "Node deleted!!" << endl;
            return;
        }
        // node to be deleted has only one child
        else if (temp->lflag == 0 || temp->rflag == 0)
        {
            TBSTNode *child = NULL;
            // initialize the child node
            if (temp->lflag == 0)
            {
                child = temp->lchild;
            }
            else
            {
                child = temp->rchild;
            }

            // node to be deleted is root node
            if (temp == root)
            {
                header->lchild = child;
                root = child;
            }
            // node to deleted is left child of its parent
            else if (parent->lchild == temp)
            {
                parent->lchild = child;
            }
            // node to be deleted is right child of its parent
            else
            {
                parent->rchild = child;
            }
            // find succsssor and predecessoe
            TBSTNode *s = inSucc(temp);
            TBSTNode *p = inPred(temp);

            // if temp has left subtree
            if (temp->lflag == 0)
            {
                p->rchild = s;
            }
            // if temp has right subtree
            else
            {
                s->lchild = p;
            }

            delete temp;
            cout << "Node deleted!!" << endl;
            return;
        }
        // node to be deleted has no child
        else
        {
            // if node to be deleted is root
            if (temp == root)
            {
                header->lchild = NULL;
                root = NULL;
            }
            // if node to be deleted is left child of it's parent
            else if (parent->lchild == temp)
            {
                parent->lflag = 1;
                parent->lchild = temp->lchild;
            }
            // if node to be deleted is right child of it's parent
            else
            {
                parent->rflag = 1;
                parent->rchild = temp->rchild;
            }
            delete temp;
            cout << "Node deleted!!" << endl;
            return;
        }
    }
};

int main()
{
    Threaded_BST b;
    b.insert(10);
    b.insert(5);
    b.insert(7);
    b.insert(13);
    b.insert(17);
    // b.deleteNode(5);
    b.display_tbst_inorder();
    // b.deleteNode(13);
    cout << "\n";
    b.display_tbst_inorder();
    cout << "\n";
    b.display_tbst_preorder();
    cout << "\n";
    return 0;
}

#include <iostream>
using namespace std;

template <typename T>
class Node
{
private:
    Node *next;
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
    template <typename Q>
    friend class Queue;
};

template <typename T>
class Queue
{
    Node<T> *front;
    Node<T> *rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    bool isEmpty()
    {
        if (front == NULL)
        {
            // cout<<"\nQueue is Empty!!"<<endl;
            return true;
        }
        return false;
    }

    void enqueue(T d)
    {
        Node<T> *temp = new Node<T>(d);
        if (front == NULL)
        {
            front = temp;
            rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
    }

    T dequeue()
    {
        if (!isEmpty())
        {
            Node<T> *temp = front;
            T a = front->data;
            front = front->next;
            // cout<<"\nElement( "<<a<<" ) dequeued successfully!!"<<endl;
            delete temp;
            return a;
        }
        return 0;
    }

    void display()
    {
        if (!isEmpty())
        {
            Node<T> *temp = front;
            cout << "\nThe Queue is : " << endl;
            cout << "\t-- ";
            while (temp != NULL)
            {
                cout << temp->data << " -- ";
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
    static int count_leaf;
    static int count_interior;

    Binary_Tree()
    {
        root = NULL;
    }

    void create_bt()
    {
        Queue<BTNode *> q;
        int c;
        cout << "\nEnter the Data of Root -----> ";
        cin >> c;
        root = new BTNode(c);
        q.enqueue(root);

        while (!q.isEmpty())
        {
            BTNode *t = q.dequeue();
            int p, w;

            cout << "Enter the value of left child of " << t->d << " -----> ";
            cin >> p;

            if (p != -1)
            {
                BTNode *r = new BTNode(p);
                t->lchild = r;
                q.enqueue(r);
            }

            cout << "Enter the value of right child of " << t->d << " ----> ";
            cin >> w;

            if (w != -1)
            {
                BTNode *s = new BTNode(w);
                t->rchild = s;
                q.enqueue(s);
            }
        }
    }

    BTNode *getroot()
    {
        return root;
    }

    void inorder_rec(BTNode *r)
    {
        if (r != NULL)
        {
            inorder_rec(r->lchild);
            cout << "[ " << r->d << " ]  ";
            inorder_rec(r->rchild);
        }
    }

    void postorder_rec(BTNode *r)
    {
        if (r != NULL)
        {
            postorder_rec(r->lchild);
            postorder_rec(r->rchild);
            cout << "[ " << r->d << " ]  ";
        }
    }

    void preorder_rec(BTNode *r)
    {
        if (r != NULL)
        {
            cout << "[ " << r->d << " ]  ";
            preorder_rec(r->lchild);
            preorder_rec(r->rchild);
        }
    }

    void leaf_nodes(BTNode *p)
    {

        if (p == NULL)
        {
            return;
        }
        leaf_nodes(p->lchild);
        leaf_nodes(p->rchild);
        if (p->lchild == NULL && p->rchild == NULL)
        {
            cout << " [ " << p->d << " ] ";
            count_leaf++;
        }
    }

    void interior_nodes(BTNode *p)
    {
        if (p == NULL)
        {
            return;
        }
        interior_nodes(p->lchild);
        interior_nodes(p->rchild);
        if (p->lchild != NULL || p->rchild != NULL)
        {
            cout << " [ " << p->d << " ] ";
            count_interior++;
        }
    }

    void mirror_bt(BTNode *p)
    {
        if (p == NULL)
        {
            return;
        }
        mirror_bt(p->lchild);
        mirror_bt(p->rchild);
        // Now swapping the nodes
        BTNode *temp = p->lchild;
        p->lchild = p->rchild;
        p->rchild = temp;
    }

    BTNode *copy_bt(BTNode *p)
    {
        if (p == NULL)
        {
            return NULL;
        }

        BTNode *newr = new BTNode(p->d);
        newr->lchild = copy_bt(p->lchild);
        newr->rchild = copy_bt(p->rchild);
        return newr;
    }
};

int Binary_Tree ::count_leaf= 0;
int Binary_Tree ::count_interior = 0;

int main()
{
    Binary_Tree b;
    b.create_bt();
    BTNode *k = b.getroot();
    b.leaf_nodes(k);
    cout << "\n";
    cout << "count : " << b.count_leaf << endl;
    b.interior_nodes(k);
    cout << "\n";
    cout << "count : " << b.count_interior << endl;
    b.inorder_rec(k);
    
    cout << "\n";
    BTNode *c = b.copy_bt(k);
    b.inorder_rec(c);
    cout << "\n";
    b.mirror_bt(c);
    cout << "\n";
    b.inorder_rec(c);
    cout<<endl;
    b.inorder_rec(k);

    int ch;
    while (ch != 4)
    {
        cout << "\n\n--------------------MAIN MENU--------------------\n\n";
        cout << "1) Inorder representation of Binary Tree" << endl;
        cout << "2) Postorder representation of Binary Tree" << endl;
        cout << "3) Preorder representation of Binary Tree" << endl;
        cout << "4) Exit" << endl;
        cout << "\nEnter your choice(1/2/3/4) -----> ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\n---------Inorder Reccursive Representation-------------\n\n";
            b.inorder_rec(k);
            break;
        case 2:
            cout << "\n\n---------Postorder Reccursive Representation-------------\n\n";
            b.postorder_rec(k);
            break;
        case 3:
            cout << "\n\n---------Preorder Reccursive Representation-------------\n\n";
            b.preorder_rec(k);
            break;
        default:
            break;
        }
    }

    return 0;
}
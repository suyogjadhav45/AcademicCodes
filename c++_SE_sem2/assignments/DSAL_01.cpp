

#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class Nodeq
{
private:
    Nodeq *next;
    T data;

public:
    Nodeq()
    {
        next == NULL;
        // data = 0;
    }
    Nodeq(T data)
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
    Nodeq<T> *front;
    Nodeq<T> *rear;

public:
    int ct = 0;
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
        Nodeq<T> *temp = new Nodeq<T>(d);
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
        ct++;
    }

    T dequeue()
    {
        if (!isEmpty())
        {
            Nodeq<T> *temp = front;
            T a = front->data;
            front = front->next;
            // cout<<"\nElement( "<<a<<" ) dequeued successfully!!"<<endl;
            delete temp;
            // cout<<"ct decremented"<<endl;
            ct = ct - 1;
            return a;
        }
        return NULL;
    }

    int size()
    {
        return ct;
    }

    void display()
    {
        if (!isEmpty())
        {
            Nodeq<T> *temp = front;
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
    int count_leaf = 0;
    int count_interior = 0;

public:
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

    int count_leaf_nodes()
    {
        return count_leaf;
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
    int count_interior_nodes()
    {
        return count_interior;
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

    void print_horz()
    {
        Queue<BTNode *> q1;
        q1.enqueue(root);
        while (!q1.isEmpty())
        {
            BTNode *temp = q1.dequeue();
            cout << " [ " << temp->d << " ] ";
            if (temp->lchild)
            {
                q1.enqueue(temp->lchild);
            }
            if (temp->rchild)
            {
                q1.enqueue(temp->rchild);
            }
        }
    }

    void delete_tree(BTNode *r)
    {
        if (r)
        {
            delete_tree(r->lchild);
            delete_tree(r->rchild);
        }
    }

    int height_rec(BTNode *p)
    {
        if (p != NULL)
        {
            int lheight = height_rec(p->lchild);
            int rheight = height_rec(p->rchild);
            return 1 + max(lheight, rheight);
        }
        return 0;
    }

    int height_iter()
    {
        Queue<BTNode *> q1;
        q1.enqueue(root);
        int ht = 0;

        while (!q1.isEmpty())
        {
            ht++;
            // cout<<"ht inc"<<endl;
            int count = q1.size();

            for (int i = 0; i < count; i++)
            {
                BTNode *temp = q1.dequeue();
                if (temp->lchild)
                {
                    q1.enqueue(temp->lchild);
                }
                if (temp->rchild)
                {
                    q1.enqueue(temp->rchild);
                }
            }
        }
        return ht;
    }
};

int main()
{
    Binary_Tree b;
    b.create_bt();
    // BTNode *l = b.create_bt_rec();
    // b.set_root(l);
    BTNode *k = b.getroot();
    cout << "\n---------Inorder Reccursive Representation-------------\n\n";
    b.inorder_rec(k);
    cout << "\n\n---------Postorder Reccursive Representation-------------\n\n";
    b.postorder_rec(k);
    cout << "\n\n---------Preorder Reccursive Representation-------------\n\n";
    b.preorder_rec(k);
    cout << "\n---------Inorder Iterative Representation-------------\n\n";
    b.inorder_iter();
    cout << "\n\n---------Postorder Iterative Representation-------------\n\n";
    b.postorder_iter();
    cout << "\n\n---------Preorder Iterative Representation-------------\n\n";
    b.preorder_iter();
    cout << "\n\n---------Mirror Image-------------\n\n";
    b.mirror_bt(k);
    cout << "\n---------Inorder of Mirrored Tree-------------\n\n";
    b.inorder_rec(k);
    cout << "\n---------Height Reccursively-------------\n\n";
    int sl = b.height_rec(k);
    cout << sl << endl;
    cout << "\n\n---------Height Iteratively-------------\n\n";
    int t = b.height_iter();
    cout << t << endl;

    cout << "\n\nPrint and count the Leaf Nodes\n\n";
    b.leaf_nodes(k);
    int p = b.count_leaf_nodes();
    cout << "\nCount : " << p << endl;

    cout << "\n\nPrint and count the Interior Nodes\n\n";
    b.interior_nodes(k);
    int l = b.count_interior_nodes();
    cout << "\nCount : " << l << endl;
    cout << "\n\nDelete all Nodes\n\n";
    b.delete_tree(k);
    // int ch;
    // while (ch != 14)
    // {
    //     cout << "\n\n--------------------MAIN MENU--------------------\n\n";
    //     cout << "1) Inorder representation of Binary Tree (Recursive)" << endl;
    //     cout << "2) Postorder representation of Binary Tree (Recursive)" << endl;
    //     cout << "3) Preorder representation of Binary Tree (Recursive)" << endl;
    //     cout << "4) Inorder representation of Binary Tree (Iterative)" << endl;
    //     cout << "5) Postorder representation of Binary Tree (Iterative)" << endl;
    //     cout << "6) Preorder representation of Binary Tree (Iterative)" << endl;
    //     cout << "7) Mirror Image of Binary Tree" << endl;
    //     cout << "8) Height of Binary Tree recursively" << endl;
    //     cout << "9) Height of Binary Tree iteratively" << endl;
    //     cout << "10) Copy the Binary Tree" << endl;
    //     cout << "11) Print and count the Leaf Nodes" << endl;
    //     cout << "12) Print and count the interior Nodes" << endl;
    //     cout << "13) Delete all Nodes of Bianry Tree" << endl;
    //     cout << "14) Exit" << endl;
    //     cout << "\nEnter your choice -----> ";
    //     cin >> ch;
    //     switch (ch)
    //     {
    //     case 1:
    //         cout << "\n---------Inorder Reccursive Representation-------------\n\n";
    //         b.inorder_rec(k);
    //         break;
    //     case 2:
    //         cout << "\n\n---------Postorder Reccursive Representation-------------\n\n";
    //         b.postorder_rec(k);
    //         break;
    //     case 3:
    //         cout << "\n\n---------Preorder Reccursive Representation-------------\n\n";
    //         b.preorder_rec(k);
    //         break;
    //     case 4:
    //         cout << "\n---------Inorder Iterative Representation-------------\n\n";
    //         b.inorder_iter();
    //         break;
    //     case 5:
    //         cout << "\n\n---------Postorder Iterative Representation-------------\n\n";
    //         b.postorder_iter();
    //         break;
    //     case 6:
    //         cout << "\n\n---------Preorder Iterative Representation-------------\n\n";
    //         b.preorder_iter();
    //         break;
    //     case 7:
    //         cout << "\n\n---------Mirror Image-------------\n\n";
    //         b.mirror_bt(k);
    //         cout << "\n---------Inorder of Mirrored Tree-------------\n\n";
    //         b.inorder_rec(k);
    //         break;
    //     case 8:
    //         cout << "\n---------Height Reccursively-------------\n\n";
    //         int s = b.height_rec(k);
    //         cout << s << endl;
    //         break;
    //     // case 9:
    //     //     cout << "\n\n---------Height Iteratively-------------\n\n";
    //     //     int t= b.height_iter();
    //     //     cout<<t<<endl;
    //     //     break;
    //     // case 10:
    //     //     cout << "\n\n---------Copy the Tree-------------\n\n";
    //     //     b.copy_bt(k);
    //     //     break;
    //     case 11:
    //         cout << "\n\nPrint and count the Leaf Nodes\n\n";
    //         b.leaf_nodes(k);
    //         int p = b.count_leaf_nodes();
    //         cout << "\nCount : " << p << endl;
    //         break;
    //     case 12:
    //         cout << "\n\nPrint and count the Interior Nodes\n\n";
    //         b.interior_nodes(k);
    //         int l = b.count_interior_nodes();
    //         cout << "\nCount : " << l << endl;
    //         break;
    //     case 13:
    //         cout << "\n\nDelete all Nodes\n\n";
    //         b.delete_tree(k);
    //         break;
    //     default:
    //         break;
    //     }
    // }
    return 0;
}

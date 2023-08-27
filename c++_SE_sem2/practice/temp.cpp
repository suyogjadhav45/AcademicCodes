#include <iostream>
using namespace std;

template <typename T>
class Node
{

    Node *next;
    T data;

public:
    Node()
    {
        next = NULL;
        // data = 0;
    }

    Node(T d)
    {
        next = NULL;
        data = d;
    }

    template <typename U>
    friend class Queue;
};

template <typename T>
class Queue
{
    Node<T> *front, *back;

public:
    Queue()
    {
        front = NULL;
        back = NULL;
    }

    void push(T data)
    {
        if (front == NULL)
        {
            front = new Node<T>(data);
            back = front;
        }
        else
        {
            back->next = new Node<T>(data);
            back = back->next;
        }
    }

    void pop()
    {

        if (front == NULL)
        {
            cout << "Queue is already empty" << endl;
            return;
        }

        Node<T> *temp = front;
        front = front->next;
        delete temp;
    }

    T frontData()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return 0;
        }
        else
        {
            return front->data;
        }
    }

    bool isEmpty()
    {
        return front == NULL;
    }

    int size()
    {
        int len = 0;
        Node<T> *temp = front;

        while (temp != NULL)
        {
            temp = temp->next;
            len++;
        }

        return len;
    }
};

class TreeNode
{
    int data;
    TreeNode *left, *right;

public:
    TreeNode()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }

    TreeNode(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }

    friend class BinaryTree;
};

class BinaryTree
{
    TreeNode *root;

public:
    BinaryTree()
    {
        root = NULL;
    }

    void insert()
    {
        Queue<TreeNode *> q;
        int rootData;
        cout << "Enter data of root: ";
        cin >> rootData;
        if (rootData == -1)
        {
            return;
        }

        root = new TreeNode(rootData);
        q.push(root);

        while (!q.isEmpty())
        {
            int leftD;
            int rightD;
            TreeNode *temp = q.frontData();
            q.pop();
            cout << "Enter left child of " << temp->data << ": ";
            cin >> leftD;
            cout << "Enter right child of " << temp->data << ": ";
            cin >> rightD;

            if (leftD != -1)
            {
                TreeNode *leftNode = new TreeNode(leftD);
                temp->left = leftNode;
                q.push(leftNode);
            }
            if (rightD != -1)
            {
                TreeNode *rightNode = new TreeNode(rightD);
                temp->right = rightNode;
                q.push(rightNode);
            }
        }
    }

    void inorderRecursive(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        inorderRecursive(root->left);
        cout << root->data << " ";
        inorderRecursive(root->right);
    }

    void postorderRecursive(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        postorderRecursive(root->left);
        postorderRecursive(root->right);
        cout << root->data << " ";
    }

    void preorderRecursive(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->data << " ";
        preorderRecursive(root->left);
        preorderRecursive(root->right);
    }

    TreeNode *getRoot()
    {
        return root;
    }
};

int main()
{
    BinaryTree T;
    T.insert();
    TreeNode *root = T.getRoot();
    cout << "Inorder:\n";
    T.inorderRecursive(root);
    cout << endl;
    cout << "Preorder:\n";
    T.preorderRecursive(root);
    cout << endl;
    cout << "Postorder:\n";
    T.postorderRecursive(root);
    cout << endl;
}

//============================================================================
// Name        : Assignment.cpp
// Author      : Atharva Walake
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// Binary tree implimentation
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

class node
{
    int data;
    node *left;
    node *right;

public:
    node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
    node()
    {
        data = -1;
        left = NULL;
        right = NULL;
    }
    friend class binary_tree;
};
class binary_tree
{
public:
    node *rootnode;
    int array[100];
    binary_tree()
    {
        rootnode = new node();
    }
    node *create(int n)
    {

        int x;
        cout << "Enter data ::";
        cin >> x;
        if (x == -1)
        {
            this->array[n] = -1;
            return NULL;
        }
        node *root = new node(x);
        this->array[n] = x;
        cout << "Enter the left for " << x << endl;
        root->left = create((2 * n) + 1);
        cout << "Enter the right for " << x << endl;
        root->right = create((2 * n) + 2);
        return root;
    }
    void operator=(const binary_tree &obj)
    {
        rootnode = obj.rootnode;
        for (int i; i < 100; i++)
        {
            array[i] = obj.array[i];
        }
        //        array = obj.array;
    }
    void preorder(node *root)
    {

        if (root == NULL)
        {
            return;
        }

        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void inorder(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
    void postorder(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
    void iterativepostorder(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        stack<node *> s1, s2;
        s1.push(root);
        node *node;
        while (!s1.empty())
        {
            node = s1.top();
            s1.pop();
            s2.push(node);
            if (node->left)
                s1.push(node->left);
            if (node->right)
                s1.push(node->right);
        }
        while (!s2.empty())
        {
            node = s2.top();
            s2.pop();
            cout << node->data << " ";
        }
    }
    void iterativeinorder(node *root)
    {
        stack<node *> s;
        node *curr = root;
        while (curr != NULL || !s.empty())
        {
            while (curr != NULL)
            {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            cout << curr->data << " ";
            curr = curr->right;
        }
    }
    void iterativepreorder(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        stack<node *> st;
        node *curr = root;
        while (!st.empty() && curr != NULL)
        {
            while (curr != NULL)
            {
                cout << curr->data << " ";
                if (curr->right)
                    st.push(curr->right);

                curr = curr->left;
            }
            if (st.empty() == false)
            {
                curr = st.top();
                st.pop();
            }
        }
    }
    void swaptree(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        node *temp;
        temp = root->left;
        root->left = root->right;
        root->right = temp;
        this->swaptree(root->left);
        this->swaptree(root->right);
    }
    int height(node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int leftH = this->height(root->left);
        int rightH = this->height(root->right);
        return max(leftH, rightH) + 1;
    }
    int leafCount(node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        if (root->left == NULL && root->right == NULL)
        {
            return 1;
        }
        return leafCount(root->left) + leafCount(root->right);
    }
    int countNonLeaf(node *root)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return 0;

        return 1 + countNonLeaf(root->left) + countNonLeaf(root->right);
    }
    void eraseAllNodes(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        eraseAllNodes(root->left);
        eraseAllNodes(root->right);
        cout << "\n\tNode Deleted :: " << root->data;
        delete root;
    }

    void print()
    {

        int ind = 1;
        vector<vector<int>> list;
        for (int i = 0; i < height(rootnode); i++)
        {
            vector<int> temp;
            for (int j = ind - 1; j < ind * 2 - 1; j++)
            {
                temp.push_back(array[j]);
            }
            list.push_back(temp);
            ind = ind << 1;
        }
        int spacing = (1 << (height(rootnode) - 1)) - 1;
        int no = 1 << (height(rootnode) - 1);

        for (int i = 0; i < height(rootnode); i++)
        {
            for (int space = 0; space < spacing; space++)
            {
                cout << " ";
            }
            vector<int> current = list.at(i);
            string spaceBT = "";
            for (int j = 0; j < (spacing << 1) + 1; j++)
            {
                spaceBT += " ";
            }
            for (long long unsigned int j = 0; j < current.size(); j++)
            {
                int x = current.at(j);
                if (x != -1)
                    cout << current.at(j) << spaceBT;
                else
                    cout << " " << spaceBT;
            }
            no = no >> 1;
            spacing -= no;
            cout << endl;
        }
    }
};

int main()
{
    int ch, ch2;
    binary_tree tree;
    binary_tree tree2;

    do
    {
        cout << "\n\n********Main*Menu********";
        cout << "\n1.Create A Tree";
        cout << "\n2.Inorder Traversal";
        cout << "\n3.Preorder Traversal";
        cout << "\n4.Postorder Traversal";
        cout << "\n5.Swap Left and Right Nodes";
        cout << "\n6.Height Of Tree";
        cout << "\n7.Print Tree";
        cout << "\n8.Count Number of Leaves";
        cout << "\n9.Count Number of Internal Nodes";
        cout << "\n10.Delete Every Node of Tree";
        cout << "\n11.Copy Tree";
        cout << "\n12.Exit";
        cout << "\n\n\tEnter Your Choice ::";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\nEnter Elements Of Tree(-1 for NULL)" << endl;
            tree.rootnode = tree.create(0);
            cout << "\nTree Created";
            break;

        case 2:
            cout << "\n1)Iterative";
            cout << "\n2)Recursive";
            cout << "\n\n\tEnter Your Choice ::";
            cin >> ch2;
            if (ch2 == 1)
            {
                cout << "\nInorder Iterative Traversal = ";
                tree.iterativeinorder(tree.rootnode);
                break;
            }
            else if (ch == 2)
            {
                cout << "\nInorder Recursive Traversal = ";
                tree.inorder(tree.rootnode);
                break;
            }
            else
            {
                cout << "\nEnter Valid Option";
                continue;
            }

            // cout << "\nInorder Traversal = ";
            // tree.inorder(tree.rootnode);
            // break;

        case 3:
            cout << "\n1)Iterative";
            cout << "\n2)Recursive";
            cout << "\n\n\tEnter Your Choice ::";
            cin >> ch2;
            if (ch2 == 1)
            {
                cout << "\nPreorder Iterative Traversal = ";
                tree.iterativepreorder(tree.rootnode);
                break;
            }
            else if (ch == 2)
            {
                cout << "\nPreorder Recursive Traversal = ";
                tree.preorder(tree.rootnode);
                break;
            }
            else
            {
                cout << "\nEnter Valid Option";
                continue;
            }

        case 4:
            cout << "\n1)Iterative";
            cout << "\n2)Recursive";
            cout << "\n\n\tEnter Your Choice ::";
            cin >> ch2;
            if (ch2 == 1)
            {
                cout << "\nPostorder Iterative Traversal = ";
                tree.iterativepostorder(tree.rootnode);
                break;
            }
            else if (ch == 2)
            {
                cout << "\nPostorder Recursive Traversal = ";
                tree.postorder(tree.rootnode);
                break;
            }
            else
            {
                cout << "\nEnter Valid Option";
                continue;
            }

        case 5:
            tree.swaptree(tree.rootnode);
            cout << "\nSwapped Inorder Tree ::";
            tree.inorder(tree.rootnode);
            break;

        case 6:
            cout << "\nHeight Of Tree :: " << tree.height(tree.rootnode);
            break;

        case 7:
            tree.print();
            break;

        case 8:
            cout << "\nNumber of Leaves :: " << tree.leafCount(tree.rootnode);
            break;

        case 9:
            cout << "\nNumber of Internal Nodes :: " << tree.countNonLeaf(tree.rootnode);
            break;

        case 10:
            tree.eraseAllNodes(tree.rootnode);
            break;

        case 12:
            cout << "\nProgram Exited";
            break;

        case 11:
            cout << "\nFirst Tree :" << endl;
            tree.print();
            cout << "\nsecond Tree" << endl;

            tree2 = tree;
            tree2.print();
            break;

        default:
            cout << "\nEnter Correct Option";
            break;
        }
    } while (ch != 12);

    //     // cout<<"\nStart: ";
    // 	binary_tree br;
    // 	br.rootnode = br.create();
    // 	cout<<"\nBR = ";
    // 	br.postorder(br.rootnode);
    // 	binary_tree cr2;
    // 	cr2 = br;
    // 	cout<<"\nCR2 = ";
    // 	cr2.postorder(cr2.rootnode);

    // //	cout<<"\nBefore :: ";
    // //	br.postorder(br.rootnode);
    // //	br.reverse_tree(br.rootnode);
    // //	cout<<"\nAfter :: ";
    // //	br.postorder(br.rootnode);
    // //	int h;
    // //	h = br.height(br.rootnode);
    // //
    // //	cout<<"\nHeight = "<<h;
    // 	// br.create();
    // 	// cout<<"\nEnd";
    // //	br.print_preorder();
    // //    br.print_postorder();
    // //    br.print_inorder();
    return 0;
}

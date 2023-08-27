#include <bits/stdc++.h>
using namespace std;

#define size 100

class Node
{

    string s;
    int weight;

public:
    Node()
    {
        s = "";
        weight = -1;
    }

    Node(string s, int w)
    {
        this->s = s;
        weight = w;
    }

    friend class Queue;
    friend class Spanning_Tree;
};

class Queue
{

    int front, rear;
    Node *arr[size];

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    void enqueue(Node *temp)
    {
        rear++;
        arr[rear] = temp;
        if (front == -1)
        {
            front++;
        }
    }

    Node *dequeue()
    {
        Node *temp = arr[front];
        front++;
        return temp;
    }

    bool is_empty()
    {

        if (front == -1 || front > rear)
        {
            return true;
        }
        return false;
    }

    friend class Spanning_Tree;
};

class Spanning_Tree
{

    int **AdjMatrix;
    int **MST;
    int **MST2;
    int vertices;

public:
    Spanning_Tree()
    {

        cout << "Enter the number of vertices: ";
        int v;
        cin >> v;
        vertices = v;

        AdjMatrix = new int *[v];
        MST = new int *[v];
        MST2 = new int *[v];

        for (int i = 0; i < v; i++)
        {
            AdjMatrix[i] = new int[v];
            MST[i] = new int[v];
            MST2[i] = new int[v];
        }
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                AdjMatrix[i][j] = 0;
                MST[i][j] = 0;
                MST2[i][j] = 0;
            }
        }
    }

    void Insert(int vertex1, int vertex2, int w);
    void Display();
    void MST_Prime();
    void Display_MST();
    void MST_Kruskal();
    void Display_MST2();
};

void Spanning_Tree::MST_Kruskal()
{

    bool reach[vertices];
    bool unreach[vertices];

    for (int i = 0; i < vertices; i++)
    {
        reach[i] = 0;
        unreach[i] = 1;
    }

    Queue q;
    int edges = 0;
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {

            if (AdjMatrix[i][j] != 0)
            {
                string s = to_string(i);
                s += to_string(j);
                Node *temp = new Node(s, AdjMatrix[i][j]);
                q.enqueue(temp);
                edges++;
            }
        }
    }

    for (int i = 0; i < edges; i++)
    {

        Node *temp1 = q.arr[i];
        for (int j = i; j < edges; j++)
        {

            Node *temp2 = q.arr[j];
            if (temp1->weight > temp2->weight)
            {

                string s1 = temp1->s;
                string s2 = temp2->s;
                int weight1 = temp1->weight;
                int weight2 = temp2->weight;

                temp2->weight = weight1;
                temp2->s = s1;
                temp1->s = s2;
                temp1->weight = weight2;
            }
        }
    }

    for (int i = 0; i < edges; i++)
    {

        if (!q.is_empty())
        {

            Node *temp = q.dequeue();
            string s = temp->s;
            int vertex1 = s[0] - '0';
            int vertex2 = s[1] - '0';
            if ((reach[vertex1] == 0 && reach[vertex2] == 0) || (reach[vertex1] == 0 && reach[vertex2] == 1) || (reach[vertex1] == 1 && reach[vertex2] == 0))
            {
                MST2[vertex1][vertex2] = 1;
                MST2[vertex2][vertex1] = 1;
                reach[vertex1] = 1;
                reach[vertex2] = 1;
                unreach[vertex1] = 0;
                unreach[vertex2] = 0;
            }
        }
    }
}

void Spanning_Tree::MST_Prime()
{

    bool reach[vertices];
    // bool unreach[vertices];
    for (int i = 0; i < vertices; i++)
    {
        reach[i] = 0;
        // unreach[i] = 1;
    }

    int vertex = 0;
    reach[vertex] = 1;
    // unreach[vertex] = 0;

    int count = 1;

    while (count < (vertices))
    {

        count = 0;
        int minimum = INT_MAX;
        int vertex1 = -1;
        int vertex2 = -1;
        for (int i = 0; i < vertices; i++)
        {

            if (reach[i] == 1)
            {

                for (int j = 0; j < vertices; j++)
                {

                    if (minimum > AdjMatrix[i][j] && AdjMatrix[i][j] != 0)
                    {

                        minimum = AdjMatrix[i][j];
                        vertex1 = i;
                        vertex2 = j;
                    }
                }
            }
        }

        if (reach[vertex1] == 1 && reach[vertex2])
        {

            AdjMatrix[vertex1][vertex2] = 0;
            AdjMatrix[vertex2][vertex1] = 0;
        }
        else
        {

            MST[vertex1][vertex2] = 1;
            MST[vertex2][vertex1] = 1;
            AdjMatrix[vertex1][vertex2] = 0;
            AdjMatrix[vertex2][vertex1] = 0;
            reach[vertex1] = 1;
            reach[vertex2] = 1;
            // unreach[vertex1] = 0;
            // unreach[vertex2] = 0;
        }

        for (int i = 0; i < vertices; i++)
        {
            if (reach[i] == 1)
            {
                count++;
            }
        }
    }
}

void Spanning_Tree::Display_MST2()
{

    cout << "  ";
    for (int i = 0; i < vertices; i++)
    {
        cout << i << "  ";
    }
    cout << endl;

    for (int i = 0; i < vertices; i++)
    {
        cout << i << " ";
        for (int j = 0; j < vertices; j++)
        {
            cout << MST2[i][j] << "  ";
        }
        cout << endl;
    }
}

void Spanning_Tree::Display_MST()
{

    cout << "  ";
    for (int i = 0; i < vertices; i++)
    {
        cout << i << "  ";
    }
    cout << endl;

    for (int i = 0; i < vertices; i++)
    {
        cout << i << " ";
        for (int j = 0; j < vertices; j++)
        {
            cout << MST[i][j] << "  ";
        }
        cout << endl;
    }
}

void Spanning_Tree::Display()
{
    cout << "  ";
    for (int i = 0; i < vertices; i++)
    {
        cout << i << "  ";
    }
    cout << endl;

    for (int i = 0; i < vertices; i++)
    {
        cout << i << "  ";
        for (int j = 0; j < vertices; j++)
        {
            cout << AdjMatrix[i][j] << "  ";
        }
        cout << endl;
    }
}

void Spanning_Tree::Insert(int vertex1, int vertex2, int w)
{

    AdjMatrix[vertex1][vertex2] = w;
    AdjMatrix[vertex2][vertex1] = w;
}

int main()
{

    Spanning_Tree s;

    cout << "Enter the number of edges: ";
    int e;
    cin >> e;
    char x;
    while (e > 0)
    {
        int v1, v2, w;
        cout << "Enter the vertex having edge: ";
        cin >> v1 >> v2;
        cout << "Enter the weight of edge: ";
        cin >> w;
        e -= 1;
        s.Insert(v1, v2, w);
        if (e == 0)
        {
            cout << "Do you want to continue inserting(y/n): ";
            cin >> x;
            if (x == 'y')
            {
                cout << "Enter the number of edges you want to add: ";
                cin >> e;
            }
        }
    }

    cout << "Do you want to print the matrix(y/n): ";
    cin >> x;
    if (x == 'y')
    {
        s.Display();
    }

    cout << "Do you want to print the MST using Primes Algorithm(y/n): ";
    cin >> x;
    if (x == 'y')
    {
        s.MST_Prime();
        cout << endl;
        cout << "/________Primes Minimum Spanning Tree________/" << endl;
        s.Display_MST();
    }

    cout << "Do you want to print the MST using Kruskal's Algorithm(y/n): ";
    cin >> x;
    if (x == 'y')
    {
        s.MST_Kruskal();
        cout << endl;
        cout << "/______Kruskal's Minimum Spanning Tree________/" << endl;
        s.Display_MST2();
    }

    return 0;
}
#include <iostream>
// #include <vector>
// #include <queue>
// #include <stack>
using namespace std;
class Node
{
    int dver;
    Node *next;

public:
    Node()
    {
        dver = -1;
        next = NULL;
    }
    Node(int f)
    {
        dver = f;
        next = NULL;
    }
    friend class Graph;
};

class Stack
{
    int top;
    int arr[10];

public:
    Stack()
    {
        top = -1;
        for (int i = 0; i < 10; i++)
        {
            arr[i] = 0;
        }
    }
    void push(int d)
    {
        top++;
        arr[top] = d;
    }
    int pop()
    {
        int v = arr[top];
        top--;
        return v;
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }
    friend class Graph;
};

class Queue
{
    int front, rear;
    int arrq[10];

public:
    Queue()
    {
        front = rear = -1;
        for (int i = 0; i < 10; i++)
        {
            arrq[i] = 0;
        }
    }
    void enqueue(int d)
    {
        if (front == -1)
        {
            front += 1;
        }
        rear += 1;
        arrq[rear] = d;
    }
    int dequeue()
    {
        if (front > rear)
        {
            return -1;
        }
        int v = arrq[front];
        front += 1;
        return v;
    }
    bool isEmpty()
    {
        if (front > rear)
        {
            return true;
        }
        return false;
    }
    friend class Graph;
};

class Graph
{
    int nver, nedges;
    Node **graphpt;

public:
    Graph()
    {
        cout << "\nEnter no of ver : ";
        cin >> nver;
        cout << "\nEnter no of edges : ";
        cin >> nedges;
        graphpt = new Node *[nver];
        for (int i = 0; i < nver; i++)
        {
            graphpt[i] = NULL;
        }
    }
    Graph(int v, int e)
    {
        nver = v;
        nedges = e;
        graphpt = new Node *[nver];
        for (int i = 0; i < nver; i++)
        {
            graphpt[i] = NULL;
        }
    }
    void insert()
    {
        for (int i = 0; i < nedges; i++)
        {
            int x, y;
            cout << "\nEnter starting and ending vertice : ";
            cin >> x >> y;
            Node *t = graphpt[x];
            Node *t1 = new Node(y);
            if (graphpt[x] == NULL)
            {
                graphpt[x] = t1;
            }
            else
            {
                while (t->next)
                {
                    t = t->next;
                }
                t->next = t1;
            }
        }
    }
    void disp_bfs()
    {
        int v;
        cout << "\nStarting vertex : ";
        cin >> v;
        bool visited[nver];
        for (int i = 0; i < nver; i++)
        {
            visited[i] = 0;
        }
        Node *p = graphpt[v];
        cout << "[ " << v << " ] ";
        visited[v] = 1;
        Queue q;
        q.enqueue(v);
        while (!q.isEmpty())
        {
            int k = q.dequeue();
            // q.pop();
            if (visited[k] == 0)
            {
                cout << "[ " << k << " ] ";
                visited[k] = 1;
            }
            p = graphpt[k];
            while (p)
            {
                if (visited[p->dver] == 0)
                {
                    q.enqueue(p->dver);
                }
                p = p->next;
            }
        }
    }
    void disp_dfs()
    {
        int v;
        cout << "\nStarting vertex : ";
        cin >> v;
        bool visited[nver];
        for (int i = 0; i < nver; i++)
        {
            visited[i] = 0;
        }
        Node *p = graphpt[v];
        cout << "[ " << v << " ] ";
        visited[v] = 1;
        Stack s;
        s.push(v);
        while (!s.isEmpty())
        {
            int k = s.pop();
            // s.pop();
            if (visited[k] == 0)
            {
                cout << "[ " << k << " ] ";
                visited[k] = 1;
            }
            p = graphpt[k];
            while (p)
            {
                if (visited[p->dver] == 0)
                {
                    s.push(p->dver);
                }
                p = p->next;
            }
        }
    }
};
int main()
{
    Graph g;
    g.insert();
    g.disp_bfs(); // cout << "\n\nhi\n";
    cout << endl;
    g.disp_dfs();
    return 0;
}
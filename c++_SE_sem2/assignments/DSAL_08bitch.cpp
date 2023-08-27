#include <iostream>
using namespace std;
#define max 10
class Queue
{
public:
    int arr[max];
    int front, rear;
    Queue()
    {
        front = -1;
        rear = -1;
    }
    void push(int x)
    {
        if (rear == max - 1)
        {
            cout << "\nOverflow" << endl;
            return;
        }
        rear++;
        arr[rear] = x;
        if (front == -1)
        {
            front++;
        }
    }
    int peek()
    {
        return arr[front];
    }
    void pop()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is Empty " << endl;
            return;
        }
        front++;
    }
    bool isEmpty()
    {
        if (front == -1 || front > rear)
        {
            return true;
        }
        return false;
    }
    bool isFull()
    {
        if (rear == max - 1)
        {
            return true;
        }
        return false;
    }
    void Display()
    {
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }
};
class Graph
{
public:
    int v, e;
    bool adjMat[10][10];

    Graph()
    {
        cout << "\nEnter Number of Vertices ::";
        cin >> v;
        cout << "\nEnter Number of Edges    ::";
        cin >> e;
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                adjMat[i][j] = false;
            }
        }
    }
    void addEdge(int s, int d)
    {
        adjMat[s][d] = true;
        // cout<<"\nEdge Added";
    }
    void Display()
    {
        cout << endl;
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                cout << adjMat[i][j] << " ";
            }
            cout << endl;
        }
    }
    int inDegree(int x)
    {
        int cnt = 0;
        for (int i = 0; i < v; i++)
        {
            cnt += adjMat[i][x];
        }
        return cnt;
    }
    void topologicalSort()
    {
        int indeg[10], count = 0;
        bool visited[10];
        for (int i = 0; i < v; i++)
        {
            visited[i] = false;
            indeg[i] = inDegree(i);
        }
        cout << "\nTopological =";
        Queue q;
        while (count < v)
        {
            // cout<<"inwhile"<<endl;
            // indeg konta 0 ahe ka
            // asel tr que madhe push
            // q madhun pop
            for (int i = 0; i < v; i++)
            {
                if (indeg[i] == 0 and visited[i] == false)
                {
                    q.push(i);
                    // q.Display();
                    visited[i] = true;
                }
            }
            while (!q.isEmpty())
            {
                int x = q.peek();
                q.pop();
                cout << x << " ";
                count++;
                for (int j = 0; j < v; j++)
                {
                    if (adjMat[x][j] == 1)
                    {
                        indeg[j]--;
                    }
                }
            }
        }
    }
};
int main()
{
    Graph g;
    for (int i = 0; i < g.e; i++)
    {
        int s, d;
        cout << "\nEnter Source ::";
        cin >> s;
        cout << "\nEnter Destination ::";
        cin >> d;
        g.addEdge(s, d);
    }
    g.Display();
    g.topologicalSort();
    return 0;
}
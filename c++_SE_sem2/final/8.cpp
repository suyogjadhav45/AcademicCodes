//============================================================================
// Name        : DSAL_08.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Nodever
{
    int destver;
    Nodever *next;

public:
    Nodever()
    {
        destver = -1;
        next = NULL;
    }
    Nodever(int destver)
    {
        this->destver = destver;
        next = NULL;
    }
    friend class Graph;
};

class Queue
{
    int front, rear;
    int arrqu[10];

public:
    Queue()
    {
        front = -1;
        rear = -1;
        for (int i = 0; i < 10; i++)
        {
            arrqu[i] = 0;
        }
    }
    void enqueue(int v)
    {
        if (front == -1)
        {
            front += 1;
        }
        rear += 1;
        arrqu[rear] = v;
    }

    int dequeue()
    {
        if (front > rear)
        {
            return -1;
        }
        int v = arrqu[front];
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
    Nodever **graphpt;
    int *indeg;

public:
    Graph()
    {
        cout << "\nEnter the Number of Vertices -----> ";
        cin >> nver;
        cout << "\nEnter the Number of Edges -----> ";
        cin >> nedges;
        indeg = new int[nver];
        graphpt = new Nodever *[nver];
        for (int i = 0; i < nver; i++)
        {
            graphpt[i] = NULL;
            indeg[i] = 0;
        }
    }
    Graph(int nver, int nedges)
    {
        this->nver = nver;
        this->nedges = nedges;
        graphpt = new Nodever *[nver];
        indeg = new int[nver];
        for (int i = 0; i < nver; i++)
        {
            graphpt[i] = NULL;
            indeg[i] = 0;
        }
    }
    void insert_edges()
    {
        for (int i = 0; i < nedges; i++)
        {
            int x, y;
            cout << "\nEnter vertices having edge between them -----> ";
            cin >> x >> y;
            Nodever *t = graphpt[x];
            Nodever *t1 = new Nodever(y);
            indeg[y] += 1;
            // cout << "\n"
            //      << indeg[y];
            if (t == NULL)
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

    void display()
    {
        cout << "\n----------------DISPLAY GRAPH----------------\n"
             << endl;
        for (int i = 0; i < nver; i++)
        {
            Nodever *p = graphpt[i];
            cout << " [ " << i << " ]";
            while (p)
            {
                cout << " ---> [ " << p->destver << " ] ";
                p = p->next;
            }
            cout << "\n";
        }
    }

    void display_indeg()
    {
        cout << "\n----------------DISPLAY IN-DEGREE ARRAY----------------\n"
             << endl;
        for (int i = 0; i < nver; i++)
        {
            cout << "In Degree of " << i << " ---> " << indeg[i] << endl;
        }
    }

    void topo_sort()
    {
        cout << "\n----------------TOPOLOGICAL SORT----------------\n"
             << endl;
        Queue q;

        for (int i = 0; i < nver; i++)
        {
            if (indeg[i] == 0)
            {
                q.enqueue(i);
            }
        }

        while (!q.isEmpty())
        {
            int s = q.dequeue();
            cout << s << " ";
            Nodever *temp = graphpt[s];
            while (temp != NULL)
            {
                indeg[temp->destver]--;
                if (indeg[temp->destver] == 0)
                {
                    q.enqueue(temp->destver);
                }
                temp = temp->next;
            }
        }
        cout << endl;
    }
};

int main()
{
    // cout << "!!!Hello Worlddd!!!" << endl; // prints !!!Hello World!!!
    Graph a;
    a.insert_edges();
    a.display();
    a.display_indeg();
    a.topo_sort();

    return 0;
}
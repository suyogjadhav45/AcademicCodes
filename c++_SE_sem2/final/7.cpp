#include <iostream>
using namespace std;
class SpanningTree
{
    int **adj;
    int **mst;
    int nver;

public:
    SpanningTree()
    {
        cout << "\nEnter number of vertices : ";
        cin >> nver;
        adj = new int *[nver];
        mst = new int *[nver];
        for (int i = 0; i < nver; i++)
        {
            adj[i] = new int[nver];
            mst[i] = new int[nver];
        }
        for (int i = 0; i < nver; i++)
        {
            for (int j = 0; j < nver; j++)
            {
                adj[i][j] = 0;
                mst[i][j] = 0;
            }
        }
    }
    void insert(int v1, int v2, int wt);
    void prime_mst();
    void display_prime();
    void display_adj();
};
void SpanningTree ::insert(int v1, int v2, int wt)
{
    adj[v1][v2] = wt;
    adj[v2][v1] = wt;
}
void SpanningTree ::prime_mst()
{
    bool reach[nver];
    for (int i = 0; i < nver; i++)
    {
        reach[i] = 0;
    }
    int v = 0;
    reach[v] = 1;
    int count = 0;
    while (count < nver)
    {
        count = 0;
        int min = 999;
        int v1, v2;
        for (int i = 0; i < nver; i++)
        {
            if (reach[i] == 1)
            {
                for (int j = 0; j < nver; j++)
                {
                    if (min > adj[i][j] && adj[i][j] != 0)
                    {
                        min = adj[i][j];
                        v1 = i;
                        v2 = j;
                    }
                }
            }
        }
        if (reach[v2] == 1)
        {
            adj[v1][v2] = 0;
            adj[v2][v1] = 0;
        }
        else
        {
            mst[v1][v2] = 1;
            mst[v2][v1] = 1;
            adj[v1][v2] = 0;
            adj[v2][v1] = 0;
            reach[v2] = 1;
        }
        for (int i = 0; i < nver; i++)
        {
            if (reach[i] == 1)
            {
                count++;
            }
        }
    }
}
void SpanningTree ::display_adj()
{
    cout << "\t";
    for (int i = 0; i < nver; i++)
    {
        cout << i << "\t";
    }
    cout << endl;
    for (int i = 0; i < nver; i++)
    {
        cout << i << "\t";
        for (int j = 0; j < nver; j++)
        {
            cout << adj[i][j] << "\t";
        }
        cout << endl;
    }
}
void SpanningTree ::display_prime()
{
    cout << "\t";
    for (int i = 0; i < nver; i++)
    {
        cout << i << "\t";
    }
    cout << endl;
    for (int i = 0; i < nver; i++)
    {
        cout << i << "\t";
        for (int j = 0; j < nver; j++)
        {
            cout << mst[i][j] << "\t";
        }
        cout << endl;
    }
}
int main()
{
    SpanningTree s;
    int e, v1, v2, w;
    cout << "\nEnter number of Edges : ";
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        cout << "\nEnter starting and ending vertices : ";
        cin >> v1 >> v2;
        cout << "\nEnter Weight of an edge : ";
        cin >> w;
        s.insert(v1, v2, w);
    }
    cout << "\nh\n";
    s.display_adj();
    s.prime_mst();
    cout << "\nhh\n";
    s.display_prime();
    return 0;
}
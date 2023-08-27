#include <bits/stdc++.h>
using namespace std;

void lamports(int e1, int e2, vector<vector<int>> m)
{
    vector<int> p1(e1, -1);
    vector<int> p2(e2, -1);
    for (int i = 0; i < e1; i++)
    {
        /* code */
        p1[i] = i + 1;
    }
    for (int i = 0; i < e2; i++)
    {
        /* code */
        p2[i] = i + 1;
    }
    for (int i = 0; i < e1; i++)
    {
        /* code */
        for (int j = 0; j < e2; j++)
        {
            /* code */
            if (m[i][j] == 1)
            {
                p2[j] = max(p2[j], p1[i] + 1);
                for (int k = j + 1; k < e2; k++)
                {
                    /* code */
                    p2[k] = p2[k - 1] + 1;
                }
            }
            if (m[i][j] == -1)
            {
                p1[i] = max(p1[i], p2[j] + 1);
                for (int k = 0; i + 1 < e1; k++)
                {
                    /* code */
                    p1[k] = p1[k - 1] + 1;
                }
            }
        }
    }
    cout << "Time stamps of events in proess P1 : \n";
    for (auto i : p1)
    {
        cout << i << "  ";
    }
    cout << endl;
    cout << "Time stamps of events in proess P2 : \n";
    for (auto i : p2)
    {
        cout << i << "  ";
    }
    cout << endl;

    return;
}

void ntp(int hr, int mn)
{

    int t1, t2, t3, t4;
    cout << "input t1,t2,t3,t4 : ";
    cin >> t1 >> t2 >> t3 >> t4;
    float delay = 99999;
    float off = 99999;
    for (float i = -0.3; i < 0.4; i += 0.1)
    {
        float dl, of;
        dl = (float(((t4 + i) - (t1 + i))) - ((t3 + i) - (t2 + i))) / float(2);
        of = (float(((t2 + i) - (t1 + i))) + ((t3 + i) - (t4 + i))) / float(2);
        if (delay > abs(dl))
        {
            delay = abs(dl);
            off = of;
        }
    }
    cout << "delay : " << int(delay) << endl;
    cout << "offset : " << int(off) << endl;
    mn += off;
    if (abs(mn) > 60)
    {
        while (abs(mn) > 60)
        {
            hr++;
            mn = abs(mn) - 60;
        }
    }

    cout << "Final Time --> " << hr << " : " << mn << endl;
}

int main()
{
    cout << "\nLamports\n";
    // int e1, e2;
    // cin >> e1 >> e2;
    // vector<vector<int>> m;
    // for (int i = 0; i < e1; i++)
    // {
    //     /* code */
    //     vector<int> temp;
    //     for (int j = 0; j < e2; j++)
    //     {
    //         /* code */
    //         int a;
    //         cin >> a;
    //         temp.push_back(a);
    //     }
    //     m.push_back(temp);
    // }

    // lamports(e1, e2, m);

    cout << "\nNTP\n";
    int hr, mn;
    cin >> hr >> mn;
    ntp(hr, mn);
    cout << "\nExecuted\n";

    return 0;
}
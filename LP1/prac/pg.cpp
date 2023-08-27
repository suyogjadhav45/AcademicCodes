#include <bits/stdc++.h>
using namespace std;

void fifo(vector<int> pages, int framesize)
{

    int n = pages.size();
    int curr = 0;
    int pgfault = 0;
    int pghit = 0;
    set<int> s;
    vector<int> frame;
    for (int i = 0; i < n; i++)
    {
        /* code */
        if (s.size() < framesize)
        {
            cout << pages[i] << "---> ";
            if (s.find(pages[i]) == s.end())
            {
                pgfault++;
                s.insert(pages[i]);
                frame.push_back(pages[i]);
                for (int j = 0; j < frame.size(); j++)
                {
                    /* code */
                    cout << frame[j] << " ";
                }
                cout << "Page Fault Occured";
            }
            else
            {
                pghit++;
                for (int j = 0; j < frame.size(); j++)
                {
                    /* code */
                    cout << frame[j] << " ";
                }
                cout << "Page Hit Occured";
            }
            cout << endl;
        }
        else
        {
            cout << pages[i] << "---> ";
            if (s.find(pages[i]) == s.end())
            {
                auto todelete = s.find(*(frame.begin() + curr));
                s.erase(todelete);
                s.insert(pages[i]);
                frame[curr] = pages[i];
                curr = (curr + 1) % 3;
                pgfault++;
                for (int j = 0; j < frame.size(); j++)
                {
                    /* code */
                    cout << frame[j] << " ";
                }
                cout << "Page Fault Occured";
            }
            else
            {
                pghit++;
                for (int j = 0; j < frame.size(); j++)
                {
                    /* code */
                    cout << frame[j] << " ";
                }
                cout << "Page Hit Occured";
            }
            cout << endl;
        }
    }
    cout << "Total Page Faults : " << pgfault << endl;
    cout << "Total Page Hits : " << pghit << endl;
}

int lru_function(vector<int> pages, vector<int> frame, int minimumidx)
{
    int index = 0;
    int minidx = minimumidx;
    for (int i = 0; i < frame.size(); i++)
    {
        /* code */
        for (int j = minimumidx; j >= 0; j--)
        {
            if (frame[i] == pages[j])
            {
                if (j < minidx)
                {
                    minidx = j;
                    index = i;
                }
                break;
            }
        }
    }
    return index;
}

void lru(vector<int> pages, int framesize)
{
    int n = pages.size();
    int curr = 0;
    int pgfault = 0;
    int pghit = 0;
    set<int> s;
    vector<int> frame;
    for (int i = 0; i < n; i++)
    {
        /* code */
        if (s.size() < framesize)
        {
            cout << pages[i] << "---> ";
            if (s.find(pages[i]) == s.end())
            {
                pgfault++;
                s.insert(pages[i]);
                frame.push_back(pages[i]);
                for (int j = 0; j < frame.size(); j++)
                {
                    /* code */
                    cout << frame[j] << " ";
                }
                cout << "Page Fault Occured";
            }
            else
            {
                pghit++;
                for (int j = 0; j < frame.size(); j++)
                {
                    /* code */
                    cout << frame[j] << " ";
                }
                cout << "Page Hit Occured";
            }
            cout << endl;
        }
        else
        {
            cout << pages[i] << "---> ";
            if (s.find(pages[i]) == s.end())
            {
                int replace = lru_function(pages, frame, i - 1);
                auto todelete = s.find(*(frame.begin() + replace));
                s.erase(todelete);
                s.insert(pages[i]);
                frame[replace] = pages[i];
                // curr = (curr + 1) % 3;
                pgfault++;
                for (int j = 0; j < frame.size(); j++)
                {
                    /* code */
                    cout << frame[j] << " ";
                }
                cout << "Page Fault Occured";
            }
            else
            {
                pghit++;
                for (int j = 0; j < frame.size(); j++)
                {
                    /* code */
                    cout << frame[j] << " ";
                }
                cout << "Page Hit Occured";
            }
            cout << endl;
        }
    }
    cout << "Total Page Faults : " << pgfault << endl;
    cout << "Total Page Hits : " << pghit << endl;
}

int optimal_function(vector<int> pages, vector<int> frame, int maxidx)
{
    int cur = maxidx;
    int index;
    for (int i = 0; i < frame.size(); i++)
    {
        /* code */
        bool flag = 0;
        for (int j = maxidx; j < pages.size(); j++)
        {
            if (frame[i] == pages[j])
            {
                if (j > cur)
                {
                    cur = j;
                    index = i;
                }
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            return i;
        }
    }
    return index;
}

void optimal(vector<int> pages, int framesize)
{
    int n = pages.size();
    int curr = 0;
    int pgfault = 0;
    int pghit = 0;
    set<int> s;
    vector<int> frame;
    for (int i = 0; i < n; i++)
    {
        /* code */
        if (s.size() < framesize)
        {
            cout << pages[i] << "---> ";
            if (s.find(pages[i]) == s.end())
            {
                pgfault++;
                s.insert(pages[i]);
                frame.push_back(pages[i]);
                for (int j = 0; j < frame.size(); j++)
                {
                    /* code */
                    cout << frame[j] << " ";
                }
                cout << "Page Fault Occured";
            }
            else
            {
                pghit++;
                for (int j = 0; j < frame.size(); j++)
                {
                    /* code */
                    cout << frame[j] << " ";
                }
                cout << "Page Hit Occured";
            }
            cout << endl;
        }
        else
        {
            cout << pages[i] << "---> ";
            if (s.find(pages[i]) == s.end())
            {
                int replace = optimal_function(pages, frame, i + 1);
                auto todelete = s.find(*(frame.begin() + replace));
                s.erase(todelete);
                s.insert(pages[i]);
                frame[replace] = pages[i];
                // curr = (curr + 1) % 3;
                pgfault++;
                for (int j = 0; j < frame.size(); j++)
                {
                    /* code */
                    cout << frame[j] << " ";
                }
                cout << "Page Fault Occured";
            }
            else
            {
                pghit++;
                for (int j = 0; j < frame.size(); j++)
                {
                    /* code */
                    cout << frame[j] << " ";
                }
                cout << "Page Hit Occured";
            }
            cout << endl;
        }
    }
    cout << "Total Page Faults : " << pgfault << endl;
    cout << "Total Page Hits : " << pghit << endl;
}

int main()
{
    int n;
    cout << "n : " << endl;
    cin >> n;
    vector<int> pages(n);
    for (int i = 0; i < n; i++)
    {
        /* code */
        cin >> pages[i];
    }
    int fsize;
    cout << "Framesize : ";
    cin >> fsize;
    cout << "\n\n---- FIFO ----\n\n";
    fifo(pages, fsize);
    cout << "\n\n---- LRU ----\n\n";
    lru(pages, fsize);

    cout << "\n\n---- Optimal ----\n\n";
    optimal(pages, fsize);

    return 0;
}
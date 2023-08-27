#include <bits/stdc++.h>
using namespace std;

void FIFO(vector<int> pages, int frameSize)
{
    int noOfPages = pages.size();
    int pageFaults = 0, pageHits = 0;
    set<int> s;
    vector<int> frames;
    int currentTop = 0;
    for (int i = 0; i < noOfPages; i++)
    {
        cout << pages[i] << " --->  ";
        if (s.size() < frameSize)
        {
            if (s.find(pages[i]) == s.end())
            {
                frames.push_back(pages[i]);
                s.insert(pages[i]);
                pageFaults++;
                for (int i = 0; i < frames.size(); i++)
                {
                    cout << frames[i] << "  ";
                }
                cout << "Page Fault Occured" << endl;
            }
            else
            {
                pageHits++;
                for (int i = 0; i < frames.size(); i++)
                {
                    cout << frames[i] << "  ";
                }
                cout << "Page Hit Occured" << endl;
            }
        }
        else
        {
            if (s.find(pages[i]) == s.end())
            {
                auto toDelete = s.find(*(frames.begin() + currentTop));
                s.erase(toDelete);
                frames[currentTop] = pages[i];
                s.insert(pages[i]);
                currentTop = (currentTop + 1) % frameSize;
                pageFaults++;
                for (int i = 0; i < frames.size(); i++)
                {
                    cout << frames[i] << "  ";
                }
                cout << "Page Fault Occured" << endl;
            }
            else
            {
                pageHits++;
                for (int i = 0; i < frames.size(); i++)
                {
                    cout << frames[i] << "  ";
                }
                cout << "Page Hit Occured" << endl;
            }
        }
    }
    cout << "No. of Page Faults : " << pageFaults << endl;
    cout << "No. of Page Hits   : " << pageHits << endl;
}

int leastRecentlyUsedIndex(vector<int> frames, vector<int> pages, int current)
{
    int frameSize = frames.size();
    int index;
    int minIndex = current;
    for (int i = 0; i < frameSize; i++)
    {
        for (int j = current; j >= 0; j--)
        {
            if (frames[i] == pages[j])
            {
                if (j < minIndex)
                {
                    minIndex = j;
                    index = i;
                }
                break;
            }
        }
    }
    return index;
}

void LRU(vector<int> pages, int frameSize)
{
    int noOfPages = pages.size();
    int pageFaults = 0, pageHits = 0;
    set<int> s;
    vector<int> frames;
    int toReplace = 0;
    for (int i = 0; i < noOfPages; i++)
    {
        cout << pages[i] << " --->  ";
        if (s.size() < frameSize)
        {
            if (s.find(pages[i]) == s.end())
            {
                frames.push_back(pages[i]);
                s.insert(pages[i]);
                pageFaults++;
                for (int i = 0; i < frames.size(); i++)
                {
                    cout << frames[i] << "  ";
                }
                cout << "Page Fault Occured" << endl;
            }
            else
            {
                pageHits++;
                for (int i = 0; i < frames.size(); i++)
                {
                    cout << frames[i] << "  ";
                }
                cout << "Page Hit Occured" << endl;
            }
        }
        else
        {
            if (s.find(pages[i]) == s.end())
            {
                toReplace = leastRecentlyUsedIndex(frames, pages, i - 1);
                auto toDelete = s.find(*(frames.begin() + toReplace));
                s.erase(toDelete);
                frames[toReplace] = pages[i];
                s.insert(pages[i]);
                pageFaults++;
                for (int i = 0; i < frames.size(); i++)
                {
                    cout << frames[i] << "  ";
                }
                cout << "Page Fault Occured" << endl;
            }
            else
            {
                pageHits++;
                for (int i = 0; i < frames.size(); i++)
                {
                    cout << frames[i] << "  ";
                }
                cout << "Page Hit Occured" << endl;
            }
        }
    }
    cout << "No. of Page Faults : " << pageFaults << endl;
    cout << "No. of Page Hits   : " << pageHits << endl;
}

int optimalIndex(vector<int> frames, vector<int> pages, int current)
{
    int frameSize = frames.size();
    int pageSize = pages.size();
    int index;
    int maxIndex = current;
    for (int i = 0; i < frameSize; i++)
    {
        int flag = 1;
        for (int j = current; j < pageSize; j++)
        {
            if (frames[i] == pages[j])
            {
                if (j > maxIndex)
                {
                    maxIndex = j;
                    index = i;
                }
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            return i;
        }
    }
    return index;
}

void Optimal(vector<int> pages, int frameSize)
{
    int noOfPages = pages.size();
    int pageFaults = 0, pageHits = 0;
    set<int> s;
    vector<int> frames;
    int toReplace = 0;
    for (int i = 0; i < noOfPages; i++)
    {
        cout << pages[i] << " --->  ";
        if (s.size() < frameSize)
        {
            if (s.find(pages[i]) == s.end())
            {
                frames.push_back(pages[i]);
                s.insert(pages[i]);
                pageFaults++;
                for (int i = 0; i < frames.size(); i++)
                {
                    cout << frames[i] << "  ";
                }
                cout << "Page Fault Occured" << endl;
            }
            else
            {
                pageHits++;
                for (int i = 0; i < frames.size(); i++)
                {
                    cout << frames[i] << "  ";
                }
                cout << "Page Hit Occured" << endl;
            }
        }
        else
        {
            if (s.find(pages[i]) == s.end())
            {
                toReplace = optimalIndex(frames, pages, i + 1);
                auto toDelete = s.find(*(frames.begin() + toReplace));
                s.erase(toDelete);
                frames[toReplace] = pages[i];
                s.insert(pages[i]);
                pageFaults++;
                for (int i = 0; i < frames.size(); i++)
                {
                    cout << frames[i] << "  ";
                }
                cout << "Page Fault Occured" << endl;
            }
            else
            {
                pageHits++;
                for (int i = 0; i < frames.size(); i++)
                {
                    cout << frames[i] << "  ";
                }
                cout << "Page Hit Occured" << endl;
            }
        }
    }
    cout << "No. of Page Faults : " << pageFaults << endl;
    cout << "No. of Page Hits   : " << pageHits << endl;
}

int main()
{
    int noOfPages, frameSize;
    cout << "Enter the no. of the pages : ";
    cin >> noOfPages;
    vector<int> pages;
    for (int i = 0; i < noOfPages; i++)
    {
        int elem;
        cin >> elem;
        pages.push_back(elem);
    }
    cout << "Enter the size of frame : ";
    cin >> frameSize;
    cout << "FIFO : " << endl;
    FIFO(pages, frameSize);
    cout << "LRU : " << endl;
    LRU(pages, frameSize);
    cout << "OPTIMAL : " << endl;
    Optimal(pages, frameSize);
    return 0;
}
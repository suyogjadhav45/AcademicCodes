#include <iostream>
using namespace std;

class MinHeap
{
    int cap, size;
    int *harr;

public:
    MinHeap(int k)
    {
        cap = k;
        size = k;
        harr = new int[k];
    }
    int parent(int i)
    {
        return (i - 1) / 2;
    }
    int right(int i)
    {
        return (2 * i + 2);
    }
    int left(int i)
    {
        return (2 * i + 1);
    }
    void printarr()
    {
        for (int i = 0; i < cap; i++)
        {
            cout << harr[i] << "\t";
        }
        cout << endl;
    }
    void swap(int &a, int &b)
    {
        int t = a;
        a = b;
        b = t;
    }
    void minheapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < size && harr[l] < harr[i])
        {
            smallest = l;
        }
        if (r < size && harr[r] < harr[smallest])
        {
            smallest = r;
        }
        if (smallest != i)
        {
            swap(harr[i], harr[smallest]);
            minheapify(smallest);
        }
    }
    int extract_min()
    {
        if (size == 0)
        {
            return 999;
        }
        if (size == 1)
        {
            size--;
            return harr[0];
        }
        int root = harr[0];
        harr[0] = harr[size - 1];
        size--;
        minheapify(0);
        return root;
    }
    void heap_sort()
    {
        for (int i = cap / 2 - 1; i >= 0; i--)
        {
            minheapify(i);
        }
        int temp[cap];
        for (int i = 0; i < cap; i++)
        {
            temp[i] = extract_min();
            cout << temp[i] << "\t";
        }
        cout << endl;
    }
    void inputarr()
    {
        cout << "\nEnter the Numbers : ";
        for (int i = 0; i < cap; i++)
        {
            cin >> harr[i];
        }
    }
};

int main()
{
    int s;
    cout << "Enter Size of Min Heap" << endl;
    cin >> s;
    MinHeap m(s);
    m.inputarr();
    m.printarr();
    m.heap_sort();
    return 0;
}
#include <iostream>
using namespace std;

class MinHeap
{
    int arr[50];

public:
    MinHeap()
    {
        for (int i = 0; i < 50; i++)
        {
            arr[i] = -1;
        }
    }

    void insert(int x)
    {
        int c = 0;
        int i = 0;
        int temp;
        while (arr[c] != -1 && c < 50)
        {
            c++;
        }
        arr[c] = x;
        i = c;
        temp = arr[c];
        while (i > 0 && temp < arr[i / 2])
        {
            arr[i] = arr[i / 2];
            i = i / 2;
        }
        arr[i] = temp;
    }

    void display()
    {
        for (int i = 0; i < 10; i++)
        {
            cout << arr[i] << " ";
        }
    }

    int delete_element()
    {
        int c = 0;
        int i;
        int j, x, temp, minimum;
        minimum = arr[0];
        while (arr[c] != -1 && c < 50)
        {
            c++;
        }
        c--;
        x = arr[c];

        arr[0] = x;
        i = 0;
        j = 1;
        while (j < c - 1 || (j == 1 && c == 2))
        {
            if (arr[j + 1] < arr[j])
            {
                j = j + 1;
            }
            if (arr[j] < arr[i])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i = j;
                j = 2 * j;
            }
            else
            {
                break;
            }
        }
        arr[c] = -1;
        return minimum;
    }
};

class Heapsort
{
public:
    int a[10];
    MinHeap M;

    void sort()
    {
        int x;
        cout << "Enter elements to be sorted";
        for (int i = 0; i < 5; i++)
        {
            cout << "\nEnter Element : ";
            cin >> a[i];
        }

        for (int i = 0; i < 5; i++)
        {
            M.insert(a[i]);
        }

        for (int i = 0; i < 5; i++)
        {
            a[i] = M.delete_element();
            M.display();
            cout << "\n";
        }

        cout << "\nThe sorted Array is ";
        for (int i = 0; i < 5; i++)
        {
            cout << a[i] << " ";
        }
    }
};

int main()
{
    /*MinHeap m;
    m.insert(10);
    m.insert(2);
    m.insert(3);
    m.display();
    m.insert(20);
    cout << "\n";
    m.display();
    m.delete_element();
    cout << "\n";
    m.display();*/
    Heapsort s;
    s.sort();
}
#include <iostream>
#include <limits>
using namespace std;

template <class T>

T selection_sort()
{
    int k;
    cout << "Enter the total count of numbers u want to insert : ";
    cin >> k;
    T a[k];
    T temp;
    for (int i = 0; i < k; i++)
    {
        cout << "a[" << i << "]=";
        cin >> a[i];
    }

    for (int i = 0; i < k; i++)
    {
        for (int j = i + 1; j < k; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    cout << "\n--------------Sorted list----------------\n";
    for (int i = 0; i < k; i++)
    {
        cout << a[i] << "  ";
    }
    cout << "\n-------------------//----------------------";
}

int main()
{

    cout << "Sorting Integer Array\n";

    selection_sort<int>();

    cout << "\n\nSorting Floating Array\n";

    selection_sort<float>();
}
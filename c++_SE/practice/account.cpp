#include <iostream>
using namespace std;

int main()
{
    int T, x1[T], x2[T];
    for (int i = 0; i < T; i++)
    {
        cin >> x1[i] >> x2[i];
    }
    for (int k = 0; k < T; k++)
    {
        if (x1[k] >= x2[k])
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}

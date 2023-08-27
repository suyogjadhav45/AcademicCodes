/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#define size 10
using namespace std;

class Mobile
{
    string name;
    long int n;

public:
    Mobile()
    {
        name = "--";
        n = 0;
    }
    Mobile(string name, long int n)
    {
        this->name = name;
        this->n = n;
    }
    friend class HashTable;
};

class HashTable
{
    Mobile hn[size];

public:
    int hash(long int x)
    {
        return (x % size);
    }
    int search(long int k)
    {
        for (int i = 0; i < size; i++)
        {
            if (hn[i].n == k)
            {
                return i;
            }
        }
    }
    int search_hash(int k)
    {
        for (int i = 0; i < size; i++)
        {
            int pos = hash(hn[i].n);
            if (k == pos)
            {
                return i;
            }
        }
    }

    void insert_without(string x, long int y)
    {
        Mobile p;
        p.name = x;
        p.n = y;
        int pos = hash(y);
        if (hn[pos].n == 0)
        {
            hn[pos] = p;
        }
        else
        {
            for (int i = pos + 1; i != pos; i++)
            {
                if (hn[i].n == 0)
                {
                    hn[i] = p;
                    return;
                }
                if (i == size)
                {
                    i = 0;
                }
            }
        }
    }

    void insert_with(string x, long int y)
    {
        Mobile p;
        p.name = x;
        p.n = y;
        int pos = hash(y);
        if (hn[pos].n == 0)
        {
            hn[pos] = p;
        }
        else
        {
            int k = hash(hn[pos].n);
            if (k != pos)
            {
                Mobile t = hn[pos];
                hn[pos] = p;
                insert_without(t.name, t.n);
            }
            else
            {
                insert_without(x, y);
            }
        }
    }

    void delete_fn(long int k)
    {
        int pos = hash(k);
        int s = search(k);
        hn[s].name = "--";
        hn[s].n = 0;
        int a = search_hash(s);
        if (s == pos && a)
        {
            hn[s] = hn[a];
            hn[a].name = "--";
            hn[a].n = 0;
        }
    }

    void display_hashtable()
    {
        cout << "\n\n---------------HASH TABLE------------------\n";
        cout << "\nIndex\t\tName\t\tMobile Number\n"
             << endl;
        for (int i = 0; i < size; i++)
        {
            cout << i << "\t\t" << hn[i].name << "\t\t" << hn[i].n << endl;
        }
        cout << "\n---------------------------------------------\n";
    }
};

int main()
{
    HashTable t;
    t.insert_without("a", 223);
    t.insert_without("b", 224);
    t.insert_without("c", 233);
    t.insert_with("d", 235);
    t.display_hashtable();
    t.delete_fn(233);
    t.display_hashtable();
    return 0;
}

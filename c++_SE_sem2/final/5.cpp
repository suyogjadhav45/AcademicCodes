/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#define size 10
using namespace std;

class HashNode
{
    string n;
    HashNode *next;

public:
    HashNode()
    {
        n = "";
        next = NULL;
    }
    HashNode(string w)
    {
        n = w;
        next = NULL;
    }
    friend class Dict;
};

class Dict
{
    HashNode *hn[size];

public:
    Dict()
    {
        for (int i = 0; i < size; i++)
        {
            hn[i] = NULL;
        }
    }
    int hash(string k)
    {
        int res = 0;
        int i = 0;
        while (k[i])
        {
            res = res + int(k[i]);
            i++;
        }
        return (res % size);
    }

    void insert(string k)
    {
        int pos = hash(k);
        if (hn[pos] == NULL)
        {
            hn[pos] = new HashNode(k);
        }
        else
        {
            HashNode *t = hn[pos];
            while (t->next)
            {
                if (t->n == k)
                {
                    cout << "duplicate entry\n";
                    return;
                }
                t = t->next;
            }
            t->next = new HashNode(k);
        }
    }

    int search(string k)
    {
        int pos = hash(k);
        int n = 0;
        if (hn[pos]->n == k)
        {
            cout << "\nfound at 0th loc of " << pos << "th index\n";
            return n;
        }
        else
        {
            HashNode *t = hn[pos];
            while (t->next)
            {
                t = t->next;
                n += 1;
                if (t->n == k)
                {
                    cout << "\nfound at " << n << "th loc of " << pos << "th index";
                    return n;
                }
            }
        }
    }

    void display_fn()
    {
        for (int i = 0; i < size; i++)
        {
            HashNode *t = hn[i];

            if (t != NULL)
            {
                cout << "\n[ " << i << " ] --> ";
                while (t)
                {
                    cout << t->n << " --> ";
                    t = t->next;
                }
            }
        }
    }

    void delete_fn(string k)
    {
        int pos = hash(k);
        int s = search(k);
        HashNode *t = hn[pos];
        for (int i = 0; i < s - 1; i++)
        {
            t = t->next;
        }
        HashNode *p = t->next;
        if (k == hn[pos]->n)
        {
            t->n = p->n;
            t->next = p->next;
        }
        else if (p->next)
        {
            t->next = p->next;
        }
        else
        {
            t->next = NULL;
        }
    }
};

int main()
{
    Dict d;
    d.insert("zim");
    d.insert("bsk");
    d.insert("bdf");
    d.insert("cde");
    d.insert("adg");
    d.insert("captain");
    d.insert("captain1");
    d.search("captain");
    d.display_fn();
    d.delete_fn("cde");
    d.display_fn();
    return 0;
}
// found at 1th position of 6th index
// 0 : bsk bdf     cde     adg
// 5 : captain1
// 6 : zim captain

// found at 2th position of 0th index
// 0 : bsk bdf     adg
// 5 : captain1
// 6 : zim captain
//============================================================================
// Name : DSAL04.cpp
// Author :
// Version :
// Copyright : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <cstring>
#define size 10
using namespace std;
class Mobile_No
{
    long int mobno;
    string name;
    bool flag;

public:
    Mobile_No()
    {
        mobno = 0;
        name = "--";
    }
    Mobile_No(string name, long int mobno)
    {
        this->name = name;
        this->mobno = mobno;
    }
    friend class Hash_Table;
};

class Hash_Table
{
    Mobile_No m[size];

public:
    int hash_fn(long int x)
    {
        return (x % size);
    }

    // void insert_with_replacement(string n, long int a)
    // {
    //     Mobile_No person;
    //     person.name = n;
    //     person.mobno = a;
    //     int pos;
    //     pos = hash_fn(person.mobno);
    //     if (m[pos].mobno == 0)
    //     {
    //         m[pos] = person;
    //     }
    //     else
    //     {
    //         int k = hash_fn(m[pos].mobno);
    //         if (k != pos)
    //         {
    //             Mobile_No temp = m[pos];
    //             // temp.name=m[pos].name;
    //             // temp.mobno=m[pos].mobno;
    //             m[pos] = person;
    //             // m[pos].name=person.name;
    //             // m[pos].mobno=person.mobno;
    //             insert_wout_rpment(temp.name, temp.mobno);
    //         }
    //         else
    //         {
    //             insert_wout_rpment(person.name, person.mobno);
    //         }
    //     }
    // }
    void insert_wout_rpment(string n, long int a)
    {
        Mobile_No person;
        person.name = n;
        person.mobno = a;
        int pos;
        pos = hash_fn(person.mobno);
        if (m[pos].mobno == 0)
        {
            m[pos] = person;
        }
        else
        {
            for (int i = pos + 1; i != pos; i++)
            {
                if (m[i].mobno == 0)
                {
                    m[i] = person;
                    break;
                }
                // cout << i << endl;
                if (i == size)
                {
                    i = 0;
                }
            }
        }
    }

    void update(long int a, string b)
    {
        int k = search(a);
        m[k].name = b;
        cout << "\nName updated successfully!!" << endl;
    }

    void display_hashtable()
    {
        cout << "\n\n---------------HASH TABLE------------------\n";
        cout << "\nIndex\t\tName\t\tMobile Number\n"
             << endl;
        for (int i = 0; i < size; i++)
        {
            cout << i << "\t\t" << m[i].name << "\t\t" << m[i].mobno << endl;
        }
        cout << "\n---------------------------------------------\n";
    }
    void delete_fn(long int k)
    {
        int a = search(k);
        long int n = m[a].mobno;
        string f = m[a].name;
        m[a].mobno = 0;
        m[a].name = "--";
        // int b = hash_fn(n);
        // int c = search_hash(b);
        // if (a == b && c)
        // {

        //     m[a] = m[c];
        //     m[c].mobno = 0;
        //     m[c].name = "--";
        // }
        cout << "\nMobile Number Deleted Successfully!!!" << endl;
    }
    // int search_hash(int k)
    // {
    //     bool f = false;
    //     for (int i = 0; i < size; i++)
    //     {
    //         int v = hash_fn(m[i].mobno);
    //         if (v == k)
    //         {
    //             f = true;
    //             return i;
    //         }
    //     }
    // }
    int search(long int k)
    {
        bool f = false;
        for (int i = 0; i < size; i++)
        {
            if (m[i].mobno == k)
            {
                f = true;
                return i;
            }
        }
        if (f == false)
        {
            cout << "Not Found!!!" << endl;
        }
    }
};

int main()
{
    Hash_Table t;
    // // t.insert_mn();
    // // t.insert_with_replacement();
    // // t.insert_with_replacement();
    // // t.insert_with_replacement();
    // t.insert_wout_rpment("a", 223);
    // t.insert_wout_rpment("b", 224);
    // t.insert_wout_rpment("c", 233);
    // t.insert_with_replacement("d", 235);
    // t.display_hashtable();
    // t.delete_fn(223);
    // // t.update(235,247);
    // // t.display_hashtable();
    // // t.delete_fn(224);
    // // t.display_hashtable();
    // // t.search();
    // // t.delete_fn();
    t.display_hashtable();
    return 0;
}
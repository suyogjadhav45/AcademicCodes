//============================================================================
// Name        : DSAL05.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#define size 10
using namespace std;

class HashNode
{
    string wordkey;
    string meaning;
    HashNode *next;

public:
    HashNode()
    {
        wordkey = "";
        meaning = "";
        next = NULL;
    }
    HashNode(string wordkey, string meaning)
    {
        this->wordkey = wordkey;
        this->meaning = meaning;
        next = NULL;
    }
    friend class Dictionary;
};

class Dictionary
{
    HashNode *hn[size];

public:
    Dictionary()
    {
        for (int i = 0; i < size; i++)
        {
            hn[i] = NULL;
        }
    }
    int hash_fn(string key)
    {
        int result = 0;
        int i = 0;
        while (key[i])
        {
            result = result + int(key[i]);
            i++;
        }
        return (result % size);
    }

    void insert(string key, string meaning)
    {
        int k = hash_fn(key);
        if (hn[k] == NULL)
        {
            HashNode *temp = new HashNode(key, meaning);
            hn[k] = temp;
        }
        else
        {
            HashNode *t = hn[k];
            while (t->next)
            {
                if (t->wordkey == key)
                {
                    cout << "\nDuplicate Entry!!!" << endl;
                    return;
                }
                t = t->next;
            }
            t->next = new HashNode(key, meaning);
        }
    }

    int search_fn(string key)
    {
        int k = hash_fn(key);
        int n = 0;

        if (hn[k]->wordkey == key)
        {
            cout << "\nFound at 0th location at " << k << "th index" << endl;
            return n;
        }
        else
        {
            HashNode *t = hn[k];

            while (t->next)
            {
                t = t->next;
                n += 1;
                if (key == t->wordkey)
                {
                    cout << "Found at " << n << "th location of " << k << "th index";

                    return n;
                }
            }
        }
        // cout<<"\nNot Found"<<endl;
    }

    void modify(string key, string m)
    {
        int k = hash_fn(key);
        int n = search_fn(key);
        HashNode *t = hn[k];
        for (int i = 0; i < n; i++)
        {
            t = t->next;
        }
        t->meaning = m;
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            HashNode *t = hn[i];
            if (t != NULL)
            {
                cout << "\nIndex: " << i << " ----> ";
                while (t->next != NULL)
                {
                    cout << " [ " << t->wordkey << "," << t->meaning << " ] ----> ";
                    t = t->next;
                }
                cout << "[ " << t->wordkey << "," << t->meaning << " ]" << endl;
            }
        }
    }

    void delete_fn(string key)
    {
        int k = hash_fn(key);
        int n = search_fn(key);
        HashNode *t = hn[k];
        for (int i = 0; i < n - 1; i++)
        {
            t = t->next;
        }
        HashNode *p = t->next;
        if (hn[k]->wordkey == key)
        {
            t->wordkey = p->wordkey;
            t->meaning = p->meaning;
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
    Dictionary d;
    d.insert("zim", "goal");
    d.insert("bsk", "per");
    d.insert("bdf", "m1");
    d.insert("cde", "m2");
    d.insert("adg", "m3");
    d.insert("captain", "cap");
    d.insert("captain1", "vk");
    d.display();
    int ch;
    string a, b;
    while (ch != 6)
    {
        cout << "\n\n----------------MAIN MENU-----------------\n\n";
        cout << "1) Insert" << endl;
        cout << "2) Search" << endl;
        cout << "3) Update" << endl;
        cout << "4) Delete" << endl;
        cout << "5) Display" << endl;
        cout << "6) Exit" << endl;
        cout << "\n------------------------------------------\n";

        cout << "\nEnter your choice -----> ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            // string a,b;
            cout << "\nEnter word  -----> ";
            cin >> a;
            cout << "Enter meaning -----> ";
            cin >> b;
            d.insert(a, b);
            break;
        case 2:
            // string a;
            cout << "\nEnter word for searching -----> ";
            cin >> a;
            d.search_fn(a);
            break;
        case 3:
            cout << "\nEnter word -----> ";
            cin >> a;
            cout << "Enter updated meaning -----> ";
            cin >> b;
            d.modify(a, b);
            break;
        case 4:
            cout << "\nEnter word for deletion -----> ";
            cin >> a;
            d.delete_fn(a);
            break;
        case 5:
            d.display();
            break;
        case 6:
            cout << "\nExitinggg!!!!!";
            break;
        }
    }

    return 0;
}
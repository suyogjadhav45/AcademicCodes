#include <iostream>
#include <fstream>
using namespace std;
class Student
{
    int roll;
    string name;

public:
    void getdata()
    {
        cout << "\nEnter Roll Number : ";
        cin >> roll;
        cout << "\nEnter Name : ";
        cin >> name;
    }
    void display()
    {
        cout << "\n-----------------------------------\n";
        cout << "Roll No : " << roll << endl;
        cout << "Name : " << name << endl;
        cout << "\n-----------------------------------\n";
    }
    friend class Record;
};
class Record
{
    Student s;

public:
    void create()
    {
        int n;
        cout << "\nEnter number of records : ";
        cin >> n;
        ofstream fout;
        fout.open("newstud.dat", ios::out | ios::binary);
        for (int i = 0; i < n; i++)
        {
            s.getdata();
            fout.write((char *)&s, sizeof(s));
        }
        fout.close();
    }
    void print()
    {
        ifstream fin;
        fin.open("newstud.dat", ios::in | ios::binary);
        fin.seekg(0, ios::beg);
        while (fin.read((char *)&s, sizeof(s)))
        {
            if (s.roll != -1)
            {
                s.display();
            }
        }
        fin.close();
    }
    int search()
    {
        int k;
        cout << "\nEnter roll for searching : ";
        cin >> k;
        int p = search(k);
        return p;
    }
    int search(int k)
    {
        ifstream fin;
        int i = 0;
        fin.open("newstud.dat", ios::in | ios::binary);
        while (fin.read((char *)&s, sizeof(s)))
        {
            if (s.roll == k)
            {
                cout << "\nRecord Found" << endl;
                s.display();
                return i;
            }
            i++;
        }
        fin.close();
        return -1;
    }
    void delete_rec()
    {
        int k;
        cout << "\nEnter roll for del : ";
        cin >> k;
        int pos, off;
        fstream f;
        f.open("newstud.dat", ios::in | ios::binary | ios::out);
        pos = search(k);
        if (pos == -1)
        {
            cout << "\nRecord not found for deletion" << endl;
            return;
        }
        off = pos * sizeof(s);
        f.seekp(off);
        s.roll = -1;
        s.name = "";
        f.write((char *)&s, sizeof(s));
        cout << "\nRecord Deleted Successfully" << endl;
        f.close();
    }
};
int main()
{
    Record r; // r.create(); // r.print(); // r.search(); // r.delete_rec();
    int ch;
    while (ch != 5)
    {
        cout << "1)create\n2)print\n3)search\n4)delete\n5)exit\n";
        cout << "Enter choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            r.create();
            break;
        case 2:
            r.print();
            break;
        case 3:
            r.search();
            break;
        case 4:
            r.delete_rec();
            break;
        case 5:
            break;
        default:
            break;
        }
    }
    return 0;
}
#include <iostream>
#include <fstream>
using namespace std;
class Student
{
public:
    int rollno;
    string name;
    void getData()
    {
        cout << "\nEnter Student Roll Number ::";
        cin >> rollno;
        cout << "\nEnter Student Name        ::";
        cin >> name;
    }
    void Display()
    {
        cout << "\n----------------------------------";
        cout << "\nROLL NUMBER :: " << rollno;
        cout << "\nNAME        :: " << name;
        cout << "\n----------------------------------";
    }
};
class Record
{
    Student s;

public:
    void create()
    {
        int n;
        cout << "\nEnter Number of Data To be Entered ::";
        cin >> n;
        fstream fout;
        fout.open("student.dat", ios::out | ios::binary);
        for (int i = 0; i < n; i++)
        {
            s.getData();
            fout.write((char *)&s, sizeof(s));
        }
        fout.close();
    }
    void Print()
    {
        ifstream fin;
        fin.open("student.dat", ios::in | ios::binary);
        fin.seekg(0, ios::beg);
        while (fin.read((char *)&s, sizeof(s)))
        {
            if (s.rollno != -1)
            {
                s.Display();
            }
        }
        fin.close();
    }
    int Search(int n)
    {
        fstream fin;
        int i = 0;
        fin.open("student.dat", ios::in | ios::binary);
        while (fin.read((char *)&s, sizeof(s)))
        {
            if (s.rollno == n)
            {
                cout << "\nRecord Found";
                s.Display();
                return i;
            }
            i++;
        }
        fin.close();
        return -1;
    }
    void Delete()
    {
        int pos, n;
        cout << "\nEnter Number to Be Deleted ::";
        cin >> n;
        pos = Search(n);
        if (pos == -1)
        {
            cout << "\nRoll Number not found ";
            return;
        }
        fstream f;
        f.open("student.dat", ios::in | ios::binary | ios::out);
        f.seekg(0, ios::beg);
        int offset = pos * sizeof(s);
        f.seekp(offset);
        s.name = "NULL";
        s.rollno = -1;
        f.write((char *)&s, sizeof(s));
        f.seekg(0);
        f.close();
        cout << "\nRecord Deleted ";
    }
};
int main()
{
    Record r;
    r.create();
    r.Print();
    r.Delete();
    r.Print();
    return 0;
}
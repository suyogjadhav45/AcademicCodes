#include <iostream>
using namespace std;

class Parent;

class Student
{
    string name;
    int Roll_no;
    string clss;
    string division;
    string DOB;
    string Bloodgrp;
    string contaddress;
    long *phonenumber;
    long *DLnumber;

    friend class Parent;

public:
    Student()
    {
        name = "";
        Roll_no = 0;
        clss = "";
        division = "";
        DOB = "dd/mm/yyyy";
        Bloodgrp = "";
        contaddress = "";
        phonenumber = new long;
        DLnumber = new long;
    }

    Student(string name, int Roll_no)
    {
        this->name = name; //this pointer
        this->Roll_no = Roll_no;
    }

    void getData(Parent &p1);

    void displayData(Parent &p1);

    int countnumber(long v)
    {
        int m = 0;
        while (v != 0)
        {
            v = v / 10;
            m++;
        }
        return m;
    }

    static void header()
    {
        cout << "\n------------------//--------------STUDENT DATABASE---------------//-----------------\n";
    }

    ~Student()
    {
        delete phonenumber, DLnumber;
    }
};

class Parent
{
    string Fname;
    string Mname;
    string Fjob;
    string Mjob;
    long *Fcontactnumber;
    long *Mcontactnumber;

    friend class Student;

public:
    Parent()
    {
        Fname = "";
        Mname = "";
        Fjob = "";
        Mjob = "";
        Fcontactnumber = new long;
        Mcontactnumber = new long;
    }

    Parent(Parent &p1)
    { //copy constructor
        Fname = p1.Fname;
        Mname = p1.Mname;
        Fjob = p1.Fjob;
        Mjob = p1.Mjob;
        Fcontactnumber = p1.Fcontactnumber;
        Mcontactnumber = p1.Mcontactnumber;
    }

    void getinfo()
    {
        cout << "Enter Father's name : ";
        cin.ignore();
        getline(cin, Fname);
        cout << "Enter Father's Job : ";
        cin.ignore();
        getline(cin, Fjob);
        cout << "Enter Father's contact number : ";
        cin >> *Fcontactnumber;
        cout << "Enter Mother's name : ";
        cin.ignore();
        getline(cin, Mname);
        cout << "Enter Mother's Job : ";
        cin.ignore();
        getline(cin, Mjob);
        cout << "Enter Mother's contact number : ";
        cin >> *Mcontactnumber;
    }

    void displayinfo()
    {
        cout << "\n\n-----------------------Parent Information---------------------------\n\n";
        cout << "Father's Name                    : " << Fname << endl;
        cout << "Father's Job                     : " << Fjob << endl;
        cout << "Father's Contact Number          : " << *Fcontactnumber << endl;
        cout << "Mother's Name                    : " << Mname << endl;
        cout << "Mother's Job                     : " << Mjob << endl;
        cout << "Mother's Contact Number          : " << *Mcontactnumber << endl;
        cout << "\n-----------------------------------------------------------------------------------------\n";
    }

    ~Parent()
    {
        delete Fcontactnumber, Mcontactnumber;
    }
};

void Student::getData(Parent &p1)
{
    cout << "\nEnter Name of student : ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Roll number of student : ";
    cin >> Roll_no;
    cout << "Enter class of student : ";
    cin >> clss;
    cout << "Enter division of student : ";
    cin >> division;
    cout << "Enter Date of Birth of student : ";
    cin >> DOB;
    cout << "Enter Blood group of student : ";
    cin >> Bloodgrp;
    cout << "Enter Contact Address of student : ";
    cin.ignore();
    getline(cin, contaddress);
    cout << "Enter Mobile number of student(10 digits) : ";
    cin >> *phonenumber;

    int len = countnumber(*phonenumber);
    try
    {
        if (len != 10)
        {
            throw "#Error# Enter 10 Digit Mobile Number";
        }
    }
    catch (const char *ex)
    {
        cout << "\nException : " << ex << "\n\n";
    }

    cout << "Enter Driving License number of student : ";
    cin >> *DLnumber;
    p1.getinfo();
}

inline void Student::displayData(Parent &p1)
{
    cout << "\n----------------------Student Information--------------------------\n\n";
    cout << "Name of student                   : " << name << endl;
    cout << "Roll number of student            : " << Roll_no << endl;
    cout << "Class of student                  : " << clss << endl;
    cout << "Division of student               : " << division << endl;
    cout << "Date of Birth of student          : " << DOB << endl;
    cout << "Blood group of student            : " << Bloodgrp << endl;
    cout << "Contact Address of student        : " << contaddress << endl;
    cout << "Telephone number of student       : " << *phonenumber << endl;
    cout << "Driving License number of student : " << *DLnumber << endl;
    p1.displayinfo();
}

int main()
{
    int ch;
    int count = 0;
    Student st[100];
    Parent pt[100];

    do
    {
        cout << "\n--------------------Menu----------------------\n";
        cout << "1. Add Student Data" << endl;
        cout << "2. Display Student Data" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice (1/2/3) : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            st[count].getData(pt[count]);
            count++;
            break;
        case 2:
            int i;
            for (i = 0; i < count; i++)
            {
                Student::header();
                cout << "\nInformation of Student No." << i + 1 << endl;
                st[i].displayData(pt[i]);
            }
            break;
        case 3:
            exit(0);
        }
    } while (ch != 3);

    return 0;
}

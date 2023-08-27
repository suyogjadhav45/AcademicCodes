#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Studentinfo
{
public:
    string Name;
    int Rollno;
    string DOB;
    long MobileNumber;

    Studentinfo()
    {
        Name = "";
        Rollno = 0;
        DOB = "";
        MobileNumber = 0;
    }

    Studentinfo(string Name, int Rollno, string DOB, long MobileNumber)
    {
        this->Name = Name;
        this->Rollno = Rollno;
        this->DOB = DOB;
        this->MobileNumber = MobileNumber;
    }

    void setData()
    {
        cout << "\n############################################################\n";
        cout << "\nEnter Name of Student -----------------> ";
        cin >> Name;
        cout << "Enter Roll Number of Student ----------> ";
        cin >> Rollno;
        cout << "Enter Date of Birth of Student --------> ";
        cin >> DOB;
        cout << "Enter Mobile Number of Student --------> ";
        cin >> MobileNumber;
    }
};

bool Compare(Studentinfo st1, Studentinfo st2)
{
    return st1.Rollno < st2.Rollno;
}

void add_to_vector(vector<Studentinfo> &v1)
{
    int n;
    cout << "Enter Number of Students you want to Add -----> ";
    cin >> n;
    Studentinfo S[n];
    for (int i = 0; i < n; i++)
    {
        Studentinfo NewStudent;
        NewStudent.setData();
        v1.push_back(NewStudent);
    }
}

int main()
{
    int choice;
    vector<Studentinfo> v;
    while (choice != 5)
    {
        cout << "\n############################## Main MENU ##############################\n\n";
        cout << "1) Add Student Information" << endl;
        cout << "2) Sort the Student Information" << endl;
        cout << "3) Search Operation using Roll Number" << endl;
        cout << "4) Search Operation using Name" << endl;
        cout << "5) Exit" << endl;

        cout << "\nEnter your choice (1/2/3/4) -------> ";
        cin >> choice;

        if (choice == 1)
        {
            add_to_vector(v);
        }

        else if (choice == 2)
        {
            sort(v.begin(), v.end(), Compare);

            vector<Studentinfo>::iterator it = v.begin();

            cout << "\n----------------------- Sorted Data ---------------------------\n";

            while (it != v.end())
            {
                cout << "\nName of Student            : " << (*it).Name << endl;
                cout << "Roll Number of Student     : " << (*it).Rollno << endl;
                cout << "Date of Birth of Student   : " << (*it).DOB << endl;
                cout << "Mobile Number of Student   : " << (*it).MobileNumber << "\n\n";
                it++;
            }
            cout << "-----------------------------------------------------------------\n";
        }

        else if (choice == 3)
        {
            int q;
            cout << "Enter Roll Number for search Operation -----> ";
            cin >> q;

            vector<Studentinfo>::iterator it = v.begin();

            while (it != v.end())
            {
                if ((*it).Rollno == q)
                {
                    break;
                }
                it++;
            }

            if ((*it).Rollno != q)
            {
                cout << "\nStudent with Roll Number '" << q << "' not found in Data!!!" << endl;
            }

            else
            {
                cout << "\n----------------------- Search Result ---------------------------\n";
                cout << "\nName of Student            : " << (*it).Name << endl;
                cout << "Roll Number of Student     : " << (*it).Rollno << endl;
                cout << "Date of Birth of Student   : " << (*it).DOB << endl;
                cout << "Mobile Number of Student   : " << (*it).MobileNumber << endl;
                cout << "\n-----------------------------------------------------------------\n";
            }
        }

        else if (choice == 4)
        {
            string y;
            cout << "Enter Name for search Operation -----> ";
            cin >> y;

            vector<Studentinfo>::iterator it = v.begin();

            while (it != v.end())
            {
                if ((*it).Name == y)
                {
                    break;
                }
                it++;
            }

            if ((*it).Name != y)
            {
                cout << "\nStudent with Name '" << y << "' not found in Data!!!" << endl;
            }

            else
            {
                cout << "\n----------------------- Search Result ---------------------------\n";
                cout << "\nName of Student            : " << (*it).Name << endl;
                cout << "Roll Number of Student     : " << (*it).Rollno << endl;
                cout << "Date of Birth of Student   : " << (*it).DOB << endl;
                cout << "Mobile Number of Student   : " << (*it).MobileNumber << endl;
                cout << "\n-----------------------------------------------------------------\n";
            }
        }
    }

    return 0;
}
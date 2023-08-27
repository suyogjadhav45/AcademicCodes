#include <iostream>
using namespace std;

class Student
{
    string name;
    int Roll_no;
    string clss;
    string division;

public:
    Student()
    {
        name = "";
        Roll_no = 0;
        clss = "";
        division = "";
    }

    void getData();

    void displayData();
};

inline void Student::getData()
{
    cout << "\nEnter Name of student : ";
    cin >> name;
    cout << "Enter Roll number of student : ";
    cin >> Roll_no;
    cout << "Enter class of student : ";
    cin >> clss;
    cout << "Enter division of student : ";
    cin >> division;
}

inline void Student::displayData()
{
    cout << "\n----------------------Student Information--------------------------\n\n";
    cout << "Name of student                   : " << name << endl;
    cout << "Roll number of student            : " << Roll_no << endl;
    cout << "Class of student                  : " << clss << endl;
    cout << "Division of student               : " << division << endl;
}

int main()
{
    int i;
    int count=0;
    Student st[3];
    for (i = 0; i < 3; i++)
    {
        cout<<"\nEnter the Information of Student no. "<<count+1<<endl;
        st[i].getData();
        count++;
    }
    for (i = 0; i < 3; i++)
    {
        st[i].displayData();
    }

    return 0;
}

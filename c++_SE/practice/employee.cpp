#include <iostream>
using namespace std;

class Employee
{
    string name;
    int id;
    string city;
    static int count;

public:
    Employee()
    {
        name = "";
        id = 0;
        city = "";
    }
    Employee(string name, int id, string city)
    {
        this->name = name;
        this->id = id;
        this->city = city;
    }
    void setData();
    void getData();
    static void Epnumber()
    {
        cout << "\nTotal Number of Employees : " << count << endl;
    }
};
int Employee::count;

inline void Employee::setData()
{
    cout << "Enter Name : " << endl;
    cin >> name;
    cout << "Enter ID : " << endl;
    cin >> id;
    cout << "Enter city : " << endl;
    cin >> city;
    count++;
}

inline void Employee::getData()
{
    cout << "\nName of Employee is : " << name << endl;
    cout << "ID of Employee is   : " << id << endl;
    cout << "city of Employee is  : " << city << endl;
}

int main()
{
    Employee ad[3];
    for (int i = 0; i < 3; i++)
    {
        ad[i].setData();
    }
    for (int i = 0; i < 3; i++)
    {
        ad[i].getData();
    }
    Employee::Epnumber();
    return 0;
}
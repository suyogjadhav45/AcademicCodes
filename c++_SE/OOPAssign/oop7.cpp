#include <iostream>
#include <fstream>
using namespace std;

class Cricket
{
    string Name;
    int Jersy_number;
    string Country;
    string Role;

public:
    void setData()
    {
        cout << "\nEnter Name of Cricketor : ";
        cin >> Name;
        cout << "Enter Jersy number of Cricketor : ";
        cin >> Jersy_number;
        cout << "Enter Country of Cricketor : ";
        cin >> Country;
        cout << "Enter Role of Cricketor : ";
        cin >> Role;
    }
    void displayData()
    {
        cout << "\n";
        cout << "\n Name         : " << Name;
        cout << "\n Jersy number : " << Jersy_number;
        cout << "\n Country      : " << Country;
        cout << "\n Role         : " << Role;
    }
};

int main()
{
    Cricket Player[5];
    ofstream Newfile;
    ifstream file;
    int i, n;

    Newfile.open("cricket.txt");
    cout << "\n How many Cricketor's information do you need to store : ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "\n------------Enter information of Cricketor number " << i + 1 << "-------------" << endl;
        Player[i].setData();
    }
    Newfile.close();

    file.open("cricket.txt");
    cout << "\n-----------------//--------------------INFORMATION OF CRICKETORS-----------------//--------------------\n";
    for (i = 0; i < n; i++)
    {
        Player[i].displayData();
    }
    file.close();

    return 0;
}
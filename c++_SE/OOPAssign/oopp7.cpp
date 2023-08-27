#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string Name;
    int Jersy_number;
    string Country;
    string Role;

    ofstream out;
    

    out.open("crick.txt");

    cout << "\nEnter Name of Cricketer : ";
    cin >> Name;
    cout << "Enter Jersy number of Cricketer : ";
    cin >> Jersy_number;
    cout << "Enter Country of Cricketer : ";
    cin >> Country;
    cout << "Enter Role of Cricketer : ";
    cin >> Role;

    out << "Name         : " << Name << endl;
    out << "Jersy number : " << Jersy_number << endl;
    out << "Country      : " << Country << endl;
    out << "Role         : " << Role << endl;

    out.close();


    ifstream in;

    string Name1;
    string Jersy_number1;
    string Country1;
    string Role1;
    in.open("crick.txt");
    getline(in,Name1);
    getline(in,Jersy_number1);
    getline(in,Country1);
    getline(in,Role1);

    cout << Name1 << endl;
    cout <<Jersy_number1 << endl;
    cout << Country1 << endl;
    cout << Role1 << endl;

    in.close();

    return 0;
}
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{

    map<string, int> State_population;
    // mapType State_population;
    int choice;
    while (choice != 3)
    {
        cout << "\n---------MENU-----------" << endl;
        cout << "1) Add" << endl;
        cout << "2) Search" << endl;
        cout << "3) Exit" << endl;
        cout << "\nEnter your choice -----> ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int n;
            cout << "Enter number of State-Population pairs you want to add -----> ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                string a;
                int b;
                cout << "Enter name of state -----> ";
                cin >> a;
                cout << "Enter population of state -----> ";
                cin >> b;
                State_population.insert(pair<string, int>(a, b));
            }
            break;
        case 2:
            string state;
            map<string,int>::iterator it;
            cout << "\nEnter name of the state -----> ";
            cin >> state;
            it = State_population.find(state);
            if (it != State_population.end())
                cout << state << "'s population is -----> " << (*it).second<<endl;
            else
                cout << "State Name not found!!" << endl;
            break;
        }
    }
}
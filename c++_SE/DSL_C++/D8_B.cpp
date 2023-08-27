#include <iostream>

using namespace std;

class Node
{
private:
    int roll;
    Node *next;

public:
    Node(int roll)
    {
        this->roll = roll;
        next = NULL;
    }
    friend class ice;
};

class ice
{
private:
    Node *start;

public:
    ice()
    {
        start = NULL;
    }

    void insert_at_end(int x)
    {
        if (start == NULL)
        {
            Node *temp = new Node(x);
            start = temp;
        }
        else
        {
            Node *temp1 = new Node(x);
            Node *temp2 = start;
            while (temp2->next != NULL)
            {
                temp2 = temp2->next;
            }
            temp2->next = temp1;
        }
    }

    int display()
    {
        int count = 0;
        if (start == NULL)
        {
            cout << "The list is empty !" << endl;
        }
        else
        {
            Node *temp = start;
            while (temp != NULL)
            {
                cout << temp->roll << "  ";
                temp = temp->next;
                count++;
            }
        }
        return count;
    }

    ice union_ice(ice s1, ice s2)
    {
        ice result;
        Node *temp1 = s1.start;
        Node *temp2 = s2.start;

        while (temp1 != NULL)
        {
            result.insert_at_end(temp1->roll);
            temp1 = temp1->next;
        }

        while (temp2 != NULL)
        {

            if (!result.present(temp2->roll))
            {
                result.insert_at_end(temp2->roll);
            }
            temp2 = temp2->next;
        }

        return result;
    }

    ice intersection_ice(ice s1, ice s2)
    {
        ice result;
        Node *temp1 = s1.start;
        Node *temp2 = s2.start;

        while (temp2 != NULL)
        {
            if (s1.present(temp2->roll))
            {
                result.insert_at_end(temp2->roll);
            }
            temp2 = temp2->next;
        }

        return result;
    }

    ice minus_ice(ice s1, ice s2)
    {
        ice result;
        Node *temp1 = s1.start;
        Node *temp2 = s2.start;

        while (temp1 != NULL)
        {
            if (!s2.present(temp1->roll))
            {
                result.insert_at_end(temp1->roll);
            }
            temp1 = temp1->next;
        }

        return result;
    }

    bool present(int roll)
    {
        Node *temp = start;
        while (temp != NULL)
        {
            if (temp->roll == roll)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};

int main()
{
    int t = 0, v = 0, b = 0, roll = 0;
    ice total;
    ice vanilla;
    ice butter;

    cout << "Enter the total number of students : ";
    cin >> t;

    for (size_t i = 0; i < t; i++)
    {
        cout << "Enter the rollnumbers - ";
        cin >> roll;
        total.insert_at_end(roll);
    }

    cout << "Enter the total number of vanilla students : ";
    cin >> v;
    for (size_t i = 0; i < v; i++)
    {
        cout << "Enter the rollnumbers - ";
        cin >> roll;
        vanilla.insert_at_end(roll);
    }
    cout << "Enter the total number of butterscotch students : ";
    cin >> b;
    for (size_t i = 0; i < b; i++)
    {
        cout << "Enter the rollnumbers - ";
        cin >> roll;
        butter.insert_at_end(roll);
    }
    int choice = 0, count = 0;
    ice ans1, ans2, ans3;

    while (choice != 5)
    {
        cout << "\n*****Main menu***\n";
        cout << "1. Display the students with their ice cream preferences\n";
        cout << "2. Students who like both vanilla and butterscotch\n";
        cout << "3. Students who like either vanilla or butterscotch or / (but) not both\n";
        cout << "4. Number of students who neither like vanilla nor butterscotch\n";
        cout << "5. Exit\n";
        cout << "*********\n";

        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
            cout << "Total students in class are : ";
            total.display();
            cout << "\nThe students who like Vanilla are : ";
            vanilla.display();
            cout << "\nThe students who like Butterscotch are : ";
            butter.display();
            cout << endl;
            break;

        case 2:
            // students with their ice cream preferences
            ans2 = ans1.intersection_ice(vanilla, butter);
            cout << "students who likes vanilla as well as butterscotch->" << endl;
            ans2.display();
            break;

        case 3:
            // Students who like either vanilla or butterscotch or not both
            ans2 = ans1.intersection_ice(vanilla, butter);
            ans3 = ans1.minus_ice(total, ans2);
            cout << "Students who like either vanilla or butterscotch or not both->" << endl;
            ans3.display();
            break;

        case 4:
            // Number of students who neither like vanilla nor butterscotch
            ans2 = ans1.union_ice(vanilla, butter);
            ans3 = ans1.minus_ice(total, ans2);
            cout << "students who neither like vanilla nor butterscotch->" << endl;
            count = ans3.display();
            cout << endl;
            cout << "Number of students : " << count << endl;
            break;

        case 5:
            cout << "Thank you\nExiting......\n";
            break;

        default:
            cout << "Enter a choice from the menu only....\n";
            break;
        }
    }

    return 0;
}

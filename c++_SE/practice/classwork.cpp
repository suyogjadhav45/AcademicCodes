#include <iostream>
using namespace std;

class node
{
public:
    int roll;
    class node *next;
};


class Student_Data
{
    node *head1 = NULL;
    node *temp1 = NULL;
    node *head2 = NULL;
    node *temp2 = NULL;
    node *head = NULL;
    node *temp = NULL;
    node *h1 = NULL;
    node *head3 = NULL;
    node *temp3 = NULL;
    int c, i, f, j, k;

public:
    node *create()
    {
        node *p = new (class node);
        cout << "Enter Roll Number of Student -----> ";
        cin >> c;
        p->roll = c;
        p->next = NULL;
        return p;
    }

    void Total_Students();
    void vanila();
    void butterscotch();

    void display()
    {
        temp = head;
        while (temp->next != NULL)
        {
            cout << "\n"
                 << temp->roll;
            temp = temp->next;
        }
        cout << "\n"
             << temp->roll;
    }

    void insert()
    {
        node *p = create();

        if (head == NULL)
        {
            head = p;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = p;
        }
    }

    void vanila_butter();
    void both_vanila_butter();
    void neither_vanila_butter();
};


void Student_Data::Total_Students()
{
    cout << "\nEnter total Number of Students in Class -----> ";
    cin >> k;
    head = NULL;

    for (i = 0; i < k; i++)
    {
        insert();
        h1 = head;
    }

    display();
    head = NULL;
}


void Student_Data::vanila()
{
    cout << "\nEnter the number of Students who likes Vanila Icescream -----> ";
    cin >> k;
    head = NULL;

    for (i = 0; i < k; i++)
    {
        insert();
        head1 = head;
    }

    display();
    head = NULL;
}


void Student_Data::butterscotch()
{
    cout << "\nEnter the number of Students who likes Butterscotch Icescream -----> ";
    cin >> j;

    for (i = 0; i < j; i++)
    {
        insert();
        head2 = head;
    }

    display();
    head = NULL;
}


void Student_Data::vanila_butter()
{
    cout << "\n##############################################################################\n";

    cout << "\n------- Students who likes Vanila or Butterscotch Icescream -------\n";

    temp1 = head1;

    while (temp1 != NULL)
    {
        node *p = new (struct node);
        p->roll = temp1->roll;
        p->next = NULL;
        if (head3 == NULL)
        {
            head3 = p;
        }
        else
        {
            temp3 = head3;
            while (temp3->next != NULL)
            {
                temp3 = temp3->next;
            }
            temp3->next = p;
        }

        temp1 = temp1->next;
    }

    temp2 = head2;

    while (temp2 != NULL)
    {
        f = 0;
        temp1 = head1;

        while (temp1 != NULL)
        {
            if (temp2->roll == temp1->roll)
            {
                f = 1;
            }
            temp1 = temp1->next;
        }

        if (f == 0)
        {
            node *p = new (struct node);
            p->roll = temp2->roll;
            p->next = NULL;
            if (head3 == NULL)
            {
                head3 = p;
            }
            else
            {
                temp3 = head3;
                while (temp3->next != NULL)
                {
                    temp3 = temp3->next;
                }
                temp3->next = p;
            }
        }
        temp2 = temp2->next;
    }

    temp3 = head3;

    while (temp3->next != NULL)
    {
        cout << "\t"
             << temp3->roll;
        temp3 = temp3->next;
    }

    cout << "\t"
         << temp3->roll;

    cout << "\n\n##############################################################################\n";
}


void Student_Data::both_vanila_butter()
{
    cout << "\n##############################################################################\n";

    cout << "\n------- Students who likes both Vanila and Butterscotch Icecream -------\n";

    temp1 = head1;

    while (temp1 != NULL)
    {
        temp2 = head2;
        while (temp2 != NULL)
        {
            if (temp1->roll == temp2->roll)
            {
                cout << "\t"
                     << temp1->roll;
            }
            temp2 = temp2->next;
        }

        temp1 = temp1->next;
    }

    cout << "\n\n##############################################################################\n";
}


void Student_Data::neither_vanila_butter()
{
    cout << "\n##############################################################################\n";

    cout << "\n------- Students who likes Neither Vanila nor Butterscotch Icecream -------\n";

    temp = h1;

    while (temp != NULL)
    {
        temp3 = head3;
        f = 0;

        while (temp3 != NULL)
        {
            if (temp->roll == temp3->roll)
            {
                f = 1;
            }
            temp3 = temp3->next;
        }

        if (f == 0)
        {
            cout << "\t"
                 << temp->roll;
        }

        temp = temp->next;
    }

    cout << "\n\n##############################################################################\n";
}


int main()
{
    Student_Data SE2;
    int ch;
    while (ch != 7)
    {
        cout << "\n\n############################### Main Menu ######################################\n\n";
        cout << "1. Add the Roll Numbers of All Students in Class" << endl;
        cout << "2. Add the Roll Numbers of Students who likes Vanila Icescream" << endl;
        cout << "3. Add the Roll Numbers of Students who likes Butterscotch Icescream" << endl;
        cout << "4. Students who likes Vanila or Butterscotch Icescream" << endl;
        cout << "5. Students who likes both Vanila and Butterscotch Icescream" << endl;
        cout << "6. Students who likes neither Vanila nor Butterscotch Icescream" << endl;
        cout << "7. Exit" << endl;
        cout << "\n################################################################################\n";

        cout << "\nEnter your choice (1/2/3/4/5/6/7) -----> ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            SE2.Total_Students();
            break;

        case 2:
            SE2.vanila();
            break;

        case 3:
            SE2.butterscotch();
            break;

        case 4:
            SE2.vanila_butter();
            break;

        case 5:
            SE2.both_vanila_butter();
            break;

        case 6:
            SE2.neither_vanila_butter();
            break;
        }
    }

    return 0;
}
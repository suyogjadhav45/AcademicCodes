#include <iostream>
#include <string>

using namespace std;

class Node
{
private:
    int data;
    char ch;
    char status = '_';
    Node *next;
    Node *prev;

public:
    Node(int data, char ch)
    {
        this->data = data;
        this->ch = ch;
        next = NULL;
        prev = NULL;
    }

    friend class tickets;
};

class tickets
{
private:
    Node *start;
    Node *last;

public:
    tickets()
    {
        start = NULL;
        last = NULL;
    }

    void insert_at_end(int value, char s)
    {
        if (start == NULL)
        {
            Node *temp = new Node(value, s);
            start = temp;
            last = temp;
        }
        else
        {
            Node *temp = new Node(value, s);
            temp->next = start;
            temp->prev = last;
            start->prev = temp;
            last->next = temp;
            last = temp;
        }
    }

    void display()
    {
        if (start == NULL)
        {
            cout << "The Linked list is empty...\n";
        }
        else
        {
            Node *temp = start;

            while (temp != last)
            {
                cout << temp->ch << temp->data << " [_" << temp->status << "_] ";
                temp = temp->next;
            }
            cout << temp->ch << temp->data << " [_" << temp->status << "_] " << endl;
        }
    }

    void assign(char s)
    {
        for (size_t i = 1; i < 8; i++)
        {
            insert_at_end(i, s);
        }
    }

    void booking(int num)
    {

        Node *temp = start;

        while (temp->data != num)
        {
            temp = temp->next;
        }

        if (temp->status == '_')
        {
            temp->status = 'x';
            cout << "The seat has been booked successfully...\n";
        }
        else if (temp->status == 'x')
        {
            cout << "The seat has already been booked....\n";
        }
    }

    void cancelling(int num)
    {

        Node *temp = start;

        while (temp->data != num)
        {
            temp = temp->next;
        }

        if (temp->status == 'x')
        {
            temp->status = '_';
            cout << "The seat has been cancelled successfully...\n";
        }
        else if (temp->status == '_')
        {
            cout << "The seat is already empty try booking it....\n";
        }
    }
};

int main()
{

    tickets obj[10];
    int choice{0}, i{0}, num{0};
    char ch;

    string s = "ABCDEFGHIJ";

    for (size_t i = 0; i < 10; i++)
    {
        obj[i].assign(s[i]);
    }

    while (choice != 4)
    {
        cout << "\n*************MENU***************\n";
        cout << "1. Display the theatre\n2. Book a seat\n3. Cancel a seat\n4. Exit\n";
        cout << "********************************\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Displaying the theatre:\n";
            for (size_t i = 0; i < 10; i++)
            {
                obj[i].display();
            }
            break;

        case 2:
            int nb;
            cout << "How many seats you want to book : ";
            cin >> nb;
            for (int p = 0; p < nb; p++)
            {
                cout << "Enter the row alphabet (A/B/C/D/E/F/G/H/I/J) : ";
                cin >> ch;
                while (s[i] != ch)
                {
                    i++;
                }
                if (i > 9)
                {
                    cout << "Enter a valid seat number...\n";
                }
                else
                {
                    cout << "Enter the number: ";
                    cin >> num;
                    if (num > 7 || num < 1)
                    {
                        cout << "Enter a valid seat number...\n";
                    }
                    else
                    {
                        obj[i].booking(num);
                    }
                }
                i = 0;
            }
            break;

        case 3:
            int nb1;
            cout << "How many seats you want to book : ";
            cin >> nb1;
            for (int mb = 0; mb < nb1; nb1++)
            {
                cout << "Enter the row alphabet (A/B/C/D/E/F/G/H/I/J) : ";
                cin >> ch;
                while (s[i] != ch)
                {
                    i++;
                }
                if (i > 9)
                {
                    cout << "Enter a valid alphabet...\n";
                }
                else
                {
                    cout << "Enter the number: ";
                    cin >> num;
                    if (num > 7 || num < 1)
                    {
                        cout << "Enter a valid seat number...\n";
                    }
                    else
                    {
                        obj[i].cancelling(num);
                    }
                }
                i = 0;
            }

            break;

        case 4:
            cout << "\nThank You for using this program!!!\n";
            break;

        default:
            cout << "Enter a valid choice....\n";
            break;
        }
    }

    return 0;
}

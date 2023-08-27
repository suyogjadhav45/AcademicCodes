#include <iostream>
#include <stdlib.h>
using namespace std;

class node
{
public:
    int seat;
    string id;
    int status;
    node *next;
    node *prev;
};

class cinemax
{
public:
    node *head, *tail, *temp;
    cinemax()
    {
        head = NULL;
    }
    void display_seats();
    void book_seats();
    void create();
    void cancel_seats();
    void available_seats();
};

void cinemax::create()
{
    int i = 1;
    temp = new node;
    temp->seat = 1;
    temp->status = 0;
    temp->id = "null";
    tail = head = temp;
    for (int i = 2; i <= 70; i++)
    {
        node *p;
        p = new node;
        p->seat = i;
        p->status = 0;
        p->id = "null";
        tail->next = p;
        p->prev = tail;
        tail = p;
        tail->next = head;
        head->prev = tail;
    }
}

void cinemax::display_seats()
{
    {
        int r = 1;
        node *temp;
        temp = head;
        int count = 0;
        cout << "\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
        cout << "\n---------------------------------SEATING ARRANGEMENT--------------------------------\n";
        cout << "\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n";
        while (temp->next != head)
        {
            if (temp->seat / 10 == 0)
                cout << "S0" << temp->seat << " :";
            else
                cout << "S" << temp->seat << " :";

            if (temp->status == 0)
                cout << "[_] ";
            else
                cout << "[B] ";
            count++;
            if (count % 7 == 0)
            {
                cout << endl;
                r++;
            }
            temp = temp->next;
        }
        cout << "S" << temp->seat << " :";
        if (temp->status == 0)
            cout << " [_] ";
        else
            cout << " [B] ";
        cout << "\n\n\n***NOTE ----> 'B' = Seat is already booked***\n";
    }
}

void cinemax::book_seats()
{
    int x;
    string y;
label:
    cout << "Enter seat number to be booked -----> ";
    cin >> x;
    cout << "Enter your ID number(3 digits) -----> ";
    cin >> y;
    if (x < 1 || x > 70)
    {
        cout << "Seat number not VALID !!! Plz Enter correct seat number (1-70)\n";
        goto label;
    }
    node *temp;
    temp = new node;
    temp = head;
    while (temp->seat != x)
    {
        temp = temp->next;
    }

    if (temp->status == 1)
        cout << "Seat already booked!!!\n";
    else
    {
        temp->status = 1;
        temp->id = y;
        cout << "Seat " << x << " booked!\n";
    }
}

void cinemax::cancel_seats()
{
    int x;
    string y;
label1:
    cout << "Enter seat number to cancel booking -----> ";
    cin >> x;
    cout << "Enter you ID(3 digits) -----> ";
    cin >> y;
    if (x < 1 || x > 70)
    {
        cout << "Enter correct seat number to cancel (1-70)\n";
        goto label1;
    }
    node *temp;
    temp = new node;
    temp = head;
    while (temp->seat != x)
    {
        temp = temp->next;
    }
    if (temp->status == 0)
    {
        cout << "Seat not booked yet!!\n";
    }
    else
    {
        if (temp->id == y)
        {
            temp->status = 0;
            cout << "Seat Cancelled Successfully!!!\n";
        }

        else
            cout << "Wrong User ID !!! Seat cannot be cancelled!!!\n";
    }
}

void cinemax::available_seats()
{
    int r = 1;
    node *temp;
    temp = head;
    int count = 0;
    cout << "\n\n";
    cout << "\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
    cout << "\n---------------------------------SEATING ARRANGEMENT--------------------------------\n";
    cout << "\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n";
    while (temp->next != head)
    {
        {
            if (temp->seat / 10 == 0)
                cout << "S0" << temp->seat << " :";
            else
                cout << "S" << temp->seat << " :";
            if (temp->status == 0)
                cout << " [_] ";
            else if (temp->status == 1)
                cout << " [B] ";

            count++;
            if (count % 7 == 0)

            {

                cout << endl;
            }
        }
        temp = temp->next;
    }
    if (temp->status == 0)
    {
        cout << "S" << temp->seat << " :";

        if (temp->status == 0)
            cout << " [_] ";
    }
    cout << "\n\n\n***NOTE ----> 'B' = Seat is already booked***\n";
}

int main()
{
    cinemax Screen_1, Screen_2;
    int n, m, t, r;
    Screen_1.create();
    Screen_2.create();
    int primary_ch, ch1, ch2;
    while (primary_ch != 3)
    {
        cout << "\n\n\n########################################################################\n";
        cout << "\n--------------------------CINEMAX MOVIE THEATRE-------------------------\n";
        cout << "\n########################################################################\n";
        cout << "\n-------------------------------CHOICE MENU------------------------------\n";
        cout << "\n########################################################################\n";
        cout << "\n There are two screens in our Theatre ";
        cout<<"\n 1)Screen1 -----> ETERNALS";
        cout<<"\n 2)Screen2 -----> SOORYAWANSHI";
        cout<<"\n 3)Exit"<<endl;
        cout << "\nEnter you choice (1/2/3) -----> ";
        cin >> primary_ch;
        switch (primary_ch)
        {
        case 1:
            while (ch1 != 5)
            {
                cout << "\n\n########################################################################\n";
                cout << "\n-------------------------------CHOICE MENU------------------------------\n";
                cout << "\n########################################################################\n";
                cout << "\n1. Display Seating Arrangement" << endl;
                cout << "2. Book a Seat" << endl;
                cout << "3. Availability of Seat" << endl;
                cout << "4. Cancelation of Seat" << endl;
                cout << "5. Exit" << endl;
                cout << "\nEnter your Choice(1-5) -----> ";
                cin >> ch1;
                switch (ch1)
                {
                case 1:
                    Screen_1.display_seats();
                    break;
                case 2:
                    cout << "How many seats you want to book -----> ";
                    cin >> n;
                    for (int i = 0; i < n; i++)
                    {
                        Screen_1.book_seats();
                    }
                    break;
                case 3:
                    Screen_1.available_seats();
                    break;
                case 4:
                    cout << "How many seats you want to cancel -----> ";
                    cin >> m;
                    for (int i = 0; i < m; i++)
                    {
                        Screen_1.cancel_seats();
                    }
                    break;
                case 5:
                    break;
                default:
                    cout << "Wrong choice input\n";
                    break;
                }
            }
            break;

        case 2:
            while (ch2 != 5)
            {
                cout << "\n\n########################################################################\n";
                cout << "\n-------------------------------CHOICE MENU------------------------------\n";
                cout << "\n########################################################################\n";
                cout << "\n1. Display Seating Arrangement" << endl;
                cout << "2. Book a Seat" << endl;
                cout << "3. Availability of Seat" << endl;
                cout << "4. Cancelation of Seat" << endl;
                cout << "5. Exit" << endl;
                cout << "\nEnter your Choice(1-5) -----> ";
                cin >> ch2;
                switch (ch2)
                {
                case 1:
                    Screen_2.display_seats();
                    break;
                case 2:
                    cout << "How many seats you want to book -----> ";
                    cin >> t;
                    for (int i = 0; i < t; i++)
                    {
                        Screen_2.book_seats();
                    }
                    break;
                case 3:
                    Screen_2.available_seats();
                    break;
                case 4:
                    cout << "How many seats you want to cancel -----> ";
                    cin >> r;
                    for (int i = 0; i < r; i++)
                    {
                        Screen_2.cancel_seats();
                    }
                    break;
                case 5:
                    break;
                default:
                    cout << "Wrong choice input\n";
                    break;
                }
            }
            break;

        case 3:
            break;
        default:
            cout << "Wrong choice input\n";
            break;
        }
    }
    return 0;
}
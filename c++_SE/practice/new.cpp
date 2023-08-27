#include <iostream>
#include <string>
using namespace std;

class LinkedList;
class Node
{
private:
    Node *next;
    int data;

public:
    Node()
    {
        next == NULL;
        data = 0;
    }
    Node(int data)
    {
        this->data = data;
    }
    friend class LinkedList;
};

class LinkedList
{
private:
    Node *head;
    Node *tail;

public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void insert_at_end(int d)
    {
        if (head == NULL)
        {
            Node *temp = new Node(d);
            head = temp;
            tail = temp;
        }
        else
        {
            Node *temp = new Node(d);
            temp->next = NULL;
            tail->next = temp;
            tail = temp;
        }
    }

    void insert_at_start(int d)
    {
        if (head == NULL)
        {
            Node *temp = new Node(d);
            head = temp;
            tail = temp;
        }
        else
        {
            Node *temp = new Node(d);
            temp->next = head;
            head = temp;
        }
    }

    void insert_after(int d1, int d2)
    {
        if (head == NULL)
        {
            cout << "Linked List is Empty!!" << endl;
        }
        else
        {
            Node *temp = head;
            while (temp->data != d1 || temp == NULL)
            {
                temp = temp->next;
            }
            if (temp == NULL)
            {
                cout << "Element after which data should be inserted NOT FOUND!!" << endl;
            }
            else
            {
                Node *temp2 = new Node(d2);
                temp2->next = temp->next;
                temp->next = temp2;
            }
        }
    }

    void delete_from_end()
    {
        if (head == NULL)
        {
            cout << "Linked List is Empty!!" << endl;
        }
        else
        {
            Node *temp = head;
            while (temp->next != tail)
            {
                temp = temp->next;
            }
            temp->next = NULL;
            tail = temp;
        }
    }

    void deleteNode(int d)
    {
        if (head == NULL)
        {
            cout << "Linked List is Empty!!" << endl;
        }
        if (head->data == d)
        {
            Node *temp = head->next;
            delete head;
            head = temp;
        }
        else
        {
            Node *temp = head;
            bool flag=0;
            while (temp->next != NULL)
            {
                if (temp->next->data == d)
                {
                    Node *temp2 = temp->next;
                    temp->next = temp2->next;
                    delete temp2;
                }
                temp = temp->next;
            }
            cout<<"Element "<<d<<" has been deleted successfully!!\n"<<endl;
        }
        
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "Linked List is Empty!!" << endl;
        }
        else
        {
            Node *temp = head;
            while (temp != tail)
            {
                cout << temp->data << " ----> ";
                temp = temp->next;
            }
            cout << tail->data << endl;
        }
        cout << "\n";
    }

    void rev(Node* temp){
		if(temp->next == NULL){
			cout << temp->data << " ----> ";
		}
		else{
			rev(temp->next);
			cout << temp->data << " ----> ";
		}
	}

    void printrev(){
        if(head==NULL){
            cout<<"Linked List is Empty!!"<<endl;
        }
        else{
            rev(head);
            cout<<"\n\n";
            
        }
    }


    void sort_LL()
    {
        if (head == NULL)
        {
            cout << "Linked List is Empty!!" << endl;
            return;
        }
        else
        {
            Node *current;
            current = head;
            while (current != NULL)
            {
                Node *index;
                index = current->next;
                while (index != NULL)
                {
                    if (current->data > index->data)
                    {
                        int temp = current->data;
                        current->data = index->data;
                        index->data = temp;
                    }
                    index = index->next;
                }
                current = current->next;
            }
            cout << "LL has been sorted\n\n";
        }
    }

    Node* gethead(){
        return head;
    }

    void concatinate(LinkedList l2){
        LinkedList l3;
        Node *temp=head;
        while(temp != NULL){
            l3.insert_at_end(temp->data);
            temp=temp->next;
        }
        Node *temp2;
        temp2=l2.gethead();
        while(temp2 != NULL){
            l3.insert_at_end(temp2->data);
            temp2=temp2->next;
        }
        l3.display();
    }

    void sorted_merge(LinkedList l2){
        LinkedList l3;
        Node *temp=head;
        while(temp != NULL){
            l3.insert_at_end(temp->data);
            temp=temp->next;
        }
        Node *temp2;
        temp2=l2.gethead();
        while(temp2 != NULL){
            l3.insert_at_end(temp2->data);
            temp2=temp2->next;
        }
        l3.sort_LL();
        l3.display();
    }

};

int main()
{
    LinkedList l1,l2;
    l1.display();
    l1.insert_at_end(4);
    l1.insert_at_end(7);
    l1.insert_at_end(2);
    l1.insert_at_end(9);
    l1.insert_at_end(11);
    l1.insert_at_start(1);
    l1.display();
    l1.sort_LL();
    l1.display();
    l1.insert_after(7, 20);
    l1.display();
    l1.delete_from_end();
    l1.display();
    l1.deleteNode(7);
    l1.display();
    l1.printrev();
    l2.insert_at_end(40);
    l2.insert_at_end(6);
    l2.insert_at_end(35);
    l2.insert_at_end(0);
    l2.display();
    l1.concatinate(l2);
    l1.sorted_merge(l2);
    l1.display();
    return 0;
}
#include <iostream>
#include<queue>
using namespace std;

template <typename T>
class Nodeq
{
private:
    Nodeq *next;
    T data;

public:
    Nodeq()
    {
        next == NULL;
        // data = 0;
    }
    Nodeq(T data)
    {
        this->data = data;
        next = NULL;
    }
    template <typename Q>
    friend class Queue;
};

template <typename T>
class Queue
{
    Nodeq<T> *front;
    Nodeq<T> *rear;

public:
    int ct=0;
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    bool isEmpty()
    {
        if (front == NULL)
        {
            // cout<<"\nQueue is Empty!!"<<endl;
            return true;
        }
        return false;
    }

    void enqueue(T d)
    {
        Nodeq<T> *temp = new Nodeq<T>(d);
        if (front == NULL)
        {
            front = temp;
            rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
        ct++;
    }


    T dequeue()
    {
        if (!isEmpty())
        {
            Nodeq<T> *temp = front;
            T a = front->data;
            front = front->next;
            //cout<<"\nElement( "<<a<<" ) dequeued successfully!!"<<endl;
            delete temp;
            //cout<<"ct decremented"<<endl;
            ct=ct-1;
            return a;
           
        }
        return NULL;
    }

    int size(){
    	return ct;
    }

    

    void display()
    {
        if (!isEmpty())
        {
            Nodeq<T> *temp = front;
            cout << "\nThe Queue is : " << endl;
            cout << "\t-- ";
            while (temp != NULL)
            {
                cout << temp->data << " -- ";
                temp = temp->next;
            }
        }
    }
};

int main(){
    Queue<int>q;
    q.display();
    q.enqueue(5);
    q.enqueue(11);
    q.enqueue(2);
    q.enqueue(20);
    q.enqueue(7);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}
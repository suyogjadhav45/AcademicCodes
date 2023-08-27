#include <iostream>
using namespace std;

class Stack
{
	int top;
	arr[10];

public:
	Stack()
	{
		top = -1;
		for (int i = 0; i < 10; i++)
		{
			arr[i] = 0;
		}
	}
	void push(int d)
	{
		top++;
		arr[top] = d;
	}
	int pop()
	{
		int v = arr[top];
		top--;
		return v;
	}
	bool isEmpty()
	{
		if (top == -1)
		{
			return true;
		}
		return false;
	}
};

class Queue
{
	int front, rear;
	arrq[10];

public:
	Queue()
	{
		front = rear = -1;
		for (int i = 0; i < 10; i++)
		{
			arrq[i] = 0;
		}
	}
	void enqueue(int d)
	{
		if (front == -1)
		{
			front += 1;
		}
		rear += 1;
		arrq[rear] = d;
	}
	int dequeue()
	{
		if (front > rear)
		{
			return -1;
		}
		int v = arrq[front];
		front += 1;
		return v;
	}
	bool isEmpty()
	{
		if (front > rear)
		{
			return true;
		}
		return false;
	}
}

int
main()
{

	return 0;
}
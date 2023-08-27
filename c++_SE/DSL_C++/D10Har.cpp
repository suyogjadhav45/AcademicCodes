#include <iostream>
#include <string>
#define MAX 20
using namespace std;
class Stack
{
  int top;

public:
  char a[MAX];

  Stack()
  {
    top = -1;
  }
  bool push(int x);
  int pop();
  char gettop();
  bool isEmpty();
  bool isFull();
  int len(string s);
};

int Stack ::len(string s)
{
  int length = 0;
  for (int i = 0; s[i] != '\0'; i++)
  {
    length += 1;
  }
  return length;
}

char Stack::gettop()
{
  return a[top];
}

bool Stack::push(int x)
{
  if (top >= (MAX - 1))
  {
    cout << "Stack in Overflow";
    return false;
  }
  else
  {
    a[++top] = x;
    return true;
  }
}

int Stack::pop()
{
  if (top < 0)
  {
    cout << "Stack in Underflow";
    return 0;
  }
  else
  {
    int x = a[top--];
    return x;
  }
}

bool Stack::isEmpty()
{
  return (top < 0);
}

bool Stack::isFull()
{
  return (top == MAX - 1);
}

int ischaracter(char c)
{
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
  {
    return 1;
  }
  return 0;
}

int preference(char c)
{

  if (c == '*' || c == '/')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
  else
    return 0;
}
string convert(string infix)
{
  Stack stac;
  int i;
  string postfix = "";

  for (i = 0; i < stac.len(infix);)
  {
    if (ischaracter(infix[i]))
    {
      postfix += infix[i++];
    }
    else if (infix[i] == '(')
    {
      stac.push(infix[i++]);
    }
    else if (infix[i] == ')')
    {
      while (!stac.isEmpty() && stac.gettop() != '(')
      {
        postfix += stac.pop();
      }

      if (stac.gettop() == '(')
        stac.pop();

      i++;
    }
    else
    {
      if (stac.isEmpty())
      {
        stac.push(infix[i]);
        i++;
      }
      else
      {
        if (stac.gettop() != '(' && preference(stac.gettop()) >= preference(infix[i]))
        {
          postfix += stac.pop();
        }
        else
        {
          stac.push(infix[i++]);
        }
      }
    }
  }

  while (!stac.isEmpty())
  {
    char c = stac.pop();

    if (c == '(')
      continue;
    else
    {
      postfix += c;
    }
  }

  cout << "Infix to Postfix conversion is: " << postfix << endl;

  return postfix;
}

void evaluate(string postfix)
{
  int j = 0;
  Stack s;
  while (j < s.len(postfix))
  {
    int e1, e2, e3;
    if (postfix[j] == '1')
      s.push(1);
    if (postfix[j] == '2')
      s.push(2);
    if (postfix[j] == '3')
      s.push(3);
    if (postfix[j] == '4')
      s.push(4);
    if (postfix[j] == '5')
      s.push(5);
    if (postfix[j] == '6')
      s.push(6);
    if (postfix[j] == '7')
      s.push(7);
    if (postfix[j] == '8')
      s.push(8);
    if (postfix[j] == '9')
      s.push(9);
    if (postfix[j] == '0')
      s.push(0);
    if (postfix[j] == '+')
    {
      e1 = s.pop();
      e2 = s.pop();
      e3 = e2 + e1;
      s.push(e3);
    }
    if (postfix[j] == '-')
    {
      e1 = s.pop();
      e2 = s.pop();
      e3 = e2 - e1;
      s.push(e3);
    }

    if (postfix[j] == '*')
    {
      e1 = s.pop();
      e2 = s.pop();
      e3 = e2 * e1;
      s.push(e3);
    }

    if (postfix[j] == '/')
    {
      e1 = s.pop();
      e2 = s.pop();
      e3 = e2 / e1;
      s.push(e3);
    }
    j++;
  }
  cout << "\nEvaluated value:";
  cout << s.pop() << "\n"
       << endl;
}

int main()
{
  string infix, postfix, temp;
  int choice;
  while (1)
  {
    cout << "Enter Choice:\n1)Infix to postfix conversion\n2)Postfix Evaluation\n3)Exit\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
      cout << "Enter the infix expression : "; // enter the expression
      cin >> infix;
      temp = convert(infix);
      evaluate(temp);
      break;
    case 2:
      cout << "Enter a postfix expression to be evaluated:\n";
      cin >> postfix;
      evaluate(postfix);
      break;
    case 3:
      return 0;
      break;
    default:
      cout << "Wrong choice entered, try again\n";
    }
  }
  return 0;
}
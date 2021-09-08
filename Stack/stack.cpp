#include "stack.h"
#include<iostream>
#include<cmath>
using namespace std;
int max_size;

stack::stack()
{
	top = -1;
	cout << "enter the size of stack : " << endl;
	cin >> max_size;
	items = new char[max_size];
}

stack::~stack()
{
	top = -1;
	delete[]items;
}
 
int stack::is_empty()
{
	if (top == -1)
	  return 1;
	else
  	  return 0;
}
int stack::is_full()
{
	if (top == max_size - 1)
		return 1;
	else       
	    return 0;
}


void stack::push(char item)
{

	if (is_full())
	{
		cout << "the stack is overflow" << endl;
		return;
    }
		top++;
		items[top] = item;
}

char stack::pop()
{
	if (is_empty())
	{
		cout << "the stack is underflow " << endl;
	
	}

	char item = items[top];   /*"item" is a variable to access and take
	the element which we want to pop from stack.*/
	top--;
	return item;  //return the value which we poped from stack.
}

void stack::print_all_elements()
{ 
	cout << "the elemnts of the stack :" << endl;
	for (int x = 0; x <= top; x++)
	{
		cout << items[x]<<"  ";
    }
	cout << endl;
}
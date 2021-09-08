#include<iostream>
#include "Linked_List.h"
using namespace std;
int main()
{
	Linked_List l;
	l.insert_last(10);
	l.insert_last(20);
	l.insert_last(30);
	l.print(); //10 20 30 
	l.insert_position(40, 1);
	l.print();//40 10 20 30
	l.delete_position(3);
	l.print(); //40 10 30
	l.delete_last();
	l.print();//40 20
	system("pause");
	return 0;
}
#include "Linked_List.h"
#include<iostream>
using namespace std;

Linked_List::Linked_List()
{
	head = NULL;
}
void Linked_List::insert_last(int value)
{
	node* new_node = new node;
	new_node->data = value;
	new_node->next = NULL;
	if (head == NULL)
	{
		head = new_node;
	}
	else
	{
		node* temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new_node;
	}
}
void Linked_List::insert_position(int value, int position_num)
{
	node* new_node = new node;
	new_node->data = value;
	new_node->next = NULL;
	node* cur = head;
	node* pre = head;
	if (position_num == 1)
	{
		new_node->next = head;
		head = new_node;
		return;
	}
	for(int i = 1; i<position_num ;i++)
	{
		pre = cur;
		cur = cur->next;
	}
	pre->next = new_node;
	new_node->next = cur;
}
void Linked_List:: delete_last()
{
	node* cur = head;
	node* pre = head;
	while(cur->next !=NULL)
	{
		pre = cur;
		cur = cur->next;
	}
	pre->next = NULL;
	delete cur;
}
void Linked_List:: delete_position(int position_num)
{
	node* cur = head;
	node* pre = head;
	for (int i = 1; i < position_num; i++)
	{
		pre = cur;
		cur = cur->next;
	}
	pre->next = cur->next;
	delete cur;
}
void Linked_List:: print()
{
	node* temp = head;
	while (temp != NULL)
	{
		cout << temp->data << "  ";
		temp= temp->next;
	}
	cout << endl;
}
#include<iostream>
using namespace std;
#include "queue.h"
int main()
{
	Queue q;
	q.Enqueue(10);
	q.Enqueue(20);
	q.Enqueue(30);
	q.Enqueue(40);
	q.Dequeue();
	q.Dequeue();
	q.Dequeue();
	q.Enqueue(50);
	q.Enqueue(60);
	q.Dequeue();
	q.Enqueue(70);
	q.print_all_elements();
	
	system("pause");
	return 0;
}
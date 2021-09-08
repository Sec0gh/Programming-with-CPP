#include<iostream>
using namespace std;
#include "queue.h"
int main()
{
    Queue q;
    q.Enqueue(20);
    q.Enqueue(40);
    q.Enqueue(60);
    q.print_all_elements();
    cout << "The deleted item from queue is : " << q.Dequeue() << endl;
    cout << "The deleted item from queue is : " << q.Dequeue()<<endl;
   q.print_all_elements();
    q.Enqueue(80);
    q.print_all_elements();
    cout << "The deleted item from queue is : " << q.Dequeue()<<endl;
    q.print_all_elements();
    system("pause");
    return 0;
}
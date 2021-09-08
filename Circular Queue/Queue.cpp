#include "queue.h"
#include <iostream>
using namespace std;
int max_size;
Queue::Queue()
{
    rear = -1;
    front = -1;
    cout << "enter the size of Queue : " << endl;
    cin >> max_size;
    items = new int[max_size];
}
int Queue::is_full()
{
    if(front == (rear+1) % max_size )
        return 1;
    return 0;
}
int Queue::is_empty()
{
    if (rear == front == -1)
        return 1;
    return 0;
}
void Queue::Enqueue(int item)
{
    if (is_full())
    {
        cout << "Queue is full." << endl;
        return;
    }
    if (front == -1)
        front = 0;

    rear = (rear + 1) % max_size;

    items[rear] = item;
}
int Queue::Dequeue()
{
    if (is_empty())
    {
        cout << "Queue is empty." << endl;
        return -1;
    }
    int deleted_item = items[front];

    if (rear == front)
    {
        rear = -1;
        front = -1;
    }
    else
    {
        front = (front + 1) % max_size;
    }
    return deleted_item;
}
void Queue::print_all_elements()
{
    if (is_empty())
    {
        cout << "Queue is empty." << endl;
    }
    else
    {
        cout << "The data in queue are :" << endl;
        for (int i = front; i != rear; i = (i + 1) % max_size)
        {
            cout << items[i] << " ";
        }
        cout << items[rear];
    }
    cout << endl;
}
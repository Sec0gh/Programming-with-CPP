class Queue
{
    private:
        int rear;
        int front;
        int *items;
    public:
        Queue();
        int is_full();
        int is_empty();
        void Enqueue(int n);
        int Dequeue();
        void print_all_elements();
};


struct node
{
	int data;
	node* next;
};
class Linked_List
{
private:
	node* head;
public:
	Linked_List();
	void insert_last(int value);
	void insert_position(int value , int position_num);
	void delete_last();
	void delete_position(int position_num );
	void print();
};


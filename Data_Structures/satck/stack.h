class stack
{
private:
	char* items;
	int top;
public:
	stack();
	~stack();
	void push(char x);
	char pop();
	int is_empty();
	int is_full();
	void print_all_elements();
};

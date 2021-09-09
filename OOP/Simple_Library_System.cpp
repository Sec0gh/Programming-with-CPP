#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
inline void main_menu();
inline void choose_option();
inline void set_Book_title();
inline void set_Member_title();
class library //base class.
{
private:
	string library_name;
public:
	library() :library_name("none") {}  //default constructor.
	library(string name) :library_name(name) {}    //constructor by paremeter.
	void show_library_name()
	{
		cout << library_name << endl;
	}
	//pure virtual function.
	virtual void remove(int num) = 0;
	virtual void display() final  //final classifier.
	{
		cout << " This project made by \"MAHMOUD AHMED GHARIB\" " << endl;
	}
};
//derived class.
class book : public library    //inhertance from the base class(library).
{
private:
	string book_name, book_author;
	long book_id, stock, serial_number = 0;
	book* next;
	book* start = NULL;
public:
	book* create_node()
	{
		book* temp = new book;
		cout << "enter the name of the book : " << endl;
		getline(cin >> ws, temp->book_name);
		cout << "enter the name of the author of the book : " << endl;
		getline(cin >> ws, temp->book_author);
		cout << "enter book id : " << endl;
		cin >> temp->book_id;
		cout << "enter the number of books available : " << endl;
		cin >> temp->stock;
		temp->serial_number = ++serial_number;
		temp->next = NULL;
		return temp;
	}
	void add_book()
	{
		book* temp = start;
		if (start == NULL)
		{
			start = create_node();
		}
		else
		{
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = create_node();
		}
	}
	void remove(int pos)    //function overloading.
	{
		book* temp = start, * t;
		if (start == NULL)
		{
			cout << "There is no book in the library!!! Please add some books to the library." << endl;
		}
		else
		{
			for (int i = 0; i < pos - 2; i++)
			{
				temp = temp->next;
			}
			t = temp->next;
			temp->next = temp->next->next;
			delete t;
			cout << "This book was permanently deleted from the library!!!" << endl;
		}
	}
	void show_book()
	{
		book* temp = start;
		if (start == NULL)
		{
			cout << "There is no book in the library!!! Please add some books to the library.\n";
		}
		else
		{
			while (temp != NULL)
			{
				cout << setw(20) << temp->serial_number << setw(20) << temp->book_id << setw(20) << temp->book_name << setw(20) << temp->book_author << setw(20) << temp->stock << endl;
				temp = temp->next;
			}
		}
	}
};
//derived class.
class member : public library   //inhertance from the base class(library).
{
private:
	string member_name;
	long member_id, phone_number, serial_number = 0;
	member* next;
	member* start = NULL;
public:
	member* create_node()
	{
		member* temp = new member;
		cout << "enter the name of the new member : " << endl;
		getline(cin >> ws, temp->member_name);
		cout << "enter member id : " << endl;
		cin >> temp->member_id;
		cout << "enter phone number : " << endl;
		cin >> temp->phone_number;
		temp->next = NULL;
		temp->serial_number = ++serial_number;
		return temp;
	}
	void add_member()
	{
		member* temp = start;
		if (start == NULL)
		{
			start = create_node();
		}
		else
		{
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = create_node();
		}
	}
	void remove(int pos)      //function overloading.
	{
		member* temp = start, * t;
		if (start == NULL)
		{
			cout << "There are no members in the library!!! Please add some members to the library." << endl;
		}
		else
		{
			for (int i = 0; i < pos - 2; i++)
			{
				temp = temp->next;
			}
			t = temp->next;
			temp->next = temp->next->next;
			delete t;
			cout << "This member was permanently removed from the library!!!" << endl;
		}
	}
	void show_member()
	{
		member* temp = start;
		if (start == NULL)
		{
			cout << "There are no members in the library!!! Please add some members to the library.\n";
		}
		else
		{
			while (temp != NULL)
			{
				cout << setw(20) << temp->serial_number << setw(20) << temp->member_id << setw(20) << temp->member_name << setw(20) << temp->phone_number << endl;
				temp = temp->next;
			}
		}
	}
	static void main_menu()         //static method.
	{
		cout << "\t\tSelect from menu " << endl << endl;
		cout << "1) Add a new book to the library." << endl;
		cout << "2) Remove a book from the library." << endl;
		cout << "3) Show all the books of the library." << endl;
		cout << "4) Add a new member to the library." << endl;
		cout << "5) Remove a member from the library." << endl;
		cout << "6) Show all the members of the library." << endl;
		cout << "7) Press to exit." << endl;
	}
	 static void choose_option()     //static method.
	{  
		int num;
		cout << "Press 1 to return to the main menu." << endl;
		cout << "Press 2 to exit the program." << endl;
		cin >> num;
		if (num == 1)
		{
			system("CLS");
		member::main_menu();   //calling the static method.
		}
		else
		{
			exit(false);
		}
	}
};
void set_book_title()
{
	cout << "\n\n\n" << setw(20) << "Serial Number" << setw(20) << "Book ID" << setw(20) << "Book Name" << setw(20) << "Author" << setw(20) << "Stock" << "\n\n\n";
}
void set_member_title()
{
	cout << "\n\n\n" << setw(20) << "Serial Number" << setw(20) << "Member ID" << setw(20) << "Member Name" << setw(20) << "Phone Number" << "\n\n\n";
}
int main()
{
	cout << endl << "\t\t//////////////////////////////////////////////////////////////////////////////////////////////////" << endl << endl;
	cout << "\t\t//// Library system for the Faculty of Computers & Artificial Intelligence, Benha University ////" << endl << endl;
	cout << "\t\t////////////////////////////////////////////////////////////////////////////////////////////////" << endl << endl;
	int choice_num;   //to enter the number of choice from main menu.
	int pos;     //to enter the serial number of the book or the member to remove them.
	book b;
	member m;
	library* ptr1, * ptr2; //pointers from base class to do polymerphism.
	ptr1 = &b;             //polymerphism.
	ptr2 = &m;
	member::main_menu();       //calling the static method.
	while (true)
	{
		cout << "ENTER YOUR CHOICE FROM (1-7) : " << endl;
		cout << " SET > ";
		cin >> choice_num;
		switch (choice_num)
		{
		case 1:
			system("CLS");
			set_book_title();
			b.show_book();
			b.add_book();
			member::choose_option();  //calling the static method.
			break;
		case 2:
			system("CLS");
			set_book_title();
			b.show_book();
			cout << "enter the serial number of the book." << endl;
			cin >> pos;
			ptr1->remove(pos);
			member::choose_option();     //calling the static method.
			break;
		case 3:
			system("CLS");
			set_book_title();
			b.show_book();
			member::choose_option();    //calling the static method.
			break;
		case 4:
			system("CLS");
			set_member_title();
			m.show_member();
			m.add_member();
			member::choose_option();   //calling the static method.
			break;
		case 5:
			system("CLS");
			set_member_title();
			m.show_member();
			cout << "enter the serial number of the book."<<endl;
			cin >> pos;
			ptr2->remove(pos);
			member::choose_option();       //calling the static method.
			break;
		case 6:
			system("CLS");
			set_member_title();
			m.show_member();
			member::choose_option();      //calling the static method.
			break;
		case 7:
			exit(false);
			break;
		default:
			cout << "It is invalid choice...."<<endl <<"please enter a valid choice." << endl;
			break;
		}
	}
	return 0;
}
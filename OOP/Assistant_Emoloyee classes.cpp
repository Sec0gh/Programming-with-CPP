#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
//the base class.
class person
{
protected:
	string name;
	float salary;
	int id;
	string address;
public:
	//default constructor.
	person() :id(0), name("not found"), salary(0.0), address("unknown") {}
	//constructor by paremeter.
	person(int i, string n, float s, string a) : id(i), name(n), salary(s), address(a) {}
	virtual void seter() = 0;     //pure virtual function.
	virtual void display() = 0;   //pure virtual function.
};
//derived class.
class assistant : public person   //inhertance (from base class person).
{
private:
	float work_hours;
public:
	//default constructor.
	assistant() :person(0, "not found", 0.0, "unknown"), work_hours(0.0) {}
	//constructor by paremeter.
	assistant(int i, string n, float s, float h, string a) :person(i, n, s, a), work_hours(h) {}
	void seter()  //overriding function.
	{
		cout << "enter your name  :" << endl;
		cin >> name;
		cout << "enter the salary which you got :" << endl;
		cin >> salary;
		cout << "enter the ID for you :" << endl;
		cin >> id;
		cout << "enter the address where you live :" << endl;
		cin >> address;
		cout << "enter the number of work hours which you work :" << endl;
		cin >> work_hours;
	}
	float get_hours()
	{
		return work_hours;
	}
	void display()    //overriding fuction.
	{
		cout << "\t\t\" the data about you which you entered \"" << endl << endl;
		cout << "hello, " << name << endl;
		cout << "your salary is: " << salary << endl;
		cout << "your ID is : " << id << endl;
		cout << "you live in " << address << endl;
		cout << "you works " << work_hours << " in the day" << endl << endl;
	}
};
//derived class.
class employee : public person  //inhertance (from base class person).
{
private:
	string job_title;
	float bouns;
public:
	//default constructor.
	employee() :person(0, "not found", 0.0, "unknown"), job_title("unknown"), bouns(0.0) {}
	//constructor by paremeter.
	employee(int i, string n, float s, string a, string j, float b)
		:person(i, n, s, a), job_title(j), bouns(b) {}
	//overriding function.
	void seter()
	{
		cout << "enter your name :" << endl;
		cin >> name;
		cout << "enter the salary which you got :" << endl;
		cin >> salary;
		cout << "enter the ID for you :" << endl;
		cin >> id;
		cout << "enter the address which you live :" << endl;
		cin >> address;
		cout << "enter the job title for your job :" << endl;
		cin >> job_title;
		cout << "enter the bouns if you have :" << endl;
		cin >> bouns;
	}
	string get_title()
	{
		return job_title;
	}
	float get_bouns()
	{
		return bouns;
	}
	void display()       //overriding function.
	{
		cout << "\t\t\" the data about you which you entered \"" << endl << endl;
		cout << "hello, " << name << endl;
		cout << "your ID is : " << id << endl;
		cout << "your salary is: " << salary << endl;
		cout << "you live in " << address << endl;
		cout << "your job title is" << job_title << endl;
		cout << "your bouns is : " << bouns << endl << endl;
	}
};
void list()
{
	cout << "\t\tSelect from main menu :\n\n";
	cout << "1- enter data about the assistant." << endl;
	cout << "2- enter data about the employee." << endl;
	cout << "3- Press to exit." << endl;
}
void Choose_Option()
{
	int n;
	cout << "Press 1 to return to the main menu." << endl;
	cout << "Press 2 to exit the program." << endl;
	cin >> n;
	if (n == 1)
	{
		system("CLS");
		list();
	}
	else
	{
		exit(false);
	}
}
int main()
{
	person* ptr_ass, * ptr_emp;  //polymerphism.
	assistant a;
	employee e;
	ptr_ass = &a, ptr_emp = &e;
	int number;   //the number to enter the type of operation. 
	list();
	while (true)
	{
		cout << "enter the type of operation which you need >> ";
		cin >> number;
		switch (number)
		{
		case 1:
			system("CLS");
			ptr_ass->seter();
			system("CLS");
			ptr_ass->display();
			Choose_Option();
			break;
		case 2:
			system("CLS");
			ptr_emp->seter();
			system("CLS");
			ptr_emp->display();
			Choose_Option();
			break;
		default:
			cout << "invalid choice. Please enter a valid choice from (1-3)" << endl;
			break;
		}
	}
	return 0;
}
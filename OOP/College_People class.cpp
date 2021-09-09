#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
//base class college pepole( about the persons in the faculty).
class college_people
{
protected:
	string name;
	int id=0;
	string address;
	int age=0;
public:
	//pure virtual functions: to make overriding for the functions in other classes. 
	virtual void set_data() = 0;
	virtual void print() = 0;
};
//derived class (data about the professors in the faculty).
class professor :public college_people    //inhertance from the base class (college_pepole).
{
private:
	string doctoral_degree;
	string department;
	float salary;
public:
	void set_data()
	{
		cout << "enter the name of professor: " << endl;
		cin.ignore();
		getline(cin, name);
		cout << "enter his ID: " << endl;
		cin >> id;
		cout << "enter his age: " << endl;
		cin >> age;
		cout << "enter the address where he live: " << endl;
		cin.ignore();
		getline(cin, address);
		cout << "enter the department of professor: " << endl;
		getline(cin, department);
		cout << "enter the doctoral degree which he got: " << endl;
		getline(cin, doctoral_degree);
		cout << "enter his salary: " << endl;
		cin >> salary;
	}
	void print()
	{
		cout << "Professor Name" << setw(20) << "Age" << setw(20) << "ID"
			<< setw(20) << "Address" << setw(20)
			<< "Department" << setw(20) << "Doctoral Degree"
			<< setw(20) << "salary" << endl;
		cout << name << setw(20) << age << setw(20) << id
			<< setw(20) << address << setw(20)
			<< department << setw(20) << doctoral_degree
			<< setw(20) << salary << endl;
	}
};
//derived class.
class faculty_students :public college_people    //inhertance from class(college_pepole).
{
protected:
	int credit_hour;  //the number of hours for tou in the faculty.
	float GPA;
	string major;
public:
	void set_data()
	{
		cout << "enter the number of his credit hour in the faculty: " << endl;
		cin >> credit_hour;
		cout << "enter his GPA:" << endl;
		cin >> GPA;
		cout << "enter his major in the faculty: " << endl;
		cin.ignore();
		getline(cin, major);
	}
};
//derived class.
class graduate_students :public faculty_students  //inhertance from class(faculty_students).
{
private:
	string bachelors_degree;
public:
	//fuctions overriding.
	void set_data()
	{
		cout << "enter the name of graduate student: " << endl;
		cin.ignore();
		getline(cin, name);
		cout << "enter his ID: " << endl;
		cin >> id;
		cout << "enter his age: " << endl;
		cin >> age;
		cout << "enter the address where he live: " << endl;
		cin.ignore();
		getline(cin, address);
		faculty_students::set_data();
		cout << "enter his bachelor's degree which he got when he graduated" << endl;
		getline(cin, bachelors_degree);
	}
	void print()
	{
		cout << "Student Name" << setw(20) << "ID" << setw(20) << "Age" << setw(20)
			<< "Address" << setw(20) << "Credit Hour" << setw(20) << "GPA" << setw(20)
			<< "Major" << setw(20) << "Bachelor's degree" << endl;
		cout << name << setw(20) << id << setw(20) << age << setw(20) << address << setw(20)
			<< credit_hour << setw(20) << GPA << setw(20) << major << setw(20)
			<< bachelors_degree << endl;
	}
};
//derived class.
class students :public faculty_students      //inhertance from calss(faculty_students).
{
private:
	string courses_name[6];
	int serial_numbers[6];  //the serial number for courses.
public:
	void set_data()
	{
		cout << "enter the name of student: " << endl;
		cin.ignore();
		getline(cin, name);
		cout << "enter his ID: " << endl;
		cin >> id;
		cout << "enter his age: " << endl;
		cin >> age;
		cout << "enter the address where he live: " << endl;
		cin.ignore();
		getline(cin, address);
		faculty_students::set_data();
		cout << "\"Available to you only 6 courses\....set (enter) to reserve the courses." << endl;
		cin.ignore();
		for (int i = 0; i < 6; i++)
		{
			cout << "enter course number " << i + 1 << endl;
			cin >> courses_name[i];
			cout << "AND enter the serial number for the course " << endl;
			cin >> serial_numbers[i];
		}
	}
	void print()
	{
		cout << "Student Name" << setw(20) << "ID" << setw(20) << "Age" << setw(20)
			<< "Address" << setw(20) << "Credit Hour" << setw(20) << "GPA" << setw(20)
			<< "Major" << endl;
		cout << name << setw(20) << id << setw(20) << age << setw(20) << address << setw(20)
			<< credit_hour << setw(20) << GPA << setw(20) << major << endl;
		cout << "your courses that have been reserved" << endl;
		cout << "Courses Name" << setw(20) << "Serial Number" << endl << endl;
		for (int i = 0; i < 6; i++)
		{
			cout << courses_name[i] << setw(20) << serial_numbers[i] << endl;
		}
	}

	static void main_menu()   //static method.
	{
		cout << "\t\tSelect from menu " << endl << endl;
		cout << "(1) To enter data about professor." << endl;
		cout << "(2) To enter data about the graguate student." << endl;
		cout << "(3) To enter data about the student." << endl;
		cout << "(4) To print the data about the professor which you entered." << endl;
		cout << "(5) To print the data about the graduate student which you entered." << endl;
		cout << "(6) To print the data about the student which you entered." << endl;
		cout << "(7) Press to exit." << endl;
	}
	static void choose_option()   //static method.
	{
		int number;
		cout << "Press 1 to return to the main menu." << endl;
		cout << "Press 2 to exit the program." << endl;
		cin >> number;
		if (number == 1)
		{
			system("CLS");
			main_menu();
		}
		else
		{
			exit(false);
		}
	}
};
int main()
{
	college_people* ptr1, * ptr2, * ptr3;
	professor p;
	graduate_students g;
	students s;
	ptr1 = &p, ptr2 = &g, ptr3 = &s;    //polymerphism.
	int num;
	students::main_menu(); //calling the static method.
	while (true)
	{
		cout << "enter number from (1-7) to set your operation : " << endl;
		cout << "set your choice >> ";
		cin >> num;
		switch (num)
		{
		case 1:
			system("CLS");
			ptr1->set_data();
			students::choose_option();  //calling the static method.
			break;
		case 2:
			system("CLS");
			ptr2->set_data();
			students::choose_option();   //calling the static method.
			break;
		case 3:
			system("CLS");
			ptr3->set_data();
			students::choose_option();   //calling the static method.
			break;
		case 4:
			system("CLS");
			ptr1->print();
			students::choose_option();  //calling the static method.
			break;
		case 5:
			system("CLS");
			ptr2->print();
			students::choose_option();  //calling the static method.
			break;
		case 6:
			system("CLS");
			ptr3->print();
			students::choose_option();  //calling the static method.
			break;
		case 7:
			exit(false);
			break;
		default:
			cout << "Invalid choice...Please enter a valid choice." << endl;
			break;
		}
	}
	return 0;
}
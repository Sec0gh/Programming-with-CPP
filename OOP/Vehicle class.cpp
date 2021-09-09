#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
//the base class(vehicle).
class vehicle
{
protected:
	int reg_number; //Registration number of vehicle.
	float speed;
	string colour;
public:
	//constructor by paremter.
	vehicle(int reg, float s, string c) : reg_number(reg), speed(s), colour(c) {}
	//pure virtual functions.
	virtual void set_vehicle_data() = 0;
	virtual void display_data() = 0;
};
// derived class inheriting from base class(vehicle) 
class car : public vehicle
{
private:
	string car_type;
	int year_made;
public:
	//default constructor.
	car() :vehicle(2365, 300.0, "black"), car_type("lamborghini"), year_made(2019) {}
	//constructor by paremter.
	car(int reg, float s, string c, string ca_t, int y) :vehicle(reg, s, c)
	{
		car_type = ca_t;
		year_made = y;
	}
	void set_vehicle_data()  //overriding function.
	{
		cout << "enter the registration number of the car : " << endl;
		cin >> reg_number;
		cout << "enter the speed for this car : " << endl;
		cin >> speed;
		cout << "enter the colour for it : " << endl;
		cin >> colour;
		cout << "enter the car type : " << endl;
		cin >> car_type;
		cout << "enter the year when it was made : " << endl;
		cin >> year_made;
	}
	void display_data()      //overriding function.
	{
		cout << "\" the data which you entered about the car : \"" << endl << endl;
		cout << "the car have a registration number is " << reg_number << endl;
		cout << "the speed of the car is " << speed << endl;
		cout << "the colour of the car is " << colour << endl;
		cout << "the car type is " << car_type << endl;
		cout << "the year when the car was made is " << year_made << endl << endl;
	}
};
// derived class inheriting from base class(vehicle) 
class bus : public vehicle
{
private:
	int passenger_capacity;
public:
	//default constructor.
	bus() :vehicle(2365, 300.0, "black"), passenger_capacity(100) {}
	bus(int reg, float s, string c, int pass_cap) : vehicle(reg, s, c)   //constructor.
	{
		passenger_capacity = pass_cap;
	}
	void set_vehicle_data()  //overriding function.
	{
		cout << "enter the registration number of the bus : " << endl;
		cin >> reg_number;
		cout << "enter the speed of the bus : " << endl;
		cin >> speed;
		cout << "enter the colour for it : " << endl;
		cin >> colour;
		cout << "enter the capacity that a bus can carry : " << endl;
		cin >> passenger_capacity;
	}
	void display_data()      //overriding function.
	{
		cout << "\" the data which you entered about the bus : \"" << endl << endl;
		cout << "the car have a registration number is " << reg_number << endl;
		cout << "the speed of the car is " << speed << endl;
		cout << "the colour of the car is " << colour << endl;
		cout << "the capacity that a bus can carry is " << passenger_capacity << endl << endl;
	}
};
// derived class inheriting from base class(vehicle) 
class truck : public vehicle
{
private:
	int model_number;
	float weight;     //the weight of the things which truck can carry with tons.
public:
	//default constructor.
	truck() :vehicle(2365, 300.0, "black"), model_number(8697), weight(3) {}
	truck(int reg, float s, string c, int mod, float w) : vehicle(reg, s, c)  //constructor.
	{
		model_number = mod;
		weight = w;
	}
	void set_vehicle_data()  //overriding function.
	{
		cout << "enter the registration number of the truck : " << endl;
		cin >> reg_number;
		cout << "enter the speed of the truck : " << endl;
		cin >> speed;
		cout << "enter the colour for it : " << endl;
		cin >> colour;
		cout << "enter the model number for the truck : " << endl;
		cin >> model_number;
		cout << "enter the weight of the things which truck can carry :" << endl;
		cin >> weight;
	}
	void display_data()      //overriding function.
	{
		cout << "\" the data which you entered about the truck : \"" << endl << endl;
		cout << "the car have a registration number is " << reg_number << endl;
		cout << "the speed of the car is " << speed << endl;
		cout << "the colour of the car is " << colour << endl;
		cout << "the model number for the truck is " << model_number << endl;
		cout << "the weight of the things which truck can carry is " << weight << endl << endl;
	}
};
void menu()
{
	cout << "\t\t\tselect from main menu " << endl << endl;
	cout << "(1) enter 1 to add data about the car." << endl;
	cout << "(2) enter 2 to add data about the bus." << endl;
	cout << "(3) enter 3 to add data about the truck." << endl;
	cout << "(4) press to exit." << endl;
}
void options()
{
	int num;
	cout << "press 1 to return to the main menu." << endl;
	cout << "press 2 to exit the program." << endl;
	cin >> num;
	if (num == 1)
	{
		system("CLS");
		menu();
	}
	else
	{
		exit(false);
	}
}
int main()
{
	vehicle* ptr_car, * ptr_bus, * ptr_truck;   //polymerphism.
	car c1;
	bus b1;
	truck t1;
	ptr_car = &c1, ptr_bus = &b1, ptr_truck = &t1;
	int proc_num;  // the process number which you will choice from it.
	menu();
	while (true)
	{
		cout << "\t\tenter the number of process to do from (1-4) ==> ";
		cin >> proc_num;
		switch (proc_num)
		{
		case 1:
			system("CLS");
			ptr_car->set_vehicle_data();
			system("CLS");
			ptr_car->display_data();
			options();
			break;
		case 2:
			system("CLS");
			ptr_bus->set_vehicle_data();
			system("CLS");
			ptr_bus->display_data();
			options();
			break;
		case 3:
			system("CLS");
			ptr_truck->set_vehicle_data();
			system("CLS");
			ptr_truck->display_data();
			options();
			break;
		case 4:
			exit(false);
			break;
		default:
			cout << "please enter a valid choice from (1-4)." << endl;
			break;
		}
	}
	return 0;
}
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class bank_account
{
private:
	string name_account;
	int account_number;
	char type_account;
	float balance_amount;
public:
	bank_account() :name_account("Unknowm"), account_number(000), type_account('s'), balance_amount(1000)
	{}
	void set_name_account(string na)
	{
		name_account = na;
	}
	void set_number_account(int num)
	{
		if(num > 0)
			account_number = num;
		else
		cout << "invalid value"<<endl;
	}
	void set_type_account(char t)
	{
		if (t == 's' || t == 'c' || t == 'S' || t == 'C')
			type_account = t;
		else
			cout << "invalid value"<<endl;
	}
	void set_balance_amount(float b)
	{
		if (b > 0)
			balance_amount = b;
		else
			cout << "invalid value"<<endl;
	}
	char get_type_account()
	{
		return type_account;
	}
	float get_balance_amount()
	{
		return balance_amount;
	}
	float deposit_money(float amount)
	{
		cout << "Enter deposit amount " << endl;
		cin >> amount;
		balance_amount += amount;
		return balance_amount;
	}
	float withdraw(float withdraw_amount)
	{
		cout << "Enter the amount which you want to withdraw  " << endl;
		cin >> withdraw_amount;
		if (withdraw_amount >= 1000)
		{
			balance_amount -= withdraw_amount;
			return balance_amount;
		}
		else
			cout << "you can't withdraw amount less than 1000 " << endl;
	}
	void display()
	{
		cout << endl;
		cout << "The name of account is " << name_account << endl;
		cout << "The number of account is " << account_number << endl;
		cout << "The type of account is " << type_account << endl;
	    cout << "The balance amount is " << balance_amount << endl;
		cout << "_____________________________________________________________" << endl;
	}
};
int main()
{

	int size_array;
	string name;
	int num;
	char type;
	float balance;
	float amount=0;
	float withdraw_amount=0;

	cout << "Enter the number of customers " << endl;
	cin >> size_array;
	
	bank_account* customers = new bank_account[size_array];
	
	for (int x = 0; x < size_array; x++)
	{
		cout << "Entre the data for customer #" << x + 1 << endl<<endl;
		cout << "Enter the name for this account : ";
		cin.ignore();
		getline(cin,name);
		customers[x].set_name_account(name);
		cout << "Enter the number of account : ";
		cin >> num;
		customers[x].set_number_account(num);
		cout << "Enter the type of account (S for saving and C for current) : ";
		cin >> type;
		customers[x].set_type_account(type);
		cout << "Enter the balance of amount : ";
		cin >> balance;
		customers[x].set_balance_amount(balance);
		customers[x].deposit_money(amount);
    	customers[x].withdraw(withdraw_amount);
	cout << "The balance value after diposit and withdraw the money is " << customers[x].get_balance_amount() << endl;
	customers[x].display();
	}
	system("pause");
	return 0;
}
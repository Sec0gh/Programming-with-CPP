#include<iostream>
using namespace std;
#include "stack.h";
//APPLICATION OF STACK : FUNCTION TO EVALUATE POSTFIX EVALUATION.
int evaluate_postfix(string expression)
{
	stack  s;
	float operand1, operand2, result=0;
	for (int i = 0; i < expression.length(); i++)
	{
		if (isdigit(expression[i]))
			s.push(expression[i] - '0');
		else
		{
			operand2 = s.pop();
			operand1 = s.pop();
			switch (expression[i])
			{
			case '+':
				result = operand1 + operand2;
				break;
			case '-':
				result = operand1 - operand2;
				break;
			case '*':
				result = operand1 * operand2;
				break;
			case '/':
				result = operand1 / operand2;
				break;
			case '^':
				result = pow(operand1, operand2);//pow() =>to get the power to 2 operands.
				break;
			}
			s.push(result);
		}
	}
	return s.pop();
}
int main()
{
	string postfix_expression = "382/+5-";
	cout << "The result of this expression \"382/+5-\" is : " <<
		evaluate_postfix(postfix_expression) << endl;

	/*stack s;
	s.push(5);
	s.push(3);
	s.push(9);
	s.print_all_elements();
	cout<<"We poped this value from the stack => "<<s.pop()<<endl;
	cout << "the element in the stack became after poping :" << endl;
	s.print_all_elements();*/
	
	return 0;
	system("pause");
}
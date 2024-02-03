#include <iostream> 
#include <cassert> 
#include <cmath> 

using namespace std;

struct Equation
{
	double a, b, c;
	double x1, x2;
};

Equation* solve_system_of_linear_equations(Equation* en_1, Equation* en_2) {

	double determinant = en_1->a * en_2->b - en_2->a * en_1->b;
	if (determinant == 0) {
		if (en_1->c == en_2->c) {
			throw(1);
		}
		else
		{
			throw(2);
		}
		return en_1;
	}
	en_1->x1 = (en_1->c * en_2->b - en_2->c * en_1->b) / determinant;
	en_1->x2 = (en_1->a * en_2->c - en_2->a * en_1->c) / determinant;
	return en_1;
}
Equation* input_acvation_x()
{
	Equation* en_1 = new Equation;
	Equation* en_2 = new Equation;
	cout << "Enter first_1 argument: ";
	cin >> en_1->a;
	cout << "Enter second_1 argument: ";
	cin >> en_1->b;
	cout << "Enter thrist_1 argument: ";
	cin >> en_1->c;
	cout << "Enter first_2 argument: ";
	cin >> en_2->a;
	cout << "Enter second_2 argument: ";
	cin >> en_2->b;
	cout << "Enter thrist_2 argument: ";
	cin >> en_2->c;
	return solve_system_of_linear_equations(en_1, en_2);
}


/*
int main()
{
	try {
		Equation* re = input_acvation_x();
		cout << "x1 = " << re->x1 << endl;
		cout << "x2 = " << re->x2 << endl;
	}
	catch (int h) {
		if(h == 1)
			cout << "==" << endl;
		if (h == 2)
			cout << "--" << endl;
	}
	
}
*/
#include <iostream> 
namespace  school_algebra {
	struct Equation
	{
		double a, b, c;
		double x1, x2;
	};


	Equation* calculateEquation(Equation* en)
	{
		double D = en->b * en->b - 4 * en->a * en->c;
		Equation* re = new Equation;
		if (D <= 0)
		{
			throw(false);
		}
		re->x1 = (-en->b - sqrt(D)) / (2 * en->a);
		re->x2 = (-en->b + sqrt(D)) / (2 * en->a);
		return re;
	}

	Equation* input_acvation()
	{
		Equation* en = new Equation;
		cout << "Enter first argument: ";
		cin >> en->a;
		cout << "Enter second argument: ";
		cin >> en->b;
		cout << "Enter thrist argument: ";
		cin >> en->c;
		return en;
	}


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

}
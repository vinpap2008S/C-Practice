#include <iostream> 
#include <cassert> 
#include <cmath> 
#include "algebra.h"

using namespace std;

int main()
{
	school_algebra::Equation* en = school_algebra::input_acvation();
	try {
		school_algebra::Equation* re = calculateEquation(en);
		cout << "x1 = " << re->x1 << endl;
		cout << "x2 = " << re->x2 << endl;
	}
	catch (bool) {
		cout << "Descriminant less than 0!" << endl;
	}
	try {
		school_algebra::Equation* re = school_algebra::input_acvation_x();
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

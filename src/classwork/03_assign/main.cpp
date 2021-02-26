//Write the include statement for decisions.h here
#include<iostream>
#include "decision.h"


//Write namespace using statements for cout and cin
using std::cout;    using std::cin;



int main() 
{	
	
	// get input from user
	int grade_from_user;
	cout << "Please input in a numeric grade between 0 and 100: ";
	cin >> grade_from_user;


	// verify if input that user entered stays between range 0 to 100
	if (grade_from_user > 0 && grade_from_user < 100)
	{
		cout << "Using if, your letter grade would be: " << get_letter_grade_using_if(grade_from_user) << "\n";
		cout << "Using switch, your letter grade would be: " << get_letter_grade_using_switch(grade_from_user) << "\n";
	}
	
	else

	{
		cout << "The number that you entered was not in range \n";
	}

	return 0;
}


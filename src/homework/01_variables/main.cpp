#include <iostream>
using namespace std;
#include "variables.h"



//write include statements


//write namespace using statement for cout


/*
Call multiply_numbers with 10 and 10 parameter values and display function result
*/

int main()
{
	//define variables
	double mealAmount,tiprate,total=0;

	//get input from the user
	cout<<"Please enter meal amount :$";
	cin>>mealAmount;

	cout<<"Please enter tip rate percentage :%";
	cin>>tiprate;

	//calculate tax amount
	double taxAmount=get_sales_tax_amount(mealAmount);

	//calculate tip amount
	double tipAmount=get_tip_amount(mealAmount,tiprate);

	//calculate total amount
	total=mealAmount+taxAmount+tipAmount;

	//Display output results
	cout<<"Meal Amount :$"<<mealAmount<<endl;
	cout<<"Tax Amount :$"<<taxAmount<<endl;
	cout<<"Tip Amount :$"<<tipAmount<<endl;
	cout<<"Total Amount :$"<<total<<endl;

	return 0;
}

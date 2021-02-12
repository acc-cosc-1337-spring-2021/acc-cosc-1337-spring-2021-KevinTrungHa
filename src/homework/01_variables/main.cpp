
//write include statements
#include <iostream>
#include <cmath>
#include "variables.h"

//write namespace using statement for cout
using std::cout, std::cin;

/*
Call multiply_numbers with 10 and 10 parameter values and display function result
*/

int main()
{
	//define variables
	double mealAmount{0};
	double tipAmount{0};
	double taxAmount{0};
	double tipRate{0};
	double total{0};

	//get input from the user
	cout<<"Please enter your meal amount :";
	cin>>mealAmount;

	cout<<"Please enter the tip rate percentage :";
	cin>>tipRate;

	//calculate tax amount
	taxAmount = get_sales_tax_amount(mealAmount);

	//calculate tip amount
	tipAmount = get_tip_amount(mealAmount,tipRate);

	//calculate total amount
	total=mealAmount+taxAmount+tipAmount;

	//Display output results
	cout<<"Meal Amount :$"<<mealAmount<<'\n';
	cout<<"Tax Amount :$"<<taxAmount<<'\n';
	cout<<"Tip Amount :$"<<tipAmount<<'\n';
	cout<<"Total Amount :$"<<total<<'\n';

	return 0;
}


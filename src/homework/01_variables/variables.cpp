#include "variables.h"
#include <iostream>

using std::cout;

//write code for multiply_numbers function here
//function returns product of num1 and num2


double get_sales_tax_amount(double meal_amount)
{
	double tax_rate{.0675};
	double tax_payed{0};

	tax_payed = meal_amount * tax_rate;
	return tax_payed;

}

double get_tip_amount(double meal_amount, double tip_rate)
{
	double tip_amount{0};

	tip_amount = meal_amount * tip_rate;
	return tip_amount;

}


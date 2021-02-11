#include <iostream>
using namespace std;
#include "variables.h"



// //example
// int add_numbers(int num1, int num2)
// {
// 	return num1 + num2;
// }

//write code for multiply_numbers function here
//function returns product of num1 and num2


const double tax_rate = 6.75;

	double get_salex_tax_amount(double meal_amount)
	{
		return meal_amount*(tax_rate/100);
	}

	double get_tip_amount(double meal_amount, double tip_rate)
	{
		return meal_amount*(tip_rate/100);
	}




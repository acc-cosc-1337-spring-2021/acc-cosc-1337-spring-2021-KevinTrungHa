#include<iostream>
#include "if.h"//to use is_even function here

using std::cout;
using std::cin;

int main() 
{
	//create a bool variable named even
	bool even;
	//create an int variable named value
	int value;

	//prompt user for a keyboard number
	cout<<"Enter a number: ";
	//assign the number to the value variable
	cin>>value;

	//call the is_even function with value as its argument
	//and assign its return value to the even variable
	even = is_even(value);

	//display even if number is even
	if(even == true)
	{
		cout<<value<<" is even.":
	}

	return 0;
}

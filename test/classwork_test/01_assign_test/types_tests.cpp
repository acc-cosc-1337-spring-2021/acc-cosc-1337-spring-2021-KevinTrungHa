// #include "types.h"
// #include "types.cpp"
// #include "main.cpp"
#include <iostream>
#include <cassert>
using namespace std;

 //Create an assertion to verify that calling the multiply_numbers function with parameter 10
 //returns the value 50.


 
int multiply_numbers(int value)

{
	assert(value == 10);
	return value * 5;
}


int main()

{

	//show the result when the parameter is 10
	cout<<"\n\nHere is the first result:\n\n";
	cout<<multiply_numbers(10);

	//show the result when the parameter is not equal to 10
	cout<<"\n\nThe second result is:\n\n";
	cout<<multiply_numbers(15);
	return 0;


}

//Create an assertion to verify that calling the multiply_numbers function with parameter 2
//returns the value 10.

int multiply_number(int value)

{
	assert(value == 2);
	return value * 5;
}


int main2()

{
	//show the result when the parameter is 2
	cout<<"\n\nHere is the first result:\n\n";
	cout<<multiply_numbers(2);

	//show the result when the parameter is not equal to 2
	cout<<"\n\nThe second result is:\n\n";
	cout<<multiply_numbers(15);
	return 0;
}

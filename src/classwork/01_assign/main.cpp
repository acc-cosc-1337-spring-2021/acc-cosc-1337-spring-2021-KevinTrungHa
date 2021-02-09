//Write the include statement for types.h here

//Write include for capturing input from keyboard and displaying output to screen

#include <iostream>
#include "types.h"
#include "types.cpp"

using std::cin;
using std::cout;

int main()

{

	int num;
	int num1 = 4;
	int result;

	cout << "Please input an integer number: ";
	cin >> num;

	result = multiply_numbers(num);

	cout << "Here is the result: " << result;

	result = multiply_numbers(num1);

	cout<< "Here is the result of the new value: " << result;

	return 0;

}


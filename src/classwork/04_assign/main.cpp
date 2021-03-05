//write includes statements
#include <iostream>
#include "loops.h"
//write using statements for cin and cout
using std::cout; using std::cin;

/*
Use a do while loop to prompt the user for 
a number, call the factorial function, and display the number's
factorial.  Also, loop continues as long as user wants to.
*/
int main() 
{
	char choice;
	//use a do while loop to prompt the user for a number
	do
	{
		auto numb{1.0};
		int product;
		cout<<"Enter an integer between 1 and 10: ";
		cin>>numb;
		while (numb < 1 || numb > 10) //input number has to be in range of 1 to 10
		{
			cout<<"\nThe integer must stay in range between 1 and 10. Please try input the number again.\n";
			cout<<"Please enter an integer between 1 and 10: ";
			cin>>numb;
		}
		int num = numb;
		product = factorial(num); 
		cout<<"\n"<<num<<"! = "<<product;
		cout<<"\nEnter y to continue: "; //loop continues as long as user wants to
		cin>>choice;

	} 
	
	while (choice == 'y' || choice == 'Y');
	
	return 0;
}
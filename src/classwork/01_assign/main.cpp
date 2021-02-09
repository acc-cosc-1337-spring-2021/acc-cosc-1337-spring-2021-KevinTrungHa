//Write the include statement for types.h here

//Write include for capturing input from keyboard and displaying output to screen
#include <iostream>
#include "types.h"
using namespace std;
  
int main()
{

   int num;

  
cout << "Enter a number!\n" ;
cin >> num;
  

int result = multiply_numbers(num);
cout<< "Result ="<<result <<endl;
  

int num1 = 4;
  

   result = multiply_numbers(num1);
   cout << "Result =" + result<<endl;
  
return 0;
}

//cpp

//write the function code that returns the factorial of num using 
//a loop of my choice

#include "loops.h"

int factorial(int num)
{
    int product = 1;

    for(int productCount = 1; productCount <= num; productCount++)
    {
        product = product * productCount
    }

    return product;
}
//cpp
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
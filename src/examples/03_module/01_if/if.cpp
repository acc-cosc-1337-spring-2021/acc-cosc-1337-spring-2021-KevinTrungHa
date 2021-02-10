//write include statement for if header

#include "if.h"

//write code for the is_even function that returns true if num is even, false otherwise

bool is_even(int num)

{
    auto even = false; 

    if(num % 2 == 0) //% modulus returns the remainder
    {
        even = true;
    }

    return even;

    //or use return num % 2 == 0; - consise way 
}

//write code for function named overtime that accepts a double hours and returns true if 
//hours over 40, false otherwise



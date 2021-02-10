//DON'T ERASE THIS 
//int sum_numbers(int num1, int num2);


#include <iostream>
using namespace std;


//create an int value-function prototype named multiply_numbers 
//with one int parameter named num1

int multiply_numbers(int num1);
int main2()

{
    int num1;
    cout << "Please enter a number:";
    cin >> num1;
    int result = multiply_numbers(num1);
    cout<<"Result:"<<result;
    return 0;
}




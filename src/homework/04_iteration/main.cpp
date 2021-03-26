//write include statements
#include<iostream>
#include "dna.h"
//write using statements
using std::cout;
using std::cin;

/*
Write code that prompts user to enter 1 for Get GC Content, 
or 2 for Get DNA Complement.  The program will prompt user for a 
DNA string and call either get gc content or get dna complement
function and display the result. Program runs as long as 
user enters a y or Y.
*/
int main() 
{	
	char choice;
	do
	{
		int num_choice;
		string dna;
		cout<<"Enter 1 for Get GC Content, or 2 for Get DNA Complement: ";
		cin>>num_choice;
		
		if(num_choice == 1)
		{	
			cout<<"\nEnter the DNA string: ";
			cin>>dna;
			double gc_content = get_gc_content(dna);
			cout<<"\nThe GC content is: "<<gc_content;
		}

		else
		{
			cout<<"\nEnter the DNA string: ";
			cin>>dna;
			string complement = get_dna_complement(dna);
			cout<<"\nThe DNA complement is: "<<complement;
		}

		cout<<"\nEnter y to continue: ";
		cin>>choice;
	} while(choice == 'y' || choice == 'Y');
	
	return 0;
}
#include "dna.h"
/*
Write code for function get_gc_content that accepts
a const reference string parameter and returns a double.
Calculate GC content:
Iterate string count Gs and Cs, divide count by string length.
Return quotient.
*/
double get_gc_content(const string& dna)
{
    double cnt = 0;
    for(std::size_t i=0; i < dna.size(); ++i)
    {
        if(dna[i] == 'c' || dna[i] == 'C' || dna[i] == 'g' || dna[i] == 'G')
        {
            cnt++;
        }
    }
    return cnt/dna.size();
}

/*
Write code for function get_reverse_string that
accepts a string parameter and returns a string reversed.
*/
string get_reverse_string(string dna)
{
    string reverse("");
    for(int i = dna.size() - 1; i >= 0; --i)
    {
        reverse.push_back(dna[i]);
    }
    return reverse;
}

/*
Write prototype for function get_dna_complement that
accepts a string dna and returns a string.
Calculate dna complement:
a. call function get_reverse_string(dna), save results to a local string variable
b. iterate local string variable and
    replace A with T, T with A, C with G and G with C
c. return string

*/
string get_dna_complement(string dna)
{
    string reverse = get_reverse_string(dna);

    for(auto& c: reverse)
    {
        if(c == 'a' || c == 'A')
        {
            c = 'T';
            continue;
        }
        
        else if(c == 't' || c == 'T')
        {
            c = 'A';
            continue;
        }

        else if(c == 'c' || c == 'C')
        {
            c = 'G';
            continue;
        }

        else
        {
            c = 'C';
        }
    }
    
    return reverse;

}

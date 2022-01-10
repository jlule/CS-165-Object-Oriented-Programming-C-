/***********************************************************************
* Program:
*    Checkpoint 02b,Complex Numbers
*    Brother Comeau, CS165
* Author:
*    James Lule
* Summary:
*    Summaries are not necessary for checkpoint assignments.
*
*
* ***********************************************************************/


#include <iostream>
using namespace std;


struct Complex
{
   double c1;
   double c2;  
};


void prompt(Complex &number)
{
   cout << "Real: ";
   cin >> number.c1;

   cout << "Imaginary: ";
   cin >> number.c2;
   
}


void display(Complex &number)
{
   cout << number.c1 << " + " << number.c2 << "i";   
}

/**********************************************************************
 * Function: addComplex
 * Purpose: Adds two complex numbers together and returns the sum.
 ***********************************************************************/
Complex addComplex(const Complex & x, const Complex & y)
{

   Complex sum;

   sum.c1 = x.c1 + y.c1;
   sum.c2 = x.c2 + y.c2;

   return sum;
}


/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{

   Complex real;
   Complex imag;


   prompt(real);
   prompt(imag);


   Complex sum;


   sum = addComplex(real, imag);
   
   cout << "\nThe sum is: ";
   display(sum);
   cout << endl;
 
   return 0;
}


/***********************************************************************
* Program:
*    Assignment: Checkpoint 3a 
*    Brother  Comeau, CS165
* Author:
*    James Lule
* Summary: 
*    Enter a brief description of your program here!  Please note that if
*    you do not take the time to fill out this block, YOU WILL LOSE POINTS.
*    Before you begin working, estimate the time you think it will
*    take you to do the assignment and include it in this header block.
*    Before you submit the assignment include the actual time it took.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
using namespace std;

int prompt() throw (const char *);

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/

int main()
{
	try
	{
		int number = prompt();
		cout << "The number is " << number << "." << endl;
	}
	catch (const char * message)
	{
		cout << "Error: The number cannot be " << message << endl;
	}
   
   

   return 0;
}


int prompt() throw (const char *)
{
	int userNum;

	cout << "Enter a number: ";
	cin >> userNum;
	if (userNum < 0)
	{
		throw "negative.";
	}
	if (userNum > 100)
	{
		throw "greater than 100.";
	}
	if (userNum%2)
	{
		throw "odd.";
	}
	return userNum;
}



/***********************************************************************
** Program:
*    Checkpoint 02a Structs
*    Brother Comeau, CS165
* Author:
*    James Lule
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
using namespace std;

struct User {
   char firstName[256];
   char lastName[256];
   int idNumber; 
};

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 *Write a C++ program according to the following:
 *Create a struct for a Student, that contains a string for a
 *first name, a string for a last name, and an integer for an id.
 *Create a function called, displayStudent, that accepts a 
 *student struct, and displays their information in the following 
 *format: "id# - FirstName LastName".
 ***********************************************************************/

int displayStudent()
{
   
   User student;
   
   cout << "Please enter your first name: ";
   cin >> student.firstName;
   cout << "Please enter your last name: ";
   cin >> student.lastName;
   cout << "Please enter your id number: ";
   cin >> student.idNumber;
   cout << endl;
   cout << "Your information:" << endl;
   cout << student.idNumber << " - " << student.firstName << " ";
   cout << student.lastName << endl;
   return 0;
}



int main()
{
  displayStudent();

   return 0;
}

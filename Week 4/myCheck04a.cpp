/***********************************************************************
* Program:
*    Assignment: Checkpoint 04a, Classes
*    Brother Comeau, CS165
* Author:
*   James Lule
* ************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

class Book {
  
    string title;
    string author;
  
    public:
    void prompt();
    void display();    
};

void Book :: prompt()
{
    cout << "Title: ";
    getline(cin,  title);
 
    cout << "Author: ";
    getline(cin, author); 
    return;
}

void Book :: display()
{
    cout << "\"" << title << "\"" << " by " << author << endl; 
    return;
}

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/


int main()
{
   Book book;
   
   book.prompt();
   
   book.display();
   
    return 0;
}







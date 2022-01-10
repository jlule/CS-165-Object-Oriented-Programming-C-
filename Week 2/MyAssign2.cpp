/***********************************************************************
* Program:
*    Assignment 02 Digital Forensics
*    Brother Comeau, CS165
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
#include <iomanip>
#include <fstream>
using namespace std;


struct AccessRecord
{
   long int timeStamp;
   char fileName[256];
   char user[256];
};

struct  Records
{
   long int startTime;
   long int endTime;
   char accessFile[256];
   int fileLength;
   int results[1000];
   int numOfResults;
};




void filePrompt(Records &input)
{
   cout << "Enter the access record file: ";
   cin >> input.accessFile;
   cout << endl;
   return;
}

void timePrompt(Records &input)
{
   cout << "Enter the start time: ";
   cin >> input.startTime;
   cout << "Enter the end time: ";
   cin >> input.endTime;

   return;
}

void readFile(Records &input, AccessRecord record[1000])
{
   int i = 0;
   ifstream fin(input.accessFile);
   if (fin.fail())
   {
      cout << "Unable to open: " << input.accessFile << endl;
      return;
   }
   char text[256];
   while (!fin.eof())
   {
      fin >> record[i].fileName;
      fin >> record[i].user;
      fin >> record[i].timeStamp;
      i++;
      input.fileLength = i;
   }


   fin.close();

   return;
}





void fileSearch(Records &input, AccessRecord record[1000])
{
   int j = 0;
   for (int i = 0; i < input.fileLength; i++)
   {
      if ( input.startTime <= record[i].timeStamp
         && input.endTime >= record[i].timeStamp)
      {
         input.results[j] = i;
         j++;
      }
   }
   input.numOfResults = j;
   return;
}


void displayResults(Records input, AccessRecord record[1000])
{
   cout << endl;
   cout << "The following records match your criteria:" << endl;
   cout << endl;
   cout << setw(15) << "Timestamp"
        << setw(20) << "File"
        << setw(20) << "User"
        << endl;
   cout << "--------------- ------------------- -------------------" << endl;

   for (int i = 0; i < input.numOfResults; i++)
   {
      int tempI = input.results[i];
      cout << setw(15) << record[tempI].timeStamp
           << setw(20) << record[tempI].fileName
           << setw(20) << record[tempI].user
           << endl;
   }

   cout << "End of records" << endl;

   return;
}

int main()
{
   Records R1;
   AccessRecord record[1000];

   filePrompt(R1);
   timePrompt(R1);
   readFile(R1, record);
   fileSearch(R1, record);
   displayResults(R1, record);

   return 0;
}

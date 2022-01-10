/***********************************************************************
* Program:
*    Assignment 03
*    Brother Comeau, CS165
* Author:
*    James Lule
* Summary: 
*  Actual:     7.0 hrs
*      Please describe briefly what was the most difficult part.
***************************************************************************/


#include <iomanip>
#include <fstream>
#include <iostream>
#include <sstream>
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


void parseFile(Records &input, AccessRecord record[1000])
{
    ifstream fin(input.accessFile);
   if (fin.fail())
   {
      cout << "Unable to open: " << input.accessFile << endl;
      return;
   }
   fin.close();
   return;
}

void parseLine(Records &input, AccessRecord record[1000])
{
    stringstream ss(input.accessFile);
   int i = 0;

    while (!ss.eof())
   {
      ss >> record[i].fileName;
      ss >> record[i].user;
      ss >> record[i].timeStamp;
      if(record[i].timeStamp > 10000000000 | record[i].timeStamp < 1000000000)
         {cout << "Error parsing line: " << record[i].fileName << record[i].user << record[i].timeStamp;
          cout << endl;
         }
      i++;
   }
      input.fileLength = i;

   if (ss.fail())
   {
      cout << "Error parsing line: " << record[i].fileName << record[i].user << record[i].timeStamp << endl;
   }

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
   parseFile(R1, record);
   parseLine(R1, record);
   timePrompt(R1);
   readFile(R1, record);
   fileSearch(R1, record);
   displayResults(R1, record);
   return 0;
}

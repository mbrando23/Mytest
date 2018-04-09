/***********************************************************************
* Program:
*    Assignment 02, Digital Forensics
*    Brother Alvey, CS165
* Author:
*    Milton Nogueira Brando Neto
* Summary:  
*    This program scan through a log to identify users who accessed files
*    in a particular window of time.
*    Estimated:  5.0 hrs   
*    Actual:     5.0 hrs
*      The most difficult part was to make a list into a specific time. 
************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <iomanip>
using namespace std;


/**********************************************************************
 *  RECORD
 *  a list of users acess into a specific period of time
 ***********************************************************************/
struct Record
{
   string userName;
   string fileName;
   long timeStamp;
};

string getText(const char * prompt);
bool   read(string fileName, Record records[]);
void   promptTime(long &start, long &end);
void   display(const Record period[], long, long);

/**********************************************************************
 *  MAIN() calls other functions in order to access a file and to display
 *  a list of users into a specific period of time
 ***********************************************************************/
int main()
{
   string fileName;               // declare file name to prompt the user
   Record records[500];           // a structure variable to read a file
   Record period[500];            // a structure variable to display
   long start;                    // logged time
   long end;                      // logged time
   fileName = getText("Enter the access record file: "); // prompt
   if (!read(fileName, records))  // reading a file
      return 1;
   promptTime(start, end);        // handling the period of time
   for (int i = 0; i < 500; i++)
   {
      if (records[i].timeStamp < end && records[i].timeStamp > start)
         period[i] = records[i];
   }
   
   display(period, start, end);
   
   return 0;
}


/************************************************************************
 * GET TEXT
 * Generic prompt function
 ***********************************************************************/
string getText(const char * prompt)
{
   cout << prompt;                
   string input;
   cin >> input;
   return input;                   // returnign a string
}


/************************************************************************
 * READ
 * Read a list from the file and store it in an array of structs  
 ***********************************************************************/
bool read(string fileName, Record records[])
{
   ifstream fin(fileName.c_str());

   
   if (fin.fail())                    // checks for any type of error 
   {
      cout << "Unable to open file " 
           << fileName  
           << endl; 
      return false;                   // reports failure to the user
   }
   
   while (!fin.eof())                 // handling the end of fin
   {
      // loop and read through the array 
      for (int i = 0; i < 500; i++)
      {
         fin >> records[i].fileName;
         fin >> records[i].userName;
         fin >> records[i].timeStamp; 
         if (fin.fail())
         {
            fin.close();             // handling possible errors
            return true;                
         }        
      }
   }
      
   fin.close();                      // closing file
   return true;
   
}

/************************************************************************
 * PROMPT
 * Prompt the user for a start time and an end time for consideration
 ***********************************************************************/
void promptTime(long &start, long &end)
{
   cout << endl;
   cout << "Enter the start time: ";
   cin  >> start;                    // fetching properly to use pass-by-
   cout << "Enter the end time: ";   //    reference
   cin  >> end;
}

/************************************************************************
 * DISPLAY
 * Display a list of files accessed during a period by users 
 ***********************************************************************/
void display(const Record period[], long start, long end)
{
   // printing properly the results by also using a loop
   cout << endl
        << "The following records match your criteria:\n"
        << endl
        << setw(15) << "Timestamp"
        << setw(20) << "File"
        << setw(20) << "User"
        << endl
        << "--------------- "
        << "------------------- "
        << "-------------------\n";
   for (int i = 0; i < 500; i++)
   {
      if (period[i].timeStamp < end && period[i].timeStamp > start)
      {
         cout << setw(15) << period[i].timeStamp
              << setw(20) << period[i].fileName
              << setw(20) << period[i].userName
              << endl;
      }
   }
   cout << "End of records\n";
}
 

/***********************************************************************
* Program:
*    Assignment 03, Digital Forensics with Corrupt Files
*    Brother Alvey, CS165
* Author:
*    Milton Nogueira Brando Neto
* Summary:  
*    This program scan through a log to identify users who accessed files
*    in a particular window of time parsing the lines and firing corrupted
*    lines too.
*    Estimated:  6.0 hrs   
*    Actual:     6.0 hrs
*      The most difficult part was to parse the lines.   
************************************************************************/

#include <iostream>
#include <fstream>     // used for file reading
#include <sstream>     // used to parse a line
#include <string>
#include <cassert>
#include <iomanip>
using namespace std;


/**********************************************************************
 *  ACESSRECORD
 *  a list of users acess into a specific period of time
 ***********************************************************************/
struct AcessRecord
{
   string userName;
   string fileName;
   long timeStamp;
};

string getText(const char * prompt);
bool   parseFile(string, AcessRecord Records[]);
void   parseLine(string, AcessRecord &Records) throw (string);
void   promptTime(long &start, long &end);
void   display(const AcessRecord Period[], long, long);

/**********************************************************************
 *  MAIN() calls other functions in order to access a file and to display
 *  a list of users into a specific period of time
 ***********************************************************************/
int main()
{
   string fileName;               // declare file name to prompt the user
   AcessRecord Records[500];      // a structure variable to read a file
   AcessRecord Period[500];       // a structure variable to display
   long start;                    // logged time
   long end;                      // logged time
   fileName = getText("Enter the access record file: "); // prompt
   if (!parseFile(fileName, Records))  // reading a file
      return 1;
   promptTime(start, end);        // handling the period of time
   display(Records, start, end);
   
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
 * PARSEFILE
 * Checks for error and parses the file calling PARSELINE
 ***********************************************************************/
bool parseFile(string fileName, AcessRecord Records[])
{
   // must use .c_str() because fstream can't handle strings
   ifstream fin(fileName.c_str());

   // ensure the file opened correctly
   if (fin.fail())                    // checks for any type of error 
   {
      cout << "Unable to open file " 
           << fileName  
           << endl; 
      return false;                   // reports failure to the user
   }

   string line;                       // for storing lines
   int i = 0;
   while (getline(fin, line))
   {
      try
      {
         parseLine(line, Records[i]);
      }
      catch (const string message)
      {
         cout << message << endl;
      }
      i++;
   }
   

   return true;
}

/************************************************************************
 * PARSELINE
 * Reads a line (a string) and populates a struct for the AccessRecord
 ***********************************************************************/
void parseLine(string line, AcessRecord &Records) throw (string)
{
   stringstream ss(line);        // reading the lines
   ss >> Records.fileName;
   ss >> Records.userName;
   ss >> Records.timeStamp;
   if (ss.fail() || Records.timeStamp < 1000000000 ||
       Records.timeStamp > 10000000000)
      throw string("Error parsing line: " + line);
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
void display(const AcessRecord Period[], long start, long end)
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
   // results inside the range     
   for (int i = 0; i < 500; i++)  
   {                          
      if (Period[i].timeStamp < end && Period[i].timeStamp > start)
      {
         cout << setw(15) << Period[i].timeStamp
              << setw(20) << Period[i].fileName
              << setw(20) << Period[i].userName
              << endl;
      }
   }
   cout << "End of records\n";
}
 

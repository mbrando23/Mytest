/***********************************************************************
* Program:
*    Project 07, Calendar
*    Brother Ellsworth, CS124
* Author:
*    Milton Nogueira Brando Neto
* Summary: 
*    Display a calendar on the screen from data that the user inputs 
*    that are: a month number and a year. 
*    Estimated:  4.0 hr   
*    Actual:     4.5 hr
*       The most difficult part was to apply loop for display the 
*       calendar.
***********************************************************************/

#include <iostream>
#include <iomanip> 
using namespace std;

int getMonth();                     // prototype of the function
int getYear();                      // prototype of the function
int computeOffset(int, int);        // prototype of the function
int numDaysInYear(int);             // prototype of the function
int numDaysInMonth(int, int);       // prototype of the function 
bool isLeapYear(int);               // prototype of the function
int display(int, int, int);         // prototype of the function
void displayTable(int, int);        // prototype of the function
void displayHeader(int, int);       // prototype of the function

/***********************************************************************
*  main function gets the parameters in order to call display().
***********************************************************************/
int main()
{
   int month  = getMonth();                 // receives parameter
   int year   = getYear();                  // receives parameter
   int offset = computeOffset(month, year); // receives display parameter
   display (month, year, offset);           // calls the function


   return 0;
}


/***********************************************************************
*  getMonth prompts the user to get the month and to return it to main.
***********************************************************************/
int getMonth()
{
   int month;                         // declares variable
   cout << "Enter a month number: ";  // prompts the user for month
   cin  >> month;                     // initializes variable
   
   // event-controlled loop
   while (month < 1 || month > 12)
   {
      cout << "Month must be between 1 and 12.\n";   // displays error
      cout << "Enter a month number: ";              // prompts again
      cin  >> month;                                 // updates variable
   }
   return month;
}


/***********************************************************************
*  getYear prompts the user to get the year and to return it to main.
***********************************************************************/
int getYear()
{
   int year;                          // declares variable
   cout << "Enter year: ";            // prompts the user for year
   cin  >> year;                      // initializes variable
   
   // event-controlled loop
   while (year < 1753)
   {
      cout << "Year must be 1753 or later.\n";       // displays error
      cout << "Enter year: ";                        // prompts again
      cin  >> year;                                  // updates variable
   }
   return year;
}


/***********************************************************************
*  computeOffset receives month and year as parameters to determine what
*  day of the week on which a given month starts and returns it to main.
***********************************************************************/
int computeOffset(int month, int year)
{
   int numDays = 0;                                // declares initializes
   int yearCount;                                  // declares variable
   int monthCount;                                 // declares variable
   // loop for counting
   for (yearCount = 1753; yearCount < year; yearCount++)
      numDays += numDaysInYear(yearCount);         // send parameter
   // loop for counting
   for (monthCount = 1; monthCount < month; monthCount++)
      numDays += numDaysInMonth(monthCount, year); // send parameter
    
   return numDays % 7;                             // returns to main
}


/***********************************************************************
*  numDaysInYear receives year as parameter and calculates the number of
*  days in a year and returns it to computeOffset. 
***********************************************************************/
int numDaysInYear(int year)
{
   bool isLeap = isLeapYear(year);                 // send parameter
   // use the answer to defines the number of days
   if (isLeap == false)
      return 365;
   else if (isLeap == true)            // returns to computeOffset
      return 366;                     // returns to computeOffset     
}


/***********************************************************************
*  numDaysInMonth receives year and month as parameters and calculates 
*  the number of days in a month and returns it to computeOffset. 
***********************************************************************/
int numDaysInMonth(int month, int year)
{
   bool isLeap = isLeapYear(year);                 // send parameter
   int numDays;
   // computes number of days in a month by logic
   if (isLeap == false && month == 2)
      numDays = 28;
   if (isLeap == true && month == 2)
      numDays = 29;  
   if (month == 1 || month == 3 || month == 5 || month == 7 || month 
           == 8 || month == 10 || month == 12)
      numDays = 31;  
   if (month == 4 || month == 6 || month == 9 || month == 11)
      numDays = 30;  
 
   return numDays;                    // returns to computeOffset
}


/***********************************************************************
*  isLeapYear verifies the leap years by receiving year parameter and 
*  returns it to numDaysInMonth and numDaysInYear. 
***********************************************************************/
bool isLeapYear(int year)
{
   // defines if a year is leap by logic
   if (year % 4 != 0)
      return 0;          // returns to numDaysInMonth and numDaysInYear
   if (year % 100 == 0 && year % 400 != 0)
      return 0;          // returns to numDaysInMonth and numDaysInYear
   if (year % 100 == 0 && year % 400 == 0)
      return 1;          // returns to numDaysInMonth and numDaysInYear
   if (year % 4 == 0 && year % 100 != 0)
      return 1;          // returns to numDaysInMonth and numDaysInYear
}


/***********************************************************************
*  this function displays a calendar on the screen by receiving month, 
*  year and offset as parameters; it calls displayHeader and displayTable. 
***********************************************************************/
int display(int month, int year, int offset)
{
   int numDays = numDaysInMonth(month, year);  // receives parameter  
   displayHeader(month, year);                 // calls the function
   displayTable(numDays, offset);              // calls the function
}


/***********************************************************************
*  this function displays the calendar header by receiving month and
*  year as parameters. 
***********************************************************************/
void displayHeader(int month, int year)
{
   // substitutes the number of month by its name
   if (month == 1)
      cout << "\nJanuary, "   << year << endl;  // displays
   else if (month == 2)
      cout << "\nFebruary, "  << year << endl;  // displays 
   else if (month == 3)
      cout << "\nMarch, "     << year << endl;  // displays  
   else if (month == 4)
      cout << "\nApril, "     << year << endl;  // displays  
   else if (month == 5)
      cout << "\nMay, "       << year << endl;  // displays
   else if (month == 6)
      cout << "\nJune, "      << year << endl;  // displays  
   else if (month == 7)
      cout << "\nJuly, "      << year << endl;  // displays
   else if (month == 8)
      cout << "\nAugust, "    << year << endl;  // displays
   else if (month == 9)
      cout << "\nSeptember, " << year << endl;  // displays
   else if (month == 10)
      cout << "\nOctober, "   << year << endl;  // displays
   else if (month == 11)
      cout << "\nNovember, "  << year << endl;  // displays
   else if (month == 12)
      cout << "\nDecember, "  << year << endl;  // displays
}


/***********************************************************************
*  this function displays calendar on the screen by receiving numDays 
*  and offset as parameters and using loops. 
***********************************************************************/
void displayTable(int numDays, int offset)
{
   // displays table header
   cout << setw(4) << "Su"
        << setw(4) << "Mo"
        << setw(4) << "Tu"
        << setw(4) << "We"
        << setw(4) << "Th"
        << setw(4) << "Fr"
        << setw(4) << "Sa" << endl;
   // make the corrections    
   if (offset == 6)
      offset = -1;
   int dow = -1;
   // use loop for a complex task
   for (int dom = -offset; dom <= numDays; dom++)
   {
      if (dom > 0)
         cout << setw(4) << dom;
      else
         cout << "    ";
      dow++;
      if (dow % 7 == 6)
         cout << "\n";
   } 
   if (dow % 7 != 6)
      cout << "\n";   
   
}



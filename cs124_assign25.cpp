/***********************************************************************
* Program:
*    Assignment 25, LOOP DESIGN
*    Brother Ellsworth, CS124
* Author:
*    Milton Nogueira Brando Neto
* Summary: 
*    Display a calendar on the screen from user who inputs the number of  
*    days in a month and the offset. 
*    Estimated:  1.0 hr   
*    Actual:     2.5 hr
*       The most difficult part was to apply loop for display the 
*       calendar.
***********************************************************************/

#include <iostream>
#include <iomanip> 
using namespace std;

/***********************************************************************
*  This function displays a calendar on the screen by using loops. 
***********************************************************************/
void displayTable(int numDays, int offset)
{
   cout << setw(4) << "Su"
        << setw(4) << "Mo"
        << setw(4) << "Tu"
        << setw(4) << "We"
        << setw(4) << "Th"
        << setw(4) << "Fr"
        << setw(4) << "Sa" << endl;


             
   if (offset == 6)
      offset = -1;
   int dow = -1;
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

/***********************************************************************
*  Prompt the user to get the parameters for displayTable().
***********************************************************************/
int main()
{
   int numDays;
   int offset;                    // declare variables
   cout << "Number of days: ";    // prompt the user for numDays
   cin  >> numDays;
   cout << "Offset: ";            // prompt the user for offset
   cin  >> offset;
   displayTable(numDays, offset); // call the function

   return 0;
}



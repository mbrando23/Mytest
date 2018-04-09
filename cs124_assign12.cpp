/***********************************************************************
* Program:
*    Assignment 12, INPUT & VARIABLES
*    Brother Ellsworth, CS124
* Author:
*    Milton Nogueira Brando Neto
* Summary: 
*    Write a program that prompts the user's income and displays
*    the result on the screen.
*    Estimated:  0.8 hr   
*    Actual:     1.0 hr
*       I had not remember to include iomanip library most of time.
***********************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * Just one function for input income and display it on screen.
 ***********************************************************************/
int main()
{
   // declare the variable
   float income;
   
   // prompt for income
   cout << "\tYour monthly income: ";
   cin  >> income;
   
   // configure the display to show money
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   
   // display the results
   cout << "Your income is: $"
        << setw(9) << income << endl;
   
   return 0;
}


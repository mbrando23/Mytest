/***********************************************************************
* Program:
*    Assignment 16, IF Statements
*    Brother Ellsworth, CS124
* Author:
*    Milton Nogueira Brando Neto
* Summary:
*    The function returns the percentage bracket that the user's income
*    falls in by asking his or her income.
*    Estimated:  1.0 hr
*    Actual:     1.5 hr
*       The most difficult part was to get out of some pitfalls.
***********************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/***********************************************************************
 *  Determine which tax bracket the user is in.
 ***********************************************************************/
int computeTax(double income)
{
   // declare a local variable
   int tax;
   
   // if statement
   if (income > 0 && income < 15100)
      tax = 10;
   else if (income >= 15100 && income < 61300)
      tax = 15;
   else if (income >= 61300  && income < 123700)
      tax = 25;
   else if (income >= 123700 && income < 188450)
      tax = 28;
   else if (income >= 188450 && income < 336550)
      tax = 33;
   else if (income >= 336550)
      tax = 35;

   return tax;
}


/***********************************************************************
 *  Prompt the user and call the function for a result.
 ***********************************************************************/
int main()
{
   // declare variable
   double income;

   // prompt the user for income
   cout << "Income: ";
   cin >> income;

   // receive the return from function and display it
   cout << "Your tax bracket is "
        << computeTax(income)
        << "%\n";
   
   return 0;
}

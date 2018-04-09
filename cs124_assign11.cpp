/***********************************************************************
* Program:
*    Assignment 11, Monthly Budget
*    Brother Ellsworth, CS124
* Author:
*    Milton Nogueira Brando Neto
* Summary: 
*    Demonstrate how to align multiple columns of text and numbers to
*    output a budget on the screen.
*    Estimated:  1.0 hr   
*    Actual:     1.5 hr
*       The most difficult part was to understand the command setw(). 
***********************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/***********************************************************************
*  Write a program to output a monthly budget:
***********************************************************************/
int main()
{
   // format the output for money
   cout.setf(ios::fixed);     // no scientific notation
   cout.setf(ios::showpoint); // always show the decimal point
   cout.precision(2);         // unless you own a gas station, money
                              //    is formatted to two decimals
   
   // display the first row
   cout << "\tItem           "
        << "Projected\n";
   
   // display the second row
   cout << "\t=============  "
        << "=========="      
        << endl;

   // display the third row
   cout << "\tIncome         "
        << "$"
        << setw(9) << 1000.00
        << endl;

   // display the fourth row
   cout << "\tTaxes          "
        << "$"
        << setw(9) << 100.00
        << endl;

   // display the fifth row
   cout << "\tTithing        "
        << "$"
        << setw(9) << 100.00
        << endl;

   // display the sixth row
   cout << "\tLiving         "
        << "$"
        << setw(9) << 650.00
        << endl;

   // display the seventh row
   cout << "\tOther          "
        << "$"
        << setw(9) << 90.00
        << endl;

   // display the eighth row
   cout << "\t=============  "
        << "=========="      
        << endl;

   // display the ninth row
   cout << "\tDelta          "
        << "$"
        << setw(9) << 60.00
        << endl;


   return 0;
}


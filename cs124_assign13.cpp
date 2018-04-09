/***********************************************************************
* Program:
*    Assignment 13, Expressions
*    Brother Ellsworth, CS124
* Author:
*    Milton Nogueira Brando Neto
* Summary: 
*    This program will prompt the user for the Fahrenheit number
*    and convert it to Celsius.
*    Estimated:  0.7 hr   
*    Actual:     1.0 hr
*       The most difficult part was to format the output.
***********************************************************************/

#include <iostream>
using namespace std;

/***********************************************************************
*  Write a program to compute the Celsius value, and display the results.
***********************************************************************/
int main()
{
   // declare the f variable
   float f;
   
   // display the prompt
   cout << "Please enter Fahrenheit degrees: ";
   cin >> f;

   // declare the c variable
   float c = 5.0 / 9 * (f - 32);
   
   // format the output for temperature numbers
   cout.setf(ios::fixed);     // no scientific notation
   cout.precision(0);         // precision required                              

   // display the output
   cout << "Celsius: "  << c << endl;
     
   return 0;
}


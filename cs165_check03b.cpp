/***********************************************************************
* Program:
*    Checkpoint 03b, Errors
*    Brother Alvey, CS165
* Author:
*    Milton Nogueira Brando Neto
* Summary: 
*    
************************************************************************/

#include <iostream>
#include <cctype>
#include <string>
using namespace std;

// TODO: Add your prompt function here
void prompt(int & number) 
{
   do
   {   
      cout << "Enter a number: ";
      cin  >> number;
      if (cin.fail())
      {
         cin.clear();
         cin.ignore(256, '\n');
	 cout << "Invalid input.\n";
      }
   }
   while (number == 0);
   
}


/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   // Declare an integer
   int number;
   
   prompt(number);
   cout << "The number is "
        << number
        << "."
        << endl;
   
   return 0;
}



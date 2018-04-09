/***********************************************************************
* Program:
*    Checkpoint 03a, Exceptions
*    Brother Alvey, CS165
* Author:
*    Milton Nogueira Brando Neto
* Summary: 
*    
************************************************************************/

#include <iostream>
#include <string>
using namespace std;

// TODO: Add your prompt function here
void prompt(int & number) throw (string)
{

   cout << "Enter a number: ";
   cin  >> number;
   if (number < 0)
      throw string("Error: The number cannot be negative.");
   if (number > 100)
      throw string("Error: The number cannot be greater than 100.");
   if (number % 2 != 0)
      throw string("Error: The number cannot be odd.");
}


/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   // Declare an integer
   int number;
   
   try
   {
      prompt(number);
      cout << "The number is "
           << number
           << "."
           << endl;
   }
   catch (const string message)
   {
      cout << message << endl;
   }
   
   return 0;
}



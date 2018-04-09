/***********************************************************************
* Program:
*    Checkpoint 01b, C++ BASICS
*    Brother Alvey, CS165
* Author:
*    Milton Nogueira Brando Neto
* Summary: 
*    
* ***********************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   int size;
   do
   {                 
      cout << "Enter the size of the list: ";
      cin  >> size;
   }
   while (size <= 0);

   // allocate the memory
   int * numbers = new int [size];
   for (int i = 0; i < size; i++)
   {
      cout << "Enter number for index "
	   << i
	   << ": ";
      cin  >> numbers[i];
   }   

   // computes the numbers divisible by 3
   cout << endl
	<< "The following are divisible by 3:"
	<< endl;
   
   for (int i = 0; i < size; i++)
   {
      if (numbers[i] % 3 == 0)
      {
         cout << numbers[i]
	      << endl;
      }
   }
   
   return 0;
}

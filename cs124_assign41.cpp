/***********************************************************************
* Program:
*    Assignment 41, ALLOCATING MEMORY
*    Brother Ellsworth, CS124
* Author:
*    Milton Nogueira Brando Neto
* Summary: 
*    This program allocates sufficient memory to display a string back
*    to the user.
*    Estimated:  0.7 hr   
*    Actual:     0.7 hr
*       The most difficult part was to treat allocation failures.
***********************************************************************/

#include <iostream>
using namespace std;

/***********************************************************************
*  This function prompts the user for a number of characters in a string
*  and for a string and display the string back to the user.
***********************************************************************/
int main()
{
   // get the size of the text
   int size;                                   // memory size 
      cout << "Number of characters: ";
      cin >> size;                             // continue prompting until the
      
   // allocate the memory
   char * text = new(nothrow) char [size + 1]; // allocate one more for \0
   cin.ignore();

   if (text == NULL)                           // failure comes in the form of a
      cout << "Allocation failure!\n";         // NULL pointer
   else
   {
      cout << "Enter Text: ";                  // prompt for the text
      cin.getline(text, size + 1);             // treat “text” like a string
      cout << "Text: "
           << text
           << endl;
   }


/*   if (!text)                                  // same as “if (text != NULL)”
      cout << "Allocation failure!\n";         // should return because we will
*/                                               // crash in a minute…

   delete text;
   text = NULL;
   
   return 0;
}




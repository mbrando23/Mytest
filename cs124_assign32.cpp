/***********************************************************************
* Program:
*    Assignment 32, Strings
*    Brother Ellsworth, CS124
* Author:
*    Milton Nogueira Brando Neto
* Summary: 
*    This program prompts the user for a letter, then prompts for a
*    string. It calculates the number of that letter in that string.
*    Estimated:  0.7 hr   
*    Actual:     1.0 hr
*       The most difficult part was to 
***********************************************************************/

#include <iostream>
using namespace std;

/***********************************************************************
*  This function countLetters() returns the number of letters in a
*  string.
***********************************************************************/
int countLetters(char text[], char letter) 
{
   int count = 0;
   for (int i = 0; text[i]; i++)
      if (text[i] == letter)
         count++;
            
   return count;
}


/***********************************************************************
*  This function  prompts the user for a line of input (using getline),
*  calls countLetters(), and displays the number of letters.
***********************************************************************/
int main()
{
   char letter;
   char text[256];
   cout << "Enter a letter: ";
   cin  >> letter;
   cout << "Enter text: ";
   cin.ignore();
   cin.getline(text, 256);
   cout << "Number of '"
        << letter
        << "'s: "
        << countLetters(text, letter)
        << endl;
   
   return 0;
}




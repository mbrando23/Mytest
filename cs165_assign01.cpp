/***********************************************************************
* Program:
*    Assignment 01, Genetic Genealogy
*    Brother Alvey, CS165
* Author:
*    Milton Nogueira Brando Neto
* Summary: 
*    This program compares user DNA with his or her relatives in order
*    to take a percentage match.
*    Estimated:  4.0 hrs   
*    Actual:     5.0 hrs
*      The most difficult part was to compute percentage.
************************************************************************/

#include <iostream>
using namespace std;

void getUserDNA(char userDNA[]);
int getNumberRel();
void getNames(char names[][50], int);
void getRelDNA(char names[][50], char othersDNA[][50], int);
void displayResults(char names[][50], int results[], int);

/**********************************************************************
 *  main() calls other functions in order to compute percentage that the
 *  user has in comparison with his or her relatives   
 ***********************************************************************/
int main()
{
   char userDNA[10];
   char othersDNA[10][50];
   char names[256][50];
   int results[50] = {};
   
   getUserDNA(userDNA);
   int relatives = getNumberRel();
   getNames(names, relatives);
   getRelDNA(names, othersDNA, relatives);

   // computes the percentage that matches in comparison with relatives 
   for (int j = 0; j < relatives; j++)
   {
      for (int i = 0; i < 10; i++)
      {
         if (userDNA[i] == othersDNA[j][i])
            results[j] += 10;
      }   
          
   }
   
   displayResults(names, results, relatives);

   return 0;
}

/**********************************************************************
 *  getUserDNA() gets the user DNA marker sequence
 ***********************************************************************/
void getUserDNA(char userDNA[])
{ 
   // Prompts the user for a 10 character DNA marker sequence
   cout << "Enter your DNA sequence: ";
   cin  >> userDNA;
}

/**********************************************************************
 *  getNumberRel() returns how many relatives we will compare
 ***********************************************************************/
int getNumberRel()
{
   int relatives;
   // Prompts the user for a number of potential relatives
   cout << "Enter the number of potential relatives: ";
   cin  >> relatives;
   cout << endl;
   return relatives;
}

/**********************************************************************
 *  getNames() gets relatives names
 ***********************************************************************/
void getNames(char names[][50], int relatives)
{
   // Prompt for the names of each of these potential relatives
   for (int i = 0; i < relatives; i++)
   {   
      cout << "Please enter the name of relative #"
           << i + 1
           << ": ";
      cin  >> names[i];
   }
   cout << endl;
}

/**********************************************************************
 *  getRelDNA() gets relatives DNA sequence for comparison in main()
 ***********************************************************************/
void getRelDNA(char names[][50], char othersDNA[][50], int relatives)
{
   for (int i = 0; i < relatives; i++)
   {
      // Prompt for the 10 character DNA marker sequence of each of the
      //    potential relatives
      cout << "Please enter the DNA sequence for "
           << names[i]
           << ": ";
      cin  >> othersDNA[i];
   }
   cout << endl;
}

/**********************************************************************
 *  displayResults() displays the percentage of user DNA that matches
 *  with the relatives
 ***********************************************************************/
void displayResults(char names[][50], int results[], int relatives)
{
   for (int i = 0; i < relatives; i++)
   {
      // Display each potential relative along with the percentage that
      //    their sequence matched the target user
      cout << "Percent match for "
           << names[i]
           << ": "
           << results[i]
           << "%"
           << endl;
   }
}

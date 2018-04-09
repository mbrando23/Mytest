/***********************************************************************
* Program:
*    Assignment 31, Array Design
*    Brother Ellsworth, CS124
* Author:
*    Milton Nogueira Brando Neto
* Summary: 
*    This program prompt the user for 10 grades and display the average. 
*    Estimated:  0.7 hr   
*    Actual:     1.0 hr
*       The most difficult part was to pass test 3 of testbed. 
***********************************************************************/

#include <iostream>
#define NUMBERS_Q 10
using namespace std;

/***********************************************************************
*  This function getGrades() prompts the user for 10 (ten) grades. 
***********************************************************************/
void getGrades (int listGrades[], int numGrades) 
{
   for (int i = 0; i < numGrades; i++)      
   {
      cout << "Grade " << i + 1 << ": ";
      cin >> listGrades[i];
   }
}

/***********************************************************************
*  This function averageGrades()  returns the average score of the ten 
*  grades.
***********************************************************************/
int averageGrades (const int grades[], int num)
{
   int average = 0;
   int sum = 0;
   for (int i = 0; i < num; i++)
      if (grades[i] != -1)
      {
         average++;
         sum += grades[i];  
      }
   if (sum == 0)
      return 0;
   return sum / average;
   
}

/***********************************************************************
*  This function calls others and send array parameters. Then display
*  results.
***********************************************************************/
int main()
{
   int listGrades[NUMBERS_Q];
   getGrades(listGrades, NUMBERS_Q);
   if (averageGrades (listGrades, NUMBERS_Q) == 0)
      cout << "Average Grade: ---%\n";
   else
      cout << "Average Grade: "
           << averageGrades (listGrades, NUMBERS_Q)
           << "%\n";
   return 0;
}




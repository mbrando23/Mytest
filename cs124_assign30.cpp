/***********************************************************************
* Program:
*    Assignment 30, Array Syntax
*    Brother Ellsworth, CS124
* Author:
*    Milton Nogueira Brando Neto
* Summary: 
*    This program prompt the user for 10 grades and display the average. 
*    Estimated:  0.7 hr   
*    Actual:     1.0 hr
*       The most difficult part was setting arrays. 
***********************************************************************/

#include <iostream>
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
   int sum = 0;
   for (int i = 0; i < num; i++)
      sum += grades[i];

   return sum / num;
   
}

/***********************************************************************
*  This function calls others and send array parameters. Then display
*  results.
***********************************************************************/
int main()
{
   int listGrades[10];
   getGrades(listGrades, 10);
   cout << "Average Grade: "
        << averageGrades (listGrades, 10)
        << "%\n";
   return 0;
}




/***********************************************************************
* Program:
*    Assignment 23, Loop Syntax
*    Brother Ellsworth, CS124
* Author:
*    Milton Nogueira Brando Neto
* Summary:
*    This program helps Sue's brother to know the multiples' sum until
*    100 of any number.
*    Estimated:  0.7 hr
*    Actual:     2.0 hr
*       The most difficult part was to decide which is the best type of
*       loop syntax to use.
***********************************************************************/

#include <iostream>
using namespace std;

/***********************************************************************
*  Write a program to compute the sum of a multiple of a number until
*  100. We prompt the user for a multiple number and display the result.
***********************************************************************/
int countForMultiple(int value)
{

/* int num = 100 / multiple;

   int sum = ((multiple + 100) / 2 ) * num;
*/
  int multiple = 0;
  int sum      = 0;
  do
  {
  	sum      += multiple;
	multiple += value;		
  }
  while (multiple < 100);
  
  return sum;
}
  
int main()
{

   cout << "What multiples are we adding? ";
   int multiple;
   cin >> multiple;
   
   int sum = countForMultiple(multiple);
   
   cout << "The sum of multiples of "
           << multiple
           << " less than 100 are: "
           << sum
           << endl;
   return 0;	
}
  






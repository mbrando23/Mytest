/***********************************************************************
* Program:
*    Assignment 33, Pointers
*    Brother Ellsworth, CS124
* Author:
*    Milton Nogueira Brando Neto
* Summary: 
*    This program prompts two people for their account balance. All
*    subsequent purchases will be charged to the largest balance
*    account.
*    Estimated:  0.7 hr   
*    Actual:     1.0 hr
*       The most difficult part was to understand pass by pointer.
***********************************************************************/

#include <iostream>
using namespace std;

/***********************************************************************
*  This function reduce the value of the debit card according to the
*  cost of the date by prompting the user for the cost of the date.
***********************************************************************/
void date(float *pAccount)
{
   // prompt the user for costs occurred on date
   float priceDinner;
   cout << "Cost of the date:\n";

   // prompt the user for detailed costs
   float cost1;
   cout << "\tDinner:    ";
   cin  >> cost1; 
   priceDinner += cost1;

   float cost2;
   cout << "\tMovie:     ";
   cin  >> cost2; 
   priceDinner += cost2;

   float cost3;
   cout << "\tIce cream: ";
   cin  >> cost3; 
   priceDinner += cost3;
   
   // use the debit card to pay
   *pAccount -= priceDinner; 
   
}


/***********************************************************************
*  This function  prompts the user for two accounts ballances and display
*  the results.
***********************************************************************/
int main()
{
   // prompt for how much sam and sue have in their accounts
   cout << "What is Sam's balance? "; 
   float accountSam;                    // original account of Sam
   cin  >> accountSam;
   cout << "What is Sue's balance? "; 
   float accountSue;                    // original account of Sam
   cin  >> accountSue;
   
   float * pAccount;                    // uninitialized pointer
   // who will pay...
   if (accountSam > accountSue)   
      pAccount = &accountSam;     
   else                           
      pAccount = &accountSue;

   date(pAccount);
      
   // report
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   cout << "Sam's balance: $"
        << accountSam << endl;    
   cout << "Sue's balance: $"
        << accountSue << endl;    
   return 0;
}




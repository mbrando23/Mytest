/***********************************************************************
* Program:
*    Assignment 15, Full Tithe Payer
*    Brother Ellsworth, CS124
* Author:
*    Milton Nogueira Brando Neto
* Summary: 
*    This program will compute if a user is a full tithe payer using
*    the complicated formula provided in the scriptures:
*        And after that, those who have thus been tithed shall 
*        pay one-tenth of all their interest annually; and this 
*        shall be a standard law unto them forever, for my holy 
*        priesthood, saith the Lord.  D&C 119:4
*
*    Estimated:  0.7 hrs   
*    Actual:     0.5 hrs
*      The most difficult part was to make the right return to main.
************************************************************************/

#include <iostream>
using namespace std;

/*****************************************************
 * Use the bool function to direct the right return
 *****************************************************/
bool isFullTithePayer(float income, float tithe)
{
   // treat the variables
   tithe *= 10;
   // make it return true if the user is a full tithe payer and
   //    false if he needs to repent.
   return (income <= tithe);
}


/**********************************************************************
 * Main will call isFullTithePayer() and display an appropriate message
 * to the user based on the results
 ***********************************************************************/
int main()
{
   float income;
   float tithe;

   // prompt user for income
   cout << "Income: ";
   cin  >> income;

   // prompt user for tithe
   cout << "Tithe: ";
   cin  >> tithe;

   // give the user his tithing report
   if (isFullTithePayer(income, tithe))
      cout << "You are a full tithe payer.\n";
   else
      cout << "Will a man rob God?  Yet ye have robbed me.\n"
           << "But ye say, Wherein have we robbed thee?\n"
           << "In tithes and offerings.  Malachi 3:8\n";

   return 0;
}

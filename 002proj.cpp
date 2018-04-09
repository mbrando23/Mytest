/***********************************************************************
* Program:
*    Project 02, Monthly Budget 
*    Brother Ellsworth, CS124
* Author:
*    Milton Nogueira Brando Neto
* Summary: 
*    A program to manage personal finance for a month. Asking for budget
*    income, expenditures and actually spent, display a final report. 
*    Estimated:  2.0 hr   
*    Actual:     2.5 hr
*       The most difficult part was to align the table output.
***********************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/***********************************************************************
*  Prompt the user for input and display the budget back on the screen.
***********************************************************************/
int main()
{
   // declare variables
   double monthlyIncome;
   double budgetLiving;
   double actualLiving;
   double actualTaxes;
   double actualTithe;
   double actualOther;
   
   // initiate explanation
   cout << "This program keeps track of your monthly budget\n"
        << "Please enter the following:\n";
   
   // prompt for monthly income and store the variable
   cout << "\tYour monthly income: ";
   cin >> monthlyIncome;
      
   // prompt for budget living expenses and store the variable
   cout << "\tYour budgeted living expenses: ";
   cin >> budgetLiving;
      
   // prompt for actual living expenses and store the variable
   cout << "\tYour actual living expenses: ";
   cin >> actualLiving;

   // prompt for actual taxes withheld and store the variable
   cout << "\tYour actual taxes withheld: ";
   cin >> actualTaxes;

   // prompt for actual tithe offerings and store the variable
   cout << "\tYour actual tithe offerings: ";
   cin >> actualTithe;

   // prompt for actual other expenses and store the variable
   cout << "\tYour actual other expenses: ";
   cin >> actualOther;   

   // format the output for money
   cout.setf(ios::fixed);     // no scientific notation
   cout.setf(ios::showpoint); // always show the decimal point
   cout.precision(2);         // unless you own a gas station, money
                              //    is formatted to two decimals
   // second explanation
   cout << "\nThe following is a report on your monthly expenses";
   
   // display the first row
   cout << "\n\tItem            "
        << setw(12) << "Budget"
        << setw(16) << "Actual"
        << endl;
   
   // display the second row  
   cout << "\t=============== "
        << "=============== "      
        << "==============="
        << endl;

   // display the third row
   cout << "\tIncome          $"
        << setw(11) << monthlyIncome
        << "    $"
        << setw(11) << monthlyIncome
        << endl;

   // display the fourth row
   cout << "\tTaxes           $"
        << setw(11) << 0.00
        << "    $"
        << setw(11) << actualTaxes        
        << endl;

   // display the fifth row
   cout << "\tTithing         $"
        << setw(11) << 0.00
        << "    $"
        << setw(11) << actualTithe
        << endl;

   // display the sixth row
   cout << "\tLiving          $"
        << setw(11) << budgetLiving
        << "    $"
        << setw(11) << actualLiving
        << endl;

   // display the seventh row
   cout << "\tOther           $"
        << setw(11) << 0.00
        << "    $"
        << setw(11) << actualOther
        << endl;

   // display the eighth row
   cout << "\t=============== "
        << "=============== "      
        << "==============="
        << endl;

   // display the ninth row
   cout << "\tDifference      $"
        << setw(11) << 0.00
        << "    $"
        << setw(11) << 0.00
        << endl;
        

   return 0;
}


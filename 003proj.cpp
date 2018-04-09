/***********************************************************************
* Program:
*    Project 03, Monthly Budget 
*    Brother Ellsworth, CS124
* Author:
*    Milton Nogueira Brando Neto
* Summary: 
*    A program to manage personal finance for a month. Asking for budget
*    income, expenditures and actually spent, display a final report. 
*    Estimated:  2.0 hr   
*    Actual:     2.5 hr
*       The most difficult part was to work with parameters. 
***********************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/***********************************************************************
*  Declare functions.
***********************************************************************/
double getIncome();
double getBudgetLiving();
double getActualLiving();
double getActualTaxes();
double getActualTithe();
double getActualOther();
double computeTithing(double income);

/***********************************************************************
*  Call the functions, hold the values the user has input and display.
***********************************************************************/
int main()
{
   // initiate explanation
   cout << "This program keeps track of your monthly budget\n"
        << "Please enter the following:\n";

   // declare variables
   double monthlyIncome = getIncome();
   double budgetLiving = getBudgetLiving();
   double actualLiving = getActualLiving();
   double actualTaxes = getActualTaxes();
   double actualTithe = getActualTithe();
   double actualOther = getActualOther();
   double budgetTithing = computeTithing(monthlyIncome);
   double budgetOther = monthlyIncome - budgetTithing - budgetLiving;
   double actualDifference = monthlyIncome - actualTaxes - actualTithe -
      actualLiving - actualOther;
   double budgetDifference = 0;
   
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
        << setw(11) << budgetTithing
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
        << setw(11) << budgetOther
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
        << setw(11) << budgetDifference
        << "    $"
        << setw(11) << actualDifference
        << endl;

   return 0;
}

/***********************************************************************
*  Prompt the user for input budget.
***********************************************************************/
double getIncome()
{
   // declare variable
   double monthlyIncome;
   
   // store the variable for return
   cout << "\tYour monthly income: ";
   cin >> monthlyIncome;
   return monthlyIncome;
}

/***********************************************************************
*  Prompt the user for budget living expenses.
***********************************************************************/
double getBudgetLiving()
{
   // declare variable
   double budgetLiving;
   
   // store the variable for return
   cout << "\tYour budgeted living expenses: ";
   cin >> budgetLiving;
   return budgetLiving;
}

/***********************************************************************
*  Prompt the user for actual living expenses.
***********************************************************************/
double getActualLiving()
{
   // declare variable
   double actualLiving;
   
   // store the variable for return
   cout << "\tYour actual living expenses: ";
   cin >> actualLiving;
   return actualLiving;
}
 
/***********************************************************************
*  Prompt the user for actual taxes withheld.
***********************************************************************/
double getActualTaxes()
{
   // declare variable
   double actualTaxes;
   
   // store the variable for return
   cout << "\tYour actual taxes withheld: ";
   cin >> actualTaxes;
   return actualTaxes;
}
       
/***********************************************************************
*  Prompt the user for actual tithing.
***********************************************************************/
double getActualTithe()
{
   // declare variable
   double actualTithe;
   
   // store the variable for return
   cout << "\tYour actual tithe offerings: ";
   cin >> actualTithe;
   return actualTithe;
}

/***********************************************************************
*  Prompt the user for actual other expenses.
***********************************************************************/
double getActualOther()
{
   // declare variable
   double actualOther;
   
   // prompt for actual other expenses and store the variable
   cout << "\tYour actual other expenses: ";
   cin >> actualOther;   
   return actualOther;
}

/***********************************************************************
*  Determine the amount required to be a full tithe payer.
***********************************************************************/
double computeTithing(double income)
{
   // declare variable;
   double tithing;
   
   // calculate the tithing
   tithing = income / 10;
   
   return tithing;
}

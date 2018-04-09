/***********************************************************************
* Program:
*    Project 04, Monthly Budget 
*    Brother Ellsworth, CS124
* Author:
*    Milton Nogueira Brando Neto
* Summary: 
*    A program to manage personal finance for a month. Asking for budget
*    income, expenditures and actually spent, display a final report. 
*    Estimated:  2.0 hr   
*    Actual:     2.0 hr
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
double computeTax(double income);

/***********************************************************************
*  Call the functions, hold the values the user has input and display.
***********************************************************************/
int main()
{
   // initiate explanation
   cout << "This program keeps track of your monthly budget\n"
        << "Please enter the following:\n";

   // declare variables
   double monthlyIncome    = getIncome();
   double monthlyTax       = computeTax(monthlyIncome);
   double budgetLiving     = getBudgetLiving();
   double actualLiving     = getActualLiving();
   double actualTaxes      = getActualTaxes();
   double actualTithe      = getActualTithe();
   double actualOther      = getActualOther();
   double budgetTithing    = computeTithing(monthlyIncome);
   double budgetOther      = monthlyIncome - budgetTithing - budgetLiving -
                             monthlyTax;
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
        << setw(11) << monthlyTax
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
*  This function 'getIncome()' prompts the user for budget, do not receive
*  any parameters and returns to main the user's input.
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
*  This function 'getBudgetLiving()' prompts the user for budget living
*  expenses, do not receive any parameters and returns to main the user's
*  input.
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
*  This function 'getActualLiving()' prompts the user for actual living
*  expenses, do not receive any parameters and returns to main the user's
*  input.
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
*  This function 'getActualTaxes() prompts the user for actual taxes
*  withheld, do not receive any parameters and returns to main the user's
*  input.
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
*  This function 'getActualTithe() prompts the user for actual tithing,
*  do not receive any parameters and returns to main the user's input.
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
*  This function 'getActualOther() prompts the user for actual other
*  expenses, do not receive any parameters and returns to main the user's
*  input.
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
*  This function 'computeTithing(income)' determines the amount required
*  to be a full tithe payer, stands as parameter's value the result
*  got from the 'getIncome()' function. It returns the amount of tithing
*  the user needs in order to fulfill Lord's law as found in D&C.
***********************************************************************/
double computeTithing(double income)
{
   // declare variable;
   double tithing;
   
   // calculate the tithing
   tithing = income / 10;
   return tithing;
}

/***********************************************************************
*  This function 'computeTax(income)' computes the tax burden the user
*  must pay to American Government. As parameters gets the result came
*  from the 'getIncome()' function. It returns the amount of tax the
*  user needs to obey man's law.
***********************************************************************/
double computeTax(double income)
{
   // declare variable
   double yearlyIncome = income * 12;
   double yearlyTax;
   
   // determine the tax bracket of the income
   if (yearlyIncome > 0 && yearlyIncome < 15100)
      yearlyTax = yearlyIncome * 0.10;
   else if (yearlyIncome >= 15100 && yearlyIncome < 61300)
      yearlyTax = 1510 + (0.15 * (yearlyIncome - 15100));
   else if (yearlyIncome >= 61300  && yearlyIncome < 123700)
      yearlyTax = 8440 + (0.25 * (yearlyIncome - 61300));
   else if (yearlyIncome >= 123700 && yearlyIncome < 188450)
      yearlyTax = 24040 + (0.28 * (yearlyIncome - 123700));
   else if (yearlyIncome >= 188450 && yearlyIncome < 336550)
      yearlyTax = 42170 + (0.33 * (yearlyIncome - 188450));
   else if (yearlyIncome >= 336550)
      yearlyTax = 91043 + (0.35 * (yearlyIncome - 336550));

   // declare variable
   double monthlyTax = yearlyTax / 12;

   return monthlyTax;
}

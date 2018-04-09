/***********************************************************************
* Program:
*    Assignment 21, Debugging
*    Brother Ellsworth, CS124
* Author:
*    Milton Nogueira Brando Neto
* Summary: 
*    Write a program to stub out every function represented how much money
*    Sue is spending on her car.
*    Estimated:  0.7 hr   
*    Actual:     0.7 hr
*       The most difficult part was to declare all functions and variables
*       properly.
***********************************************************************/
#include <iostream>
using namespace std;

int promptDevalue()
{
   return 0;
}

int promptInsurance()
{
   return 0;
}

int promptParking()
{
   return 0;
}

int getPeriodicCost(int cost1, int cost2, int cost3)
{
   return 0;
}

int promptMileage()
{
   return 0;
}

int promptGas()
{
   return 0;
}

int promptRepairs()
{
   return 0;
}

int promptTires()
{
   return 0;
}


int getUsageCost(int mileage, int cost1, int cost2, int cost3)
{
   return 0;
}

void display(int costP, int costU)
{
   return;
}

int main()
{
   int costP1       =  promptDevalue();
   int costP2       =  promptInsurance();
   int costP3       =  promptParking();
   int costPeriodic =  getPeriodicCost(costP1, costP2, costP3);
   int costM1       =  promptMileage();
   int costU1       =  promptGas();
   int costU2       =  promptRepairs();
   int costU3       =  promptTires();
   int costUsage    = getUsageCost(costM1, costU1, costU2, costU3);

   display(costPeriodic, costUsage);
   
   cout << "Success\n";
   
   return 0;
}


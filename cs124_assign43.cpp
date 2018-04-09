/***********************************************************************
* Program:
*    Assignment 43, COMMAND LINE
*    Brother Ellsworth, CS124
* Author:
*    Milton Nogueira Brando Neto
* Summary: 
*    This program convert feet to meters into parameters input.
*    Estimated:  0.7 hr   
*    Actual:     0.7 hr
*       The most difficult part was to use atof().
***********************************************************************/

#include <iostream>
#include <cstdlib>
using namespace std;

/***********************************************************************
*  This function 
***********************************************************************/
int main(int argc, char ** argv)
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(1);
   for (int iArg = 1; iArg < argc; iArg++) // standard command line loop
   {   
      float meters;
      float foot;
      meters = atof(argv[iArg]);
      foot = atof(argv[iArg]);
      cout << foot
           << " feet is "
           << meters*0.3048
           << " meters"
           << endl;
   }
   return 0;
}




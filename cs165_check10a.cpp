/***********************************************************************
* Program:
*    Checkpoint 10a, Vectors
*    Brother Alvey, CS165
* Author:
*    Milton Nogueira Brando Neto
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
************************************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;



/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   vector <int> num;
   int number;
   do
   {
      cout << "Enter int: ";
      cin  >> number;
      num.push_back(number);
   }
   while (number != 0);
   
   cout << "Your list is:"
        << endl;

   for (int i = 0; i < num.size(); i++) 
   {
      if (num[i] != 0)
      {
         cout << num[i]
              << endl;
      }
   }

   cout << endl;    
   vector <string> name;
   string trin;
   do
   {
      cout << "Enter string: ";
      cin  >> trin;
      name.push_back(trin);
   }
   while (trin != "quit");

   cout << "Your list is:"
        << endl;

   for (int i = 0; i < name.size(); i++) 
   {
      if (name[i] != "quit")
      {
         cout << name[i]
              << endl;
      }
   }
   
   

   return 0;
}



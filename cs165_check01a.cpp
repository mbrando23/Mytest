/***********************************************************************
* Program:
*    Checkpoint 01a, C++ BASICS
*    Brother Alvey, CS165
* Author:
*    Milton Nogueira Brando Neto
* Summary: 
*    
* ***********************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   string name;
   int age;
   cout << "Hello CS 165 World!"
        << endl;
   cout << "Please enter your first name: ";
   cin  >> name;
   cout << "Please enter your age: ";
   cin  >> age;
   cout << endl
        << "Hello "
        << name
        << ", you are "
        << age
        << " years old."
        << endl;
   
   return 0;
}

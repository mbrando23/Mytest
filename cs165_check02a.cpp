/***********************************************************************
* Program:
*    Checkpoint 02a, Structs
*    Brother Alvey, CS165
* Author:
*    Milton Nogueira Brando Neto
* Summary: 
*    
* ***********************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

/***********************************
 * STUDENT
 * The position on the globe
 **********************************/
struct Student
{
   string firstName;  // corresponds to the structure 
   string lastName;   
   int id;            // note member variables can be of different data-types
};                    // do not forget the semi-colon!
   

// prompt information
void prompt(Student & user);

// display information
void display(const Student & user);

/**********************************************************************
 * This will be just a simple driver program
 ***********************************************************************/
int main()
{
   // First we will declare
   Student user;

   // Next we will fill it with the prompt function
   prompt(user);

   // display information
   display(user);
   
   return 0;
}

/**********************************************************************
 * Function: prompt
 * Purpose: Ask the user for information
 ***********************************************************************/
void prompt(Student & user)
{
   cout << "Please enter your first name: ";
   cin  >> user.firstName;
   cout << "Please enter your last name: ";
   cin  >> user.lastName;
   cout << "Please enter your id number: ";
   cin  >> user.id;
   cout << endl;
}

/**********************************************************************
 * Function: display
 * Purpose: Display information
 ***********************************************************************/
// display information
void display(const Student & user)
{
   cout << "Your information:"
        << endl
        << user.id
        << " - "
        << user.firstName
        << " "
        << user.lastName
        << endl;
}

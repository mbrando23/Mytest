/***********************************************************************
* Program:
*    Checkpoint 02b, Complex Numbers
*    Brother Alvey, CS165
* Author:
*    Milton Nogueira Brando Neto
* Summary: 
*    
************************************************************************/

#include <iostream>
using namespace std;

// TODO: Define your Complex struct here
struct Complex
{
   double real;
   double imaginary;
};

// TODO: Add your prompt function here
void prompt(Complex & c)
{

   cout << "Real: ";
   cin  >> c.real;
   cout << "Imaginary: ";
   cin  >> c.imaginary;
}

// TODO: Add your display function here
void display(const Complex & sum)
{

   //cout.precision(1);

   cout << sum.real
        << " + "
        << sum.imaginary
        << "i";
}

/**********************************************************************
 * Function: addComplex
 * Purpose: Adds two complex numbers together and returns the sum.
 ***********************************************************************/
Complex addComplex(const Complex & x, const Complex & y)
{
   // TODO: Fill in the body of the add function
   Complex sum;
   sum.real = x.real + y.real;
   sum.imaginary = x.imaginary + y.imaginary;
   return sum;
}


/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   // Declare two Complex objects, c1 and c2
   Complex c1;
   Complex c2;

   // Call your prompt function twice to fill in c1, and c2 
   prompt(c1);
   prompt(c2);

   // Declare another Complex for the sum
   Complex sum;

   // Call the addComplex function, putting the result in sum;
   sum = addComplex(c1, c2);
   
   cout << "\nThe sum is: ";
   display(sum);
   cout << endl;
 
   return 0;
}



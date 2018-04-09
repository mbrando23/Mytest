/***********************************************************************
* Program:
*    Assignment 14, Matthew 18:21-22
*    Brother Ellsworth, CS124
* Author:
*    Milton Nogueira Brando Neto
* Summary: 
*    This program will address Peter's question to the Lord in 
*    Matthew 18:21-22
*
*    Estimated:  0.5 hrs   
*    Actual:     0.8 hrs
*      I had some trouble when I tried to pass styleChecker.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
* Use this function to input only.
***********************************************************************/
void questionPeter()
{
   // display Peter's question
   cout << "Lord, how oft shall my brother sin against me, and I forgive him?"
        << "\nTill seven times?\n";
   // send no information back to main()
   return;
}

/**********************************************************************
* Use this function to input only.
***********************************************************************/
int responseLord()
{
   // display Lord's answer
   return 490;
}

/**********************************************************************
* Just implement the two functions: questionPeter() and responseLord().
***********************************************************************/
int main()
{
   // ask Peter's question
   questionPeter();

   // the first part of the Lord's response
   cout << "Jesus saith unto him, I say not unto thee, Until seven\n";
   cout << "times: but, Until " << responseLord() << ".\n";

   return 0;
}

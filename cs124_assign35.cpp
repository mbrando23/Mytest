/***********************************************************************
* Program:
*    Assignment 35, Advanced Conditionals
*    Brother Ellsworth, CS124
* Author:
*    Milton Nogueira Brando Neto
* Summary: 
*    This program prompts the user for a number grade then displays the
*    letter grade properly.
*    Estimated:  0.7 hr   
*    Actual:     0.7 hr
*       The most difficult part was not to use conditional operators.
**********************************************************************/

#include <iostream>
using namespace std;


/**********************************************************************
*  computeLetterGrade() returns the letter grade from a number grade.
**********************************************************************/
char computeLetterGrade(int grade)
{
   char letterGrade;
   switch (grade / 10)
   {
      case 10:
      case 9:
         letterGrade = 'A';
         break;
      case 8:
         letterGrade = 'B';
         break;
      case 7:
         letterGrade = 'C';
         break;
      case 6:
         letterGrade = 'D';
         break;
      default:
         letterGrade = 'F';
   }
   return letterGrade;
}


/**********************************************************************
*  computeGradeSign() returns the grade sign '+' or '-' from a number
*  grade.
**********************************************************************/
char computeGradeSign(int grade)
{
   char result;
   switch (grade % 10)
   {
      case 9:
      case 8:
      case 7:
         result = '+';
         break;
      case 2:
      case 1:
      case 0:
         result = '-';
         break;
      default:
         result = 'x';      
   }
   return result;
}


/**********************************************************************
*  main() prompts the user for a number graded then displays the letter
*  grade with the proper sign. 
**********************************************************************/
int main()
{
   int grade;
   cout << "Enter number grade: ";
   cin  >> grade;
   char letter = computeLetterGrade(grade);
   char sign   = computeGradeSign(grade);
   char letterGrade;
   switch (letter)
   {
      case 'A':
      case 'F':
         cout << grade
              << "% is "
              << letter
              << endl;
         break;
      default:
         switch (grade % 10)
         {
            case 9:
            case 8:
            case 7:
               cout << grade
                    << "% is "
                    << letter
                    << sign
                    << endl;
               break;
            case 2:
            case 1:
            case 0:
               cout << grade
                    << "% is "
                    << letter
                    << sign
                    << endl;
               break;
            default:
               cout << grade
                    << "% is "
                    << letter
                    << endl;
         }
   }  
   return 0;
}




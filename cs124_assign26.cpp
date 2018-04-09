/***********************************************************************
* Program:
*    Assignment 26, Files
*    Brother Ellsworth, CS124
* Author:
*    Milton Nogueira Brando Neto
* Summary: 
*    This program read 10 grades from a file and display the average. 
*    Estimated:  0.7 hr   
*    Actual:     1.0 hr
*       The most difficult part was setting to report error. 
***********************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

/***********************************************************************
*  This function prompts the user for file name. 
***********************************************************************/
void getFileName(char fileName[]) 
{
  cout << "Please enter the filename: "; 
  cin >> fileName; 

}

/***********************************************************************
*  This function reads the file and returns the average score of the ten 
*  values.
***********************************************************************/
float readFile(char fileName[])
{
   ifstream fin(fileName);                      // attempt to open the file 
   float grade;
   float sum   = 0.0; 
   int count = 0;   

   while(fin >> grade) 
   { 
      sum += grade;
      count++;
   }
   if(count != 10)
   {  
      cout << "Error reading file " 
           << "\""
           << fileName
           << "\"\n"; 
      return 0;
   }      
   if (count == 10)
   {   
      float average;
      average = sum / 10;
      return average;  
   }
   fin.close();
}

/***********************************************************************
*  This function displays the average score to zero decimals of accuracy
*  (rounded).
***********************************************************************/
void display(float average)
{
   // configure COUT for displaying average score 
   cout.setf(ios::fixed);  
   cout.precision(0);
   cout << "Average Grade: " 
        << average 
        << "%\n";    

 
}



/***********************************************************************
*  This function calls others and send average parameter to display it 
*  at display function.
***********************************************************************/
int main()
{
   char fileName[256];
   getFileName(fileName);
   float average = readFile(fileName);
   if (average != 0)
      display (average);
   
   return 0;
}




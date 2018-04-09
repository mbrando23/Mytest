/***********************************************************************
* Program:
*    Assignment 40, MULTI-DIMENSIONAL ARRAYS
*    Brother Ellsworth, CS124
* Author:
*    Milton Nogueira Brando Neto
* Summary: 
*    This program reads a Tic-Tac-Toe board into an array then writes it   
*    in another file.
*    Estimated:  0.7 hr   
*    Actual:     0.7 hr
*       The most difficult part was to 
***********************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

/***********************************************************************
*  This function reads a file into an array and displays a board on the
*  screen.
***********************************************************************/
bool readBoard(char ticTac[][3], const char * fileName)
{
   ifstream fin(fileName);
   if (fin.fail())
      return false;

   // loop through the characters
   for (int row = 0; row < 3; row++)
      for (int col = 0; col < 3; col++)
      {
         fin >> ticTac[row][col];         
         if (fin.fail())
         {
            fin.close();
            return false;
         }
         
      }
      

   fin.close();
   return true;
}

/***********************************************************************
*  This function writes the displayed board into a file.
***********************************************************************/
bool writeBoard(char ticTac[][3], const char * fileName)
{
   ofstream fout(fileName);
   if (fout.fail())
      return false;

   // loop through the characters
   for (int row = 0; row < 3; row++)
      for (int col = 0; col < 3; col++)
      {
         fout << ticTac[row][col]
              << (col == 2 ? '\n' : ' ');          
         if (fout.fail())
         {
            fout.close();
            return false;
         }
  
      }

   fout.close();
   return true;
}




/***********************************************************************
*  This function prompts the user for a filename to read then prompts
*  the user again for a destination filename and calls two functions
*  to make those tasks, also displays the board.
***********************************************************************/
int main()
{
   char ticTac[3][3];
   
   cout << "Enter source filename: ";
   char source[256];
   cin  >> source;
   if (!readBoard(ticTac, source))
      return 1;
      
   for (int row = 0; row < 3; row++)
      for (int col = 0; col < 3; col++)
      {   
         if (ticTac[row][col] == '.')
            ticTac[row][col] = ' '; 
      }
   cout << " " << ticTac[0][0] << " | " << ticTac[0][1] << " | " 
        << ticTac[0][2] << " "
        << endl 
        << "---+---+---"
        << endl
        << " " << ticTac[1][0] << " | " << ticTac[1][1] << " | " 
        << ticTac[1][2] << " "
        << endl 
        << "---+---+---"
        << endl
        << " " << ticTac[2][0] << " | " << ticTac[2][1] << " | " 
        << ticTac[2][2] << " "
        << endl;
   
   cout << "Enter destination filename: ";
   char destin[256];
   cin  >> destin;
   
   for (int row = 0; row < 3; row++)
      for (int col = 0; col < 3; col++)
      {   
         if (ticTac[row][col] == ' ')
            ticTac[row][col] = '.';
      } 
   
   if (!writeBoard(ticTac, destin))
      return 1;
   cout << "File written\n";
   return 0;
}




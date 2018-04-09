/***********************************************************************
* Program:
*    Project 13, Sudoku
*    Brother Ellsworth, CS124
* Author:
*    Milton Nogueira Brando Neto
* Summary: 
*    Make the game to obey the rules of Sudoku.  
*    Estimated:  2.0 hr   
*    Actual:    15.0 hr
*      The most difficult part was to sincronize the possible values
*         with the edit function.
***********************************************************************/

#include <iostream> 
#include <fstream>
#include <cctype> 
#include <cassert>
#include <iomanip>
#include <cstdlib>
  
using namespace std;

// function prototypes
void getFileName    (char fileName[]);                         
bool readFile       (char filename[], char board[][9]);           
bool writeBoard     (char board[][9]);                          
bool interact       (char board[][9]);                            
void displayOptions ();                                     
void displayBoard   (char board[][9]);                        
void editSquare     (char board[][9], int array[], char coordinates[],
                     bool possible[]);          
void displayPossible(char board[][9], int array[], char coordinates[],    
                     bool possible[]);    
void getCoordinates (int array[], char coordinates[]);      
void computeValues  (bool possible[], char board[][9], int array[]); 

/***********************************************************************
*  main() function calls getFilename(), calls readFile() and gets the    
*  board array, then calls interact() and passes it. Also calls 
*  displayOptions() at first and calls writeBoard() in the end to store
*  the values of this board array.
***********************************************************************/
int main()
{
   char fileName[256];                  // declaring file name to read
   char board[9][9];                    // declaring principal board 
   getFileName(fileName);               // calling to get file name
   if (!readFile(fileName, board))      // calling to get board 
      return 1;
   displayOptions();                    // first screen to user
   displayBoard(board);                 // first board to user
   if (interact(board))                 // giving the user choices
      if (!writeBoard(board))           // writing a new board
         return 1; 
   return 0;
}

/***********************************************************************
*  getFileName() prompts the user for filename in order to use it into 
*  the readFile() funcion.
***********************************************************************/
void getFileName(char fileName[])
{
   cout << "Where is your board located? ";              // prompts user
   cin  >> fileName;                                     // gets fileName
   cin.ignore();                                         // little bug
}

/***********************************************************************
*  readFile() uses filename to fill the board. 
***********************************************************************/
bool readFile(char fileName[], char board[][9])
{
   ifstream fin(fileName); 
   if (fin.fail())                    // checks for any type of error 
   {
      cout << "Unable to open file " 
           << fileName  
           << endl; 
      return false;                   // reports failure to the user
   }

   // loop and read through the array 
   for (int row = 0; row < 9; row++)
      for (int col = 0; col < 9; col++)
      {
         fin >> board[row][col];      // reading through the array    
         if (fin.fail())
         {
            fin.close();
            return false;
         }        
      }
      
   fin.close();                      // closing file
   return true;

}

/***********************************************************************
*  writeBoard() stores a final array in a file.
***********************************************************************/
bool writeBoard(char board[][9])
{
   char fileName2[256];
   cout << "What file would you like to write your board to: "; // prompt
   cin  >> fileName2;                          // gets other file name
 
   ofstream fout(fileName2);                   // opens file
   if (fout.fail())
      return false;

   // loop through the characters to record into the file
   for (int row = 0; row < 9; row++)
      for (int col = 0; col < 9; col++)
      {
         fout << board[row][col]
              << (col == 8 ? '\n' : ' ');      // to be a 2D array         
         if (fout.fail())
         {
            fout.close();                      // if fails return
            return false;
         }
      }
   fout.close();
   cout << "Board written successfully"        // reporting success to user
        << endl;
   return true;

}

/***********************************************************************
*  interact() gets a board array from main then calls other functions as 
*  chosen by the user. 
***********************************************************************/
bool interact(char board[][9])
{
   char option;
   char coordinates[2];                       // initializes variables
   int array[2];
   bool possible[10];
   // loop until the user decides to leave
   do
   {
      cout << "> ";
      cin  >> option;
      switch (option)
      {
         case '?':
            displayOptions();             // displays the options of the user
            cout << endl;
            break;
         case 'd':
         case 'D':
            displayBoard(board);          // displays board on the screen
            break;
         case 'e':
         case 'E':                        // verifies and edits board values
            getCoordinates(array, coordinates);
            editSquare(board, array, coordinates, possible); 
            cout << endl;
            break;
         case 's':
         case 'S':                        // computes board values
            getCoordinates(array, coordinates);
            displayPossible(board, array, coordinates, possible);
            cout << endl;
            break;
         case 'q':
         case 'Q':
            break;
         default:
            cout << "ERROR: Invalid command"
                 << endl;
      }
   }
   while (option != 'q' && option != 'Q'); 
      return true;                       // returns to finish
}

/***********************************************************************
 *  displayOptions() displays the instructions on the screen. 
 ***********************************************************************/
void displayOptions()
{
   // gives to the user the options on the screen
   cout << "Options:"
        << endl
        << "   ?  Show these instructions"
        << endl
        << "   D  Display the board"
        << endl
        << "   E  Edit one square"
        << endl
        << "   S  Show the possible values for a square"
        << endl
        << "   Q  Save and Quit"
        << endl
        << endl;
}

/***********************************************************************
 *  displayBoard() displays the contents of the board[][] array on the 
 *  screen. 
 ***********************************************************************/
void displayBoard(char board[][9])
{
   // taking out zeros and putting blank spaces
   for (int row = 0; row < 9; row++)
      for (int col = 0; col < 9; col++)
      {   
         if (board[row][col] == 48)
            board[row][col] = ' '; 
      }

   //line 0
   cout << "   A B C D E F G H I"  
        << endl; 
   
   // line 1 
   cout << 1 << "  ";
   for (int i = 0; i < 2; i++)
      cout << board[0][i] 
           << " ";
   cout << board[0][2] << "|";
   for (int i = 3; i < 5; i++)
      cout << (board[0][i] == 0 ? ' ' : board[0][i]) 
           << " ";   
   cout << board[0][5] << "|";
   for (int i = 6; i < 8; i++)
      cout << board[0][i] 
           << " ";
   cout << board[0][8] << endl;
   
   // line 2
   cout << 2 << "  ";
   for (int i = 0; i < 2; i++)
      cout << board[1][i] 
           << " ";
   cout << board[1][2] << "|";
   for (int i = 3; i < 5; i++)
      cout << board[1][i] 
           << " ";
   cout << board[1][5] << "|";
   for (int i = 6; i < 8; i++)
      cout << board[1][i] 
           << " ";
   cout << board[1][8] << endl;
   
   // line 3
   cout << 3 << "  ";
   for (int i = 0; i < 2; i++)
      cout << board[2][i] 
           << " ";
   cout << board[2][2] << "|";
   for (int i = 3; i < 5; i++)
      cout << board[2][i] 
           << " ";
   cout << board[2][5] << "|";
   for (int i = 6; i < 8; i++)
      cout << board[2][i] 
           << " ";
   cout << board[2][8] << endl;
   
   // division 1
   cout << "   -----+-----+-----"
        << endl;
        
   // line 4
   cout << 4 << "  ";
   for (int i = 0; i < 2; i++)
      cout << board[3][i] 
           << " ";
   cout << board[3][2] << "|";
   for (int i = 3; i < 5; i++)
      cout << board[3][i] 
           << " ";
   cout << board[3][5] << "|";
   for (int i = 6; i < 8; i++)
      cout << board[3][i] 
           << " ";
   cout << board[3][8] << endl;
   
   // line 5
   cout << 5 << "  ";
   for (int i = 0; i < 2; i++)
      cout << board[4][i] 
           << " ";
   cout << board[4][2] << "|";
   for (int i = 3; i < 5; i++)
      cout << board[4][i] 
           << " ";
   cout << board[4][5] << "|";
   for (int i = 6; i < 8; i++)
      cout << board[4][i] 
           << " ";
   cout << board[4][8] << endl;
   
   // line 6
   cout << 6 << "  ";
   for (int i = 0; i < 2; i++)
      cout << board[5][i] 
           << " ";
   cout << board[5][2] << "|";
   for (int i = 3; i < 5; i++)
      cout << board[5][i] 
           << " ";
   cout << board[5][5] << "|";
   for (int i = 6; i < 8; i++)
      cout << board[5][i] 
           << " ";
   cout << board[5][8] << endl;
   
   // division 2 
   cout << "   -----+-----+-----"
        << endl;
          
   // line 7
   cout << 7 << "  ";
   for (int i = 0; i < 2; i++)
      cout << board[6][i] 
           << " ";
   cout << board[6][2] << "|";
   for (int i = 3; i < 5; i++)
      cout << board[6][i] 
           << " ";
   cout << board[6][5] << "|";
   for (int i = 6; i < 8; i++)
      cout << board[6][i] 
           << " ";
   cout << board[6][8] << endl;
   
   // line 8 
   cout << 8 << "  ";
   for (int i = 0; i < 2; i++)
      cout << board[7][i] 
           << " ";
   cout << board[7][2] << "|";
   for (int i = 3; i < 5; i++)
      cout << board[7][i] 
           << " ";
   cout << board[7][5] << "|";
   for (int i = 6; i < 8; i++)
      cout << board[7][i] 
           << " ";
   cout << board[7][8] << endl;
    
   // line 9
   cout << 9 << "  ";
   for (int i = 0; i < 2; i++)
      cout << board[8][i] 
           << " ";
   cout << board[8][2] << "|";
   for (int i = 3; i < 5; i++)
      cout << board[8][i] 
           << " ";
   cout << board[8][5] << "|";
   for (int i = 6; i < 8; i++)
      cout << board[8][i] 
           << " ";
   cout << board[8][8] << endl;  
   
   // putting zeros again into the board
   for (int row = 0; row < 9; row++)
      for (int col = 0; col < 9; col++)
      {   
         if (board[row][col] == ' ')
            board[row][col] = 48; 
      }  
   cout << endl; 
}

/***********************************************************************
 *  editSquare() edits a square with no verification if values are correct 
 *  or valid.
 ***********************************************************************/
void editSquare(char board[][9], int array[], char coordinates[],
                bool possible[])
{
   char newValue;  
   computeValues(possible, board, array);
   int right = 0;
                                          // cases not defined before
   if (array[0] == 9 || array[1] == 9)    //   on getCoordinates()
   {    
      cout << "ERROR: Square "
           << "'"
           << coordinates
           << "'"
           << " is invalid" 
           << endl;
   }                                       
   // if there is a third place...
   else if (coordinates[2])
   {
      cout << "ERROR: Square "
           << "'"
           << coordinates
           << "'"
           << " is invalid" 
           << endl;
   }                                        
   // not use only letter or numbers
   else if (coordinates[0] > 64 && coordinates[1] > 64)
   {
      cout << "ERROR: Square "
           << "'"
           << coordinates
           << "'"
           << " is invalid" 
           << endl;
   }                                         
   // better use of letter or numbers
   else if (coordinates[0] < 48 || coordinates[1] < 48)
   {
      cout << "ERROR: Square "
           << "'"
           << coordinates
           << "'"
           << " is invalid" 
           << endl;
   }                                         
   // not use only letter or numbers
   else if (coordinates[0] < 58 && coordinates[1] < 58)
   {
      cout << "ERROR: Square "
           << "'"
           << coordinates
           << "'"
           << " is invalid" 
           << endl;
   }  
   else if (board[array[0]][array[1]] != 48) // if is different from zeros
   {
      cout << "ERROR: Square" 
           << " '"
           << coordinates[0]
           << coordinates[1] 
           << "'" 
           << " is filled"
           << endl;
   }
   else                                       // then we can continue...
   {
      cout << "What is the value at"
           << " '"
           << coordinates[0]
           << coordinates[1]
           << "': ";
      cin  >> newValue;

      // newValue variable is a char
      if (newValue == 49 || newValue == 50 || newValue == 51 ||
          newValue == 52 || newValue == 53 || newValue == 54 ||
          newValue == 55 || newValue == 56 || newValue == 57)
      {
         for (int i = 1; i < 10; i++)           
         {
            if (possible[i])
            {   
               if (newValue - 48 == i)        // equalization of int and char
               { 
                  right += 1;
               } 
            }
         }
         if (right == 0)                        // variable used to compare two
            cout << "ERROR: Value '"            //   situations
                 << newValue
                 << "' in square '"
                 << coordinates 
                 << "' is invalid" 
                 << endl;
         else
            board[array[0]][array[1]] = newValue;    
      }
      else
      {
         cout << "ERROR: Value '"            //   the same words used before
              << newValue
              << "' in square '"
              << coordinates 
              << "' is invalid"
              << endl;
      }
   }
}

/***********************************************************************
 *  displayPossible() shows possible values from computeValues() function.
 ***********************************************************************/
void displayPossible(char board[][9], int array[], char coordinates[], 
                     bool possible[])
{
   bool first = true;
   computeValues(possible, board, array);
                                             // cases not defined before
   if (array[0] == 9 || array[1] == 9)       //    on getCoordinates()    
   {                                           
      cout << "ERROR: Square "                
           << "'"
           << coordinates[0]
           << coordinates[1]
           << "'"
           << " is invalid" 
           << endl;
   }                                         
   // not use only letter or numbers
   else if (coordinates[0] > 64 && coordinates[1] > 64)
   {
      cout << "ERROR: Square "
           << "'"
           << coordinates[0]
           << coordinates[1]
           << "'"
           << " is invalid" 
           << endl;
   }                                         
   // not use only letter or numbers
   else if (coordinates[0] < 58 && coordinates[1] < 58)
   {
      cout << "ERROR: Square "
           << "'"
           << coordinates[0]
           << coordinates[1]
           << "'"
           << " is invalid" 
           << endl;
   }                                         
   // better use of letter or numbers
   else if (coordinates[0] < 48 || coordinates[1] < 48)
   {
      cout << "ERROR: Square "
           << "'"
           << coordinates[0]
           << coordinates[1]
           << "'"
           << " is invalid" 
           << endl;
   }
   else if (board[array[0]][array[1]] != 48)  // if is different from zeros
   {
      cout << "ERROR: Square" 
           << " '"
           << coordinates[0]
           << coordinates[1] 
           << "'" 
           << " is filled"
           << endl
           << endl;
   }
   else                                       // then we can continue...
   {
      cout << "The possible values for '"
           << coordinates[0]
           << coordinates[1]
           << "' are: "; 
      for (int i = 1; i < 10; i++)
         if (possible[i])                     // displays possible values
         {                                   
            if (!first)                       //    on the screen to the user
            {
               cout << ", "; 
            } 
            cout << i;     
            first = false;
         }
      cout << endl;
   }
}

/***********************************************************************
 *  getCoordinates() gets sudoku coordinates from user.
 ***********************************************************************/
void getCoordinates(int array[], char coordinates[])
{

   cout << "What are the coordinates of the square: ";
   cin  >> coordinates;
  
   // the cases allowed to store from the 1st place of coordinates
   switch (coordinates[0])
   {
      case 49: 
         array[0] = 0;
         break;
      case 50:
         array[0] = 1;
         break;
      case 51:
         array[0] = 2;
         break;
      case 52:
         array[0] = 3;
         break;
      case 53:
         array[0] = 4;
         break;
      case 54:
         array[0] = 5;
         break;
      case 55:
         array[0] = 6;
         break;
      case 56:
         array[0] = 7;
         break;
      case 57:
         array[0] = 8;
         break;
      case 97:
      case 65:
         array[1] = 0;
         break;
      case 98:
      case 66:
         array[1] = 1;
         break;
      case 99:
      case 67:
         array[1] = 2;
         break;
      case 100:
      case 68:
         array[1] = 3;
         break;
      case 101:
      case 69:
         array[1] = 4;
         break;
      case 102:
      case 70:
         array[1] = 5;
         break;
      case 103:
      case 71:
         array[1] = 6;
         break;
      case 104:
      case 72:
         array[1] = 7;
         break;
      case 105:
      case 73:
         array[1] = 8;
         break;
      default:
         array[1] = 9;             // special case in displayPossible
   }
   
   // the cases allowed to store from the 2nd place of coordinates
   switch (coordinates[1])
   {
      case 49:
         array[0] = 0;
         break;
      case 50:
         array[0] = 1;
         break;
      case 51:
         array[0] = 2;
         break;
      case 52:
         array[0] = 3;
         break;
      case 53:
         array[0] = 4;
         break;
      case 54:
         array[0] = 5;
         break;
      case 55:
         array[0] = 6;
         break;
      case 56:
         array[0] = 7;
         break;
      case 57:
         array[0] = 8;
         break;
      case 97:
      case 65:
         array[1] = 0;
         break;
      case 98:
      case 66:
         array[1] = 1;
         break;
      case 99:
      case 67:
         array[1] = 2;
         break;
      case 100:
      case 68:
         array[1] = 3;
         break;
      case 101:
      case 69:
         array[1] = 4;
         break;
      case 102:
      case 70:
         array[1] = 5;
         break;
      case 103:
      case 71:
         array[1] = 6;
         break;
      case 104:
      case 72:
         array[1] = 7;
         break;
      case 105:
      case 73:
         array[1] = 8;
         break;
      default:
         array[1] = 9;             // special case in displayPossible
   }
}

/***********************************************************************
 *  computeValues() verifies if a user input is correct or valid.
 ***********************************************************************/
void computeValues(bool possible[], char board[][9], int array[])
{
   // first set all true
   for (int i = 0; i < 10; i++)
      possible[i] = true;  
   // set false the values on the same column
   for (int iRow = 0; iRow < 9; iRow++)
      possible[board[iRow][array[1]] - 48] = false;
   // set false the values on the same row
   for (int iCol = 0; iCol < 9; iCol++)
      possible[board[array[0]][iCol] - 48] = false;
   // set false the values on the same square
   for (int iRow = 0; iRow < 3; iRow++)
      for (int iCol = 0; iCol < 3; iCol++)
         possible[board[array[0] / 3 * 3 + iRow] [array[1] / 3 * 3 + iCol]
                  - 48] = false;
  
}

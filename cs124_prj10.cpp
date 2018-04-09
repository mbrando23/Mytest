/***********************************************************************
* Program:
*    Project 10, Mad Lib
*    Brother Ellsworth, CS124
* Author:
*    Milton Nogueira Brando Neto
* Summary: 
*    Prompt the user for a lib file, substitute words. Then, display
*    a complete story on the screen.
*    Estimated:  4.0 hr   
*    Actual:     5.0 hr
*      The most difficult part was to set cin for askQuestions function. 
***********************************************************************/

#include <iostream> 
#include <fstream>
#include <cctype>
#include <cassert>
#include <iomanip>
  
using namespace std;

int  readFile(char story[][32]);                   // prototype 
void getFileName(char fileName[]);                 // prototype 
void askQuestions(char text[]);                    // prototype 
bool playAgain();                                  // prototype 
void displayStory(char story[][32], int);          // prototype 
bool isPunc(char story[]);                         // prototype 

/***********************************************************************
*  MAIN gets the story from readFile() and sends it to displayStory().
*  Then, receives continue or not from playAgain().
***********************************************************************/
int main()
{
   char story[256][32];                   // 256 words in the story
   do                                     // with 32 caracters lenght
   {     
      int numWords = readFile(story);     // pass by reference
      displayStory(story, numWords);      // pass by reference
   }
   while (playAgain());                   // prompt the user
   
      cout << "Thank you for playing.\n"; // then finishing
      
   return 0;
}


/***********************************************************************
*  READFILE receives filename from getFileName(); then open it, and
*  read the words for askQuestions() and story.
***********************************************************************/
int readFile(char story[][32])
{
   char fileName[256];                // normal size for filename
   getFileName(fileName);
   
   ifstream fin(fileName);
   if (fin.fail())                    // check for any type of error 
   {
      cout << "Unable to open file " 
           << fileName  
           << endl; 
      return false;                   // report failure to the user
   }
     
   // loop and read through the words of the file 
   int numWords = 0; 
   while (numWords < 256 && fin >> story[numWords])
   {
      askQuestions(story[numWords]); 
      numWords++;
   }
   fin.close();
   return numWords;                   // return number of words

}

/***********************************************************************
*  GETFILENAME prompts the user for a filename, then sends it to
*  readFile().
***********************************************************************/
void getFileName(char fileName[])
{
   cout << "Please enter the filename of the Mad Lib: "; // prompts user
   cin  >> fileName;                                     // gets fileName
   cin.ignore();                                         // little bug
}


/***********************************************************************
*  ASKQUESTIONS prompts the user for answers into some parts of the
*  story.
***********************************************************************/
void askQuestions(char text[]) 
{
   if (text[0] != '<' || !isalpha(text[1]))            // no questions ignored
      return;        
   if (text[0] == '<' && isalpha(text[1]))
   {     
      text[1] = toupper(text[1]);                      // 1st letter uppercase
      cout << "\t"                                     // one tab
           << text[1];                                 // display 1st letter
      for (int iText = 2; text[iText] != '>'; iText++) // loop into questions
      {
         text[iText] = tolower(text[iText]);           // all rest lowercase
         if (text[iText] == '_')                       // put _ for space
            text[iText] = ' ';   
         cout << text[iText];                          // display text
      }        
      cout << ": ";                                    // format assigned   

      cin.getline(text, 32);                           // properly fetch the
                                                       //  section input     
   }
    
}
 

/***********************************************************************
*  PLAYAGAIN prompts the user for new game and sends continue to
*  main().
***********************************************************************/
bool playAgain()
{
   char play;
   cout << "\nDo you want to play again (y/n)? ";         // prompt user
   cin  >> play;                                          // store
   return (play == 'y' || play == 'Y' ? true : false);    // return answers
     
}

   


/***********************************************************************
*  DISPLAYSTORY receives story and lenght as parameters from main(), 
*  receiveis isPunc from isPunc() and displays complete story.
***********************************************************************/
void displayStory(char story[][32], int numWords)
{
   cout << endl; 
   int i = 0;
   while (i <= numWords)               // loop through the words     
   {
      if (story[i][1] == '#')          // display newline
         cout << endl; 
      else if (story[i][1] == '{')     // display quotes
         cout << " \"";
      else if (story[i][1] == '}')     // display quotes
         cout << "\" ";
      else if (story[i][1] == '[')     // display quotes
         cout << " '";
      else if (story[i][1] == ']')     // display quotes
         cout << "' ";
      else                             // how to display the story
         if (isPunc(story[i]) || i == 0 || story[i - 1][1] == '#'
            || story[i - 1][1] == '}' || story[i - 1][1] == '{'
            || story[i - 1][1] == ']' || story[i - 1][1] == '['
            || story[i][1] == '}' || story[i][1] == '{'
            || story[i][1] == ']' || story[i][1] == '['
            || story[i][1] == '#') 
            cout << story[i];  // do not put space in these cases       
         else             
            cout << " "        // put a space before as default
                 << story[i];
      i++;         
   } 
}
  

/***********************************************************************
*  ISPUNC() verifies if a character is punctuation or not and returns it 
*  to displayStory().
***********************************************************************/
bool isPunc(char story[])   
{
   if (story[0] == ',' || story[0] == '.' || story[0] == '!' || 
      story[0] == '?')         // if we have these punctuation cases
      return true;             // return true to display
   else
      return false;
}



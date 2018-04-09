/***********************************************************************
* Program:
*    Project 09, Mad Lib Program
*    Brother Ellsworth, CS124
* Author:
*    Milton Nogueira Brando Neto
* Summary: 
*    Prompt the user for a lib file, substitute words. Then, display
*    a complete story on the screen.
*    Estimated:  4.0 hr   
*    Actual:     4.5 hr
*      The most difficult part was to read the file and prompt the user.
***********************************************************************/

#include <iostream> 
#include <fstream>
#include <cctype>
#include <cassert>
#include <iomanip>

using namespace std;

int  readFile(char story[][256]);          // prototype of the function
void getFileName(char fileName[]);         // prototype of the function
void askQuestions(char text[]);            // prototype of the function
bool playAgain();                          // prototype of the function
void displayStory();                       // prototype of the function 
bool isPunc();                             // prototype of the function

/***********************************************************************
*  MAIN gets the story from readFile() and sends it to displayStory().
*  Then, receives continue or not from playAgain().
***********************************************************************/
int main()
{
   char story[256][256]; // There are no more than 256 words in the story
   do
   {    
      readFile(story);   // pass by reference
   }
   while (playAgain());  // adjust to next project
   
      return 0;
}


/***********************************************************************
*  READFILE receives filename from getFileName(); then open it, and
*  read the words for askQuestions() and story.
***********************************************************************/
int readFile(char story[][256])
{
   char fileName[256];
   getFileName(fileName);
   
   ifstream fin(fileName);
   if (fin.fail())                    // check for any type of error 
   {
      cout << "Unable to open file " 
           << fileName  
           << endl; 
      return false;                   // report failure to the user
   }
    

   int numWords = 0; 
   while (numWords < 256 && fin >> story[numWords])
   {
      askQuestions(story[numWords]);  // loop through the words    
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

}




/***********************************************************************
*  ASKQUESTIONS prompts the user for answers into some parts of the
*  story.
***********************************************************************/
void askQuestions(char text[]) 
{
   if (text[0] != '<' || !isalpha(text[1]))         // no questions ignored
      return;
   
   text[1] = toupper(text[1]);                      // 1st letter uppercase
      
   cout << "\t"                                     // one tab
        << text[1];                                 // display 1st letter
       
   for (int iText = 2; text[iText] != '>'; iText++) // loop through questions
   {
      text[iText] = tolower(text[iText]);           // all rest lowercase
      if (text[iText] == '_')                       // substitute _ for space
         text[iText] = ' ';   
      cout << text[iText];                          // display text
   }   
   
   cout << ": ";                                    // format assigned
   cin.ignore();                                    // properly fetch the
   cin.getline(text, 256);                          // section input
 
 
}




/***********************************************************************
*  PLAYAGAIN prompts the user for new game and sends continue to
*  main().
***********************************************************************/
bool playAgain()
{
   cout << "Thank you for playing.\n";    // finishing for now
   return 0;
}




/***********************************************************************
*  DISPLAYSTORY receives story and lenght as parameters from main(), 
*  receiveis isPunc from isPunc() and displays complete story.
***********************************************************************/
void displayStory()
{
                                   // stub for now...
}





/***********************************************************************
*  ISPUNC()
***********************************************************************/
bool isPunc()
{
   return 0;                       // stub for now...
}



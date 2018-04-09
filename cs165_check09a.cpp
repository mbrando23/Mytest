/***********************************************************************
* Program:
*    Checkpoint 09a, Virtual Functions
*    Brother Alvey, CS 165
* Author:
*    Milton Nogueira Brando Neto
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>
using namespace std;

// For this assignment, for simplicity, you may put all of your classes
// in this file.

// TODO: Define your classes here
class Car
{
   protected:
      string name;

   public:
      Car()
      {
         setName("Unknown model");
      }
   
      string getName() 
      {
         return name;
      }

      void setName(string name)
      {
         this->name = name;
      }

      virtual string getDoorSpecs() 
      {
         string v = "Unknown doors";
         return v;
      }

};

class Civic : public Car
{
   public:

      virtual string getDoorSpecs()
      {
         string v = "4 doors";
         return v;
      }

      Civic()
      {
         setName("Civic");
      }
};

class Odyssey : public Car
{
   public:

      virtual string getDoorSpecs() 
      {
         string v = "2 front doors, 2 sliding doors, 1 tail gate";
         return v;
      }

      Odyssey()
      {
         setName("Odyssey");
      }
};

class Ferrari : public Car
{
   public:

      virtual string getDoorSpecs() 
      {
         string v = "2 butterfly doors";
         return v;
      }

      Ferrari()
      {
         setName("Ferrari");
      }
};





/**********************************************************************
 * Function: attachDoors
 * Purpose: This function can accept any type of Car object. It will
 *  call the appropriate functions to display the name and the doors info.
 ***********************************************************************/

// TODO: Include your attachDoors function here
void attachDoors(Car & car)
{
   cout << "Attaching doors to "
        << car.getName()
        << " - "
        << car.getDoorSpecs()
        << endl;
}


/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   // You should not change main

   Civic civic;
   Odyssey odyssey;
   Ferrari ferrari;

   attachDoors(civic);
   attachDoors(odyssey);
   attachDoors(ferrari);

   return 0;
}



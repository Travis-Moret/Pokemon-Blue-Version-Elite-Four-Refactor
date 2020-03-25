/**************************************************************************
** Project Name: Final Project
** Author: Travis Moret
** Date: 12/7/2019
** Description: In this program, Ash must battle the elite four to become
                the Indigo League Champion. Ash's Level 80 Pikachu must
                defeat each Gym Leaders' pokemon to advance to the next
                gym. If Ash's Pikachu faints, the game ends. If Ash defeats
                each gym leader, he will attain the golden key to unlock
                the Champion's Chamber.
**************************************************************************/

#include <iostream>
#include <string>
#include "Space.hpp" //include all header files
#include "Die.hpp" 
#include "Pokemon.hpp" 
#include "Game.hpp" 

using std::cout;
using std::endl;
using std::cin;
using std::string; 

/*
* Summary: constructor 
* Param: 
* Returns: 
*/
Space::Space()
{
   
   inventory.reserve(1);//set a limit on the container size   
   trainerName = "Ash"; 
   gymLeader = " "; 
   gymName = " ";  
   defender = nullptr;
   currentSpace = nullptr;  
   indigoPlateauFlag = false; 
   loreleiGymFlag = false; 
   brunoGymFlag = false; 
   agathaGymFlag = false; 
   lanceGymFlag = false;  
   
    
}


 
/*
* Summary: destructor
* Param: 
* Returns: 
*/
Space::~Space()
{ 
   delete defender; 
} 



/*
* Summary: set leader
* Param: 
* Returns: 
*/
void Space::setGymLeader(string nameIn)
{ 
   gymLeader = nameIn; 
} 



/*
* Summary: set gym name
* Param: 
* Returns: 
*/
void Space::setGymName(string nameIn)
{ 
   gymName = nameIn; 
} 



/*
* Summary: set the defending pokemon
* Param: 
* Returns: 
*/
void Space::setDefender(Pokemon *defenderIn)
{ 
   defender = defenderIn; 
} 



/*
* Summary: display instructions
* Param: 
* Returns: 
*/
void Space::instructions()
{ 
   cout << "                Instructions" << endl; 
   cout << endl; 
   cout << "       Welcome to the world of Pokemon!" << endl;
   cout << endl;  
   cout << "In this game, you and your level 100 Pikachu must " << endl; 
   cout << "defeat the Elite Four to become the Indigo League " << endl; 
   cout << "champions! Your Pikachu must defeat all 4 gym leaders " << endl; 
   cout << "without fainting, or you will have to start over." << endl; 
   cout << "You have a chance of receiving potions from gym " << endl; 
   cout << "leaders along the way to heal you Pikachu. After " << endl; 
   cout << "defeating the 4th Gym Leader, you will receive the " << endl; 
   cout << "golden key, needed to open the Champion's Chamber." << endl; 
   cout << "If you become the Indigo League Champion, you win!" << endl; 

} 



/*
* Summary: virtual to be overwritten in each space
* Param: 
* Returns: 
*/
void Space::printDialogue()
{

} 



/*
* Summary: virtual to be overwritten in each space
* Param: 
* Returns: 
*/
void Space::printMenu()
{ 


}


 
/*
* Summary: prints the inventory for the user
* Param: none
* Returns: nothing
*/
void Space::printInventory()
{
   int num = 0;   
   cout << endl; 
   cout << "--------------------------" << endl; 
   cout << "Items:" << endl;

   //if there are no items, print message to user
   if(inventory.size()==0)
   { 
      cout << "No Items in the inventory" << endl;
      cout << "--------------------------" << endl;
      cout << endl;  
      printMenu(); 
   } 
   //if there is an item, print string and give additional menu
   else
   { 
      for(int i=0; i<inventory.size(); i++) 
      { 
         cout << inventory[i] << endl;  
      }  
      cout << "--------------------------" << endl;
      cout << endl; 
      cout << "Would you like to use this item?" << endl;   
      cout << endl; 
      cout << "1.Yes" << endl; 
      cout << "2.No" << endl; 
      cout << endl; 
      cout << "Please choose a 1 or a 2." << endl; 
      
      num = integerInputVal(1,2); 
      //bring user to last space if key is used
      if(num == 1)
      { 
        Game G1; 
        G1.moveSpaces(1,5); 
      } 
      else 
      {  
         cout << endl;  
         printMenu(); 
      } 
   } 
}



/*
* Summary: returns trainer name
* Param: none
* Returns: trainer name
*/
string Space::getTrainerName()
{ 
   return trainerName; 
}



/*
* Summary: returns gym leader name
* Param: none
* Returns: gym leader name
*/
string Space::getGymLeader()
{ 
   return gymLeader; 
} 



/*
* Summary: returns the gym name
* Param: none
* Returns: gym name
*/
string Space::getGymName()
{ 
   return gymName; 
} 



/*
* Summary: returns the pokemon of the gym leader of each space
* Param: none
* Returns: nothing
*/
Pokemon * Space::getPokemon()
{ 
   return defender; 
}



/*
* Summary: input validation for ints 
* Param: max and min
* Returns: int 
*/
int Space::integerInputVal(int Min,int Max)
{
   string test=" "; //for testing
   int testInt=0;
   int number = 0;

   do
   {
        //pull the whole line for analysis
        getline(cin,test);

        //test if input is valid, if ENTER was pressed, or if characters
        //were entered
        if (cin.fail() || cin.eof() || test.find_first_not_of("0123456789")
            !=string::npos || test.empty())
        {
            cout << "Please enter a number between " << Min << " and "
                 << Max << "." << endl;

            if (test.find_first_not_of("0123456789") == string::npos)
            {
                cin.clear();//if a character was entered, clear the buffer
            }
         }
         //if a number was entered with no characters, convert it to an
         //integer and test if it is equivalent to the numbers requested
         else
         {
            testInt = stoi(test);

            if (!(testInt >= Min && testInt <= Max))
            {
                 cout << "Please enter a number between " << Min << " and "
                      << Max << "." << endl;
            }
         }
     }
     //loop while input is not between min and max values
     while (!(testInt >= Min && testInt <= Max));
     number = stoi(test);

     return number;
}


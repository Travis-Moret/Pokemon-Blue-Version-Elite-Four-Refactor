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
#include "BrunoGym.hpp" //include all header files
#include "Game.hpp" 
#include "Space.hpp" 

using std::cout;
using std::endl;
using std::cin;

/*
* Summary: 
* Param:  
* Returns: 
*/
void BrunoGym::printDialogue()
{
   Game G1;    

   cout << "           " << getGymName() << endl;

   if(brunoGymFlag == false)
   { 
      cout << "-------------------------------------------------" << endl;
      cout << "I am surprised you got this far, trainer!" << endl;
      cout << "No worries! Bruno will crush you with his super " << endl; 
      cout << "strong fighting Pokemon! " << endl; 
      cout << "-------------------------------------------------" << endl;
      cout << endl;
      G1.oneRound(getGymLeader(),getPokemon()); 
      cout << endl;  
      G1.showHealth(); 
      if(G1.getStatus()==false)
      { 
         cout << endl; 
         cout << "Your Pikachu has fully recovered before it's next battle" << endl;
         cout << endl;
         cout << "Current Room: Bruno's Gym" << endl;
         cout << "Previous Room: Lorelei's Gym" << endl;
         cout << "Next Room: Agatha's Gym" << endl;
         cout << endl;
         printMenu(); 
      } 
   }
   else
   {
      cout << "You have already defeated Bruno! You must " << endl;
      cout << "continue on if you want to be the Indigo League " << endl;
      cout << "Champion!" << endl;
   }
}



/*
* Summary: 
* Param:  
* Returns: 
*/
void BrunoGym::printMenu()
{
   int num = 0;

   cout << "-------------------------------------------" << endl; 
   cout << "1. Enter next room " << endl;  
   cout << "2. Review Items " << endl; 
   cout << "-------------------------------------------" << endl; 
   cout << endl;
   cout << "Choose a 1 or 2." << endl;
   num = integerInputVal(1,2); 

   if(num == 1)
   {
      Game G1; 
      G1.moveSpaces(1,3); 
   }
   if(num == 2)
   {
      printInventory(); 
   }
 
}


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
#include "LanceGym.hpp" //include all header files
#include "Game.hpp" 

using std::cout;
using std::endl;
using std::cin;

/*
* Summary: 
* Param:  
* Returns: 
*/
void LanceGym::printDialogue()
{
   Game G1;   

   cout << "           " << getGymName() << endl;

   if(lanceGymFlag == false)
   {
      cout << "-------------------------------------------------" << endl;
      cout << "Ash, It's fantastic to see you again my friend." << endl;
      cout << "You have come a long way. You must be an amazing trainer!" 
           << endl;
      cout << "I look forward to the opportunity to battle you!" << endl;
      cout << "-------------------------------------------------" << endl;
      cout << endl;
      G1.oneRound(getGymLeader(),getPokemon());
      cout << endl; 
      G1.showHealth(); 
      if(G1.getStatus()==false)//receive key if user does not faint
      { 
         cout << endl;
         cout << "Ash! I knew you were a brilliant trainer!" << endl; 
         cout << "Here, take this, Ash. You deserve it!" << endl; 
         cout << endl; 
         cout << "Ash received: Golden Key!" << endl; 
         cout << "You will need that key to open the Champion Chamber" << endl;
         cout << endl;  
         cout << "Farewell Ash!" << endl;
         cout << endl;  
         inventory.push_back("Golden Key"); 
         cout << "Your Pikachu has fully recovered before it's next battle" << endl;
         cout << endl;  
         cout << "Current Room: Lance's Gym" << endl;
         cout << "Previous Room: Agatha's Gym" << endl;
         cout << "Next Room: Champion Chamber" << endl;
         cout << endl;
         printMenu(); 
      } 
   }
   else
   {
      cout << "You have already defeated Lance! You must " << endl;
      cout << "continue on if you want to be the Indigo League " << endl;
      cout << "Champion!" << endl;
   }
}



/*
* Summary: 
* Param:  
* Returns: 
*/
void LanceGym::printMenu()
{
   int num = 0;
   cout << endl; 
   cout << "-------------------------------------------" << endl; 
   cout << "1. Enter next room " << endl; 
   //cout << "2. Enter previous room " << endl; 
   cout << "2. Review Items " << endl; 
   cout << "-------------------------------------------" << endl; 
   cout << endl;
   cout << "Choose a 1 or 2." << endl;
   num = integerInputVal(1,2); 

   //get inventory or move space
   if(num == 1)
   {
      cout << endl; 
      cout << "The door is locked." << endl; 
      cout << "Maybe you should use the Golden Key!" << endl; 
      printMenu(); 
   }
   if(num == 2)
   {
      printInventory(); 
   }
}


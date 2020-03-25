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
#include "IndigoPlateau.hpp" //include all header files
#include "Game.hpp" 

using std::cout;
using std::endl;
using std::cin;

/*
* Summary: prints and actions for this space 
* Param: 
* Returns: 
*/
void IndigoPlateau::printDialogue()
{
   Game G1;

   cout << "           " << getGymName() << endl; 

   //print dialogue
   if(indigoPlateauFlag == false)
   {
      cout << "-------------------------------------------------" << endl; 
      cout << "Ash!!" << endl; 
      cout << endl; 
      cout << "Welcome to the Indigo Plateau!" << endl; 
      cout << "I assume you are here to battle the Elite Four?" << endl;
      cout << endl;  
      cout << "These trainers are tough to beat. I hope you are " << endl; 
      cout << "ready to face them." << endl; 
      cout << endl; 
      cout << "The first gym leader is right through that door." << endl; 
      cout << "Enter when you are ready! " << endl;
      cout << "-------------------------------------------------" << endl;
      cout << endl;
      G1.showHealth(); //show pikachu health
      cout << endl; 
      cout << "Current Room: Indigo Plateau" << endl; 
      cout << "Next Room: Lorelei's Gym" << endl; 
      cout << endl;         
      printMenu();  
   } 
   else 
   { 
      cout << "-------------------------------------------------" << endl; 
      cout << "You have already visited this room! You must " << endl;  
      cout << "continue on if you want to be the Indigo League " << endl; 
      cout << "Champion!" << endl; 
      cout << "-------------------------------------------------" << endl;
      cout << endl; 
      G1.showHealth(); 
      cout << endl; 
      printMenu();  
   } 
}


 
/*
* Summary: prints menu for this space
* Param: 
* Returns: 
*/
void IndigoPlateau::printMenu()
{ 
   int num = 0; 
 
   cout << "    Options" << endl; 
   cout << endl; 
   cout << "-------------------------------------------" << endl; 
   cout << "1. Enter next room " << endl; 
   cout << "2. Review Items " << endl; 
   cout << "-------------------------------------------" << endl; 
   cout << endl; 
   cout << "Choose a 1 or a 2." << endl; 
   num = integerInputVal(1,2); 
   //moves user or prints inventory
   if(num == 1)
   { 
      Game G1; 
      G1.moveSpaces(1,1); 
          
   }    
   if(num == 2) 
   { 
      printInventory(); 
   } 
 
} 

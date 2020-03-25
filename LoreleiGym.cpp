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
#include "LoreleiGym.hpp" //include all header files
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
void LoreleiGym::printDialogue()
{
   Game G1;    

   cout << "           " << getGymName() << endl;

   if(loreleiGymFlag == false)
   {
      cout << "-------------------------------------------------" << endl;
      cout << "Hello Ash, I have been expecting you." << endl; 
      cout << "My name is Lorelei, and I think Ice Pokemon are cool!" << endl; 
      cout << "Get ready to be frozen in fear!!" << endl; 
      cout << "-------------------------------------------------" << endl;
      cout << endl;
      G1.oneRound(getGymLeader(),getPokemon());//user battles Lorelei 
      cout << endl;  
      G1.showHealth(); 
      if(G1.getStatus()==false)//if user faints, game ends
      {
         cout << endl; 
         cout << "Your Pikachu has fully recovered before it's next battle" << endl; 
         cout << endl; 
         cout << "Current Room: Lorelei's Gym" << endl; 
         cout << "Previous Room: Indigo Plateau" << endl; 
         cout << "Next Room: Bruno's Gym" << endl; 
         cout << endl; 
         printMenu(); 
      } 
   }
   else
   {
      cout << "-------------------------------------------------" << endl;
      cout << "You have already defeated Lorelei! You must " << endl;
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
* Summary: 
* Param: 
* Returns: 
*/
void LoreleiGym::printMenu()
{
   int num = 0;
   
   cout << "     Options" << endl; 
   cout << endl; 
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
      G1.moveSpaces(1,2); 
   }
   if(num == 2)
   {
      printInventory(); 
   } 
}


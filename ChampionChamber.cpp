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
#include "ChampionChamber.hpp" //include all header files
#include "Game.hpp" 

using std::cout;
using std::endl;
using std::cin;

/*
* Summary: 
* Param: 
* Returns: 
*/
void ChampionChamber::printDialogue()
{
   Game G1;  
  
   cout << "           " << getGymName() << endl;

   cout << "-------------------------------------------------" << endl;
   cout << "Your rival, Goofy Garry, took an arrow to the knee while " << endl; 
   cout << "making his journey to the Indigo Plateau. He has since " << endl; 
   cout << "retired from his career as a pokemon trainer. You are " << endl; 
   cout << "the Indigo League Champion!!!" << endl;
   cout << "-------------------------------------------------" << endl; 
   cout << endl; 
   cout << "You Win!" << endl; 
}

void ChampionChamber::printMenu()
{

}

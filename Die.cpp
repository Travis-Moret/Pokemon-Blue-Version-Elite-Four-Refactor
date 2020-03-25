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
#include "Die.hpp"
#include "Space.hpp"
#include "IndigoPlateau.hpp"
#include "LoreleiGym.hpp"
#include "BrunoGym.hpp"
#include "AgathaGym.hpp"
#include "LanceGym.hpp"
#include "ChampionChamber.hpp"
#include "Pokemon.hpp"
#include "Pikachu.hpp"
#include "Lapras.hpp"
#include "Machamp.hpp"
#include "Gengar.hpp"
#include "Dragonite.hpp"


using std::cout;
using std::endl;
using std::cin;

/*
* Summary: constructor 
* Param: sides
* Returns: nothing
*/
Die::Die(int sidesIn)
{ 
   rollValue = 0; 
   sides = sidesIn; 
}


 
/*
* Summary: deconstructor
* Param: none
* Returns: nothing
*/
Die::~Die()
{ 
} 



/*
* Summary: rolls a random number up to the number of sides
* Param: none
* Returns: value of dice rolled
*/
int Die::dieRoll()
{ 
   rollValue = rand()% sides +1; 
   
   return rollValue; 
}  












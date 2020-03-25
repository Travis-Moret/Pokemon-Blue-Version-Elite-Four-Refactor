/**************************************************************************
** Project Name: Fantasy Game
** Author: Travis Moret
** Date: 11/3/2019
** Description: This program is a fantasy combat game simulation, in which
                the user can choose from 5 different characters with
                special abilities. The characters simulate combat, and the
                result of each round is displayed, and the winner of each
                duel. Users can then play again or quit.
**************************************************************************/

#include <iostream>
#include <string> 
#include "Space.hpp" //included all header files
#include "Die.hpp"
#include "Pokemon.hpp"
#include "Pikachu.hpp"
#include "Machamp.hpp"
#include "Lapras.hpp"
#include "Gengar.hpp"
#include "Dragonite.hpp"


using std::cout;
using std::endl;
using std::cin;
using std::string; 

/*
* Summary: constructor 
* Param: name, armor, strengthpoints and lives inherited from Pokemon
* Returns: nothing
*/
Lapras::Lapras() : Pokemon("Lapras",1,28,20,1)//set from Pokemon
{  
   //set dice values for attack and defense
   attackerRoll.diceCount = 1;
   attackerRoll.diceSides = 12;
   defenderRoll.diceCount = 1;
   defenderRoll.diceSides = 12;

   //place attack and defense dice in arrays
   attackerDice = new Die *[attackerRoll.diceCount];

   for(int i=0; i < attackerRoll.diceCount; i++)
   {
      attackerDice[i] = new Die(attackerRoll.diceSides);
   }

   defenderDice = new Die *[defenderRoll.diceCount];

   for(int i=0; i < defenderRoll.diceCount; i++)
   {
      defenderDice[i] = new Die(defenderRoll.diceSides);
   }
}



/*
* Summary: destructor
* Param: none
* Returns: nothing
*/
Lapras::~Lapras()
{
   //delete the dynamically allocated arrays 
   for(int i=0; i<attackerRoll.diceCount; i++)
   {
      delete attackerDice[i];
   }
   delete [] attackerDice;

   for(int i=0; i<defenderRoll.diceCount; i++)
   {
      delete defenderDice[i];
   }
   delete [] defenderDice;
}



/*
* Summary: one attack turn for the vampire
* Param: defender vampire is attacking
* Returns: totalAttack
*/
int Lapras::attackMove(Pokemon *defender)
{
   int count = 1;
   int totalAttack = 0;
   int rollValue = 0;

   //Show attacker and defender stats
   cout << "Attacker type: " << getName() << endl;
   cout << "Defender type: " << defender->getName() << endl;
   cout << endl;

   cout << "Defender stats: " << endl;
   cout << "Armor: " << defender->getArmor() << endl;
   cout << "Strength Points: " << defender->getStrength() << endl;
   cout << endl; 

   //dice rolls for attacker
   cout << getName() << "'s attack dice roll:" << endl;

   for(int i=0; i<attackerRoll.diceCount; i++)
   {
      rollValue = attackerDice[i]->dieRoll();
      totalAttack += rollValue;

      cout << "Roll " << count << ": " << rollValue << endl;
      count++;
   }

   //show total attack stat
   cout << endl; 
   cout << getName() << "'s total attack is: " << totalAttack << endl;

   return totalAttack;
}



/*
* Summary: one defense move for vampire
* Param: attack of the attacker
* Returns: nothing
*/
void Lapras::defendMove(int attack)
{
   int count = 1;
   int totalDefense = 0;
   int rollValue = 0;
   int totalDamage = 0;
   int remainingStrength = 0;
   int charm = 0; 
   
   //initiate charm for 50%
   charm = rand()%4; 
      
   //if charmed, attacker does no damage
   if(charm == 1) 
   {  
      cout << endl;  
      cout << getName() << "Froze it's opponent! It's opponent " << 
              "did not attack!" << endl; 
      cout << "No damage was inflicted." << endl;
      cout << endl;  
   }    
   //if not charmed, roll defense die and calculate damage
   else
   { 
      cout << endl; 
      cout << getName() << "'s defense Dice roll: " << endl;

      //roll defense dice
      for(int i=0; i<defenderRoll.diceCount; i++)
      {
         rollValue = defenderDice[i]->dieRoll();
         totalDefense += rollValue;

         cout << "Roll " << count << ": " << rollValue << endl;
         count++;
      }
   
      //show vampire's defense stat
      cout << endl; 
      cout << getName() << "'s total defense is: " << totalDefense << endl;
      cout << endl; 

      //calculate total damage
      totalDamage = (attack - totalDefense - getArmor()); 
   
      //negative number dmage reset to 0
      if(totalDamage <= 0)
      { 
      totalDamage = 0; 
      } 

      //subtract damage from strength and set new strength
      remainingStrength = getStrength() - totalDamage;
      setStrength(remainingStrength);

      //show total damage
      cout << "Total damage: " << totalDamage << endl;
      cout << endl;
    }
   
   //show remaining strength points
   cout << getName() << "'s remaining strength points: " <<
        getStrength() << endl;
   cout << endl;
}
 


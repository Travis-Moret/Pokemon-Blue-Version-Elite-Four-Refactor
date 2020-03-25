/**************************************************************************
** Program Name: Final Project
** Author: Travis Moret
** Date: 12/7/2019
** Descrpition: In this program, Ash must battle the elite four to become
                the Indigo League Champion. Ash's Level 80 Pikachu must
                defeat each Gym Leaders' pokemon to advance to the next
                gym. If Ash's Pikachu faints, the game ends. If Ash defeats
                each gym leader, he will attain the golden key to unlock
                the Champion's Chamber.
**************************************************************************/

#ifndef POKEMON_H // include guards
#define POKEMON_H

#include <string> 
#include "Die.hpp" //include die for access for child classes

using std::string; 

//struct to keep track of information for each characters dice
struct playerRoll
{ 
   int diceCount; 
   int diceSides; 
};  

//base class
class Pokemon 
{ 
   protected:
      string userName; 
      string name;//variables to have in all child classes  
      int attack; 
      int defense; 
      int armor; 
      int strengthPoints;
      int maxStrengthPoints; 
      int lives; 
      bool isDead;  
      playerRoll attackerRoll; //struct objects for attacker and defender
      playerRoll defenderRoll;
      Die **attackerDice; //arrays for the attack and defense dice
      Die **defenderDice;  
      
   public:
      Pokemon();  
      Pokemon(string,int,int,int,int); //copy constructor 
      virtual ~Pokemon(); //each child's destructor will be different
      virtual int attackMove(Pokemon *)=0; //abstracted for child classes
      virtual void defendMove(int)=0; 
      //void pikachuDefense(int,int&);  
      virtual void setStrength(int); //special cases for Harry and BlueMen
      int getArmor(); //getters needed for game sequence
      int getStrength();
      int getMaxStrength();  
      playerRoll getAttack(); 
      playerRoll getDefense(); 
      string getName();
      string getUserName(); 
      void setUserName(string); //set the user input name 
      bool isAlive();//determine if characters have died
      virtual void recover();   
}; 
#endif


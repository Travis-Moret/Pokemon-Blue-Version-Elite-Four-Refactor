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

#ifndef SPACE_H // include guards
#define SPACE_H

#include <string>
#include <vector>  
#include "Pokemon.hpp" 


using std::string; 
using std::vector;
 
class Space
{ 

   protected: 
      vector<string> inventory; // container for inventory 
      string trainerName; //gym information
      string gymLeader;
      string gymName; 
      Space *currentSpace;  
      Pokemon *defender; //pokemon defending the gym   
      bool indigoPlateauFlag; //has each gym been defeated
      bool loreleiGymFlag; 
      bool brunoGymFlag;
      bool agathaGymFlag;  
      bool lanceGymFlag;     
   public:
      Space(); 
      ~Space(); 
      void instructions();
      virtual void printDialogue()=0;  //virtual functions
      virtual void printMenu()=0; 
      void printInventory(); 
      string getTrainerName();
      string getGymLeader(); 
      string getGymName();
      Pokemon * getPokemon();
      int integerInputVal(int,int); 
      void setGymLeader(string); 
      void setGymName(string);   
      void setDefender(Pokemon *);    
}; 
#endif


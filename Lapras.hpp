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

#ifndef LAPRAS_H // include guards
#define LAPRAS_H

#include "Pokemon.hpp" 

//child class of Pokemon
class Lapras: public Pokemon
{ 
   private:

   public: 
      Lapras(); //functions to be overwritten
      ~Lapras(); 
      int attackMove(Pokemon *); 
      void defendMove(int); 
}; 
#endif


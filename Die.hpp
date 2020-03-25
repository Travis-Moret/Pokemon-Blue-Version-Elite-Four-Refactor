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

#ifndef DIE_H // include guards
#define DIE_H

class Die
{
   private: 
      int rollValue; //returned from dieRoll
      int sides; //for struct in Menu

   public: 
      Die(int); 
      ~Die(); 
      int dieRoll(); 

}; 
#endif


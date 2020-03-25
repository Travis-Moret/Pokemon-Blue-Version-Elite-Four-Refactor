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

#ifndef GAME_H // include guards
#define GAME_H

#include "Pokemon.hpp"
#include "Space.hpp"
#include "IndigoPlateau.hpp"
#include "LoreleiGym.hpp"
#include "BrunoGym.hpp"
#include "AgathaGym.hpp"
#include "LanceGym.hpp"
#include "ChampionChamber.hpp"

class Game
{ 
   private:
      int round;  
      bool hasFainted; 
      Space *indigoPlateau;//pointer for each space 
      Space *loreleiGym; 
      Space *brunoGym; 
      Space *agathaGym; 
      Space *lanceGym; 
      Space *championChamber;
      Space *currentSpace;  
      Pokemon *player; //pointer for players pokemon

   public: 
      Game(); 
      ~Game();
      bool getStatus(); //is pikachu fainted
      void gameOver(); //if pikachu faints
      void instructions(); //game instructions
      void setupTrain(); //sets up board
      void destroyTrain(); //deletes board
      void oneRound(string,Pokemon *);  //pokemon battle
      void showHealth(); //show pikachu health
      void setupGyms(); //fill gyms
      void moveSpaces(int,int); //move from one space to next
      void changeCurrentSpace(Space *&); //change currentspace   
}; 
#endif


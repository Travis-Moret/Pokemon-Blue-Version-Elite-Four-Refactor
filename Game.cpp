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
#include "Game.hpp" //include all header files
#include "Pokemon.hpp" 
#include "Pikachu.hpp" 
#include "Lapras.hpp"
#include "Machamp.hpp"
#include "Gengar.hpp" 
#include "Dragonite.hpp"
#include "Space.hpp"
#include "IndigoPlateau.hpp"
#include "LoreleiGym.hpp"
#include "BrunoGym.hpp"
#include "AgathaGym.hpp"
#include "LanceGym.hpp"
#include "ChampionChamber.hpp"

using std::cout;
using std::endl;
using std::cin;

/*
* Summary: constructor
* Param: none
* Returns: nothing
*/
Game::Game()
{
   //initialize data members
   round = 1; 
   hasFainted = false; 
   player = nullptr;  
   player = new Pikachu;  
   setupTrain(); 
   setupGyms(); 
}



/*
* Summary: destructor
* Param: none
* Returns: nothing
*/
Game::~Game()
{
   //free pointers
   delete player;
   destroyTrain();  
}



/*
* Summary: gives instructions
* Param: none
* Returns: nothing
*/
void Game::instructions()
{
   //provide the user with instructions
   cout << "                Instructions" << endl;
   cout << endl;
   cout << "       Welcome to the world of Pokemon!" << endl;
   cout << endl;
   cout << "In this game, you and your level 100 Pikachu must " << endl;
   cout << "defeat the Elite Four to become the Indigo League " << endl;
   cout << "champions! Your Pikachu must defeat each of the 4 " << endl;
   cout << "without fainting, or you will have to start over." << endl;
   cout << "Your Pikachu will rest and heal after each battle. " << endl;
   cout << "After defeating the 4th Gym Leader, you receive the " << endl;
   cout << "golden key, needed to open the Champion's Chamber." << endl;
   cout << "If you become the Indigo League Champion, you win!" << endl;
   cout << endl; 
   cout << endl; 
   moveSpaces(0,0);//put user on initial space  
}

/*
* Summary: initiates battle sequence for pokemon
* Param: gym leader name and pokemon in
* Returns: nothing
*/
void Game::oneRound(string gymLeaderIn,Pokemon *pokemonIn)
{ 

   int totalAttack = 0;

   cout << "Round " << round << endl;
   cout << endl;

   //initiate player 1's attack sequaence
   cout << "Ash's " << player->getName() << " attacks!" << endl;
   cout << endl;

   //calculate total attack
   totalAttack = player->attackMove(pokemonIn);
   cout << endl;

   //initiate player 2's defense sequence
   cout << gymLeaderIn << "'s " << pokemonIn->getName() << " defends!" << endl;

   pokemonIn->defendMove(totalAttack);

   //determine if player 2 is alive. If so, player 2 attacks
   if (pokemonIn->isAlive())
   {
      //player 2's attack sequence
      cout << gymLeaderIn << "'s " << pokemonIn->getName() << " attacks!" << endl;
      cout << endl;

      totalAttack = pokemonIn->attackMove(player);

      //player 1's defense sequence
      cout << endl;
      cout << "Ash's" << player->getName() << " defends!" << endl;
      
      int currentStrength = 0; 
      currentStrength = player->getStrength(); 
  
      player->defendMove(totalAttack);

      //check if player 1 is still alive. Show if a player has dies and
      //end game. If both players survived, continue rounds
      if(player->isAlive())
      {
         round++;
         cout << "Both players still stand. Commence round " <<
              round << "." << endl;
         cout << endl;
         oneRound(gymLeaderIn,pokemonIn);
      }
      else
      {
         cout << "Ash's " << player->getName() <<
                 " has fainted." << endl;
         cout << endl;
         round=1;
         hasFainted = true; 
         gameOver(); 
      }
    }
    else
    {
       cout << gymLeaderIn << "'s " << pokemonIn->getName() <<
               " has fainted. You have beat " << gymLeaderIn << "!"<< endl;
       cout << endl;
       round=1;
    }
}


//displays if Pikachu faints
void Game::gameOver()
{ 
   cout << "Your Pikachu may need some more training." << endl; 
   cout << "Come back and battle when you are ready!" << endl; 
} 


//gets pikachu's status
bool Game::getStatus()
{ 
   return hasFainted; 
} 


/*
* Summary: moves the user a space
* Param: users choice of move, count
* Returns: nothing
*/
void Game::moveSpaces(int choiceIn,int count)
{     
   //determine the user's choice and move space accordingly
   if(count == 0) 
   { 
      if(choiceIn == 0)
      {
         currentSpace->printDialogue();
      }
   } 
   else if(count == 1)
   { 
      if(choiceIn == 1)
      {   
         loreleiGym->printDialogue(); 
      } 
   } 
   else if (count == 2) 
   { 
        if(choiceIn == 1)
      {
         brunoGym->printDialogue(); 
      }
   } 
   else if(count == 3)
   { 
       if(choiceIn == 1)
      {
         agathaGym->printDialogue();
      }
   } 
   else if(count == 4)
   { 
        if(choiceIn == 1)
      {
         lanceGym->printDialogue();
      }
   } 
   else if(count ==5)
   { 
       if(choiceIn == 1)
      {
         championChamber->printDialogue();
      }
   }  
    
}



/*
* Summary: set up the game board
* Param: none
* Returns: nothing
*/
void Game::setupTrain()
{

   //assign each gym pointer its object
   indigoPlateau = new IndigoPlateau; 
   loreleiGym = new LoreleiGym; 
   brunoGym = new BrunoGym; 
   agathaGym = new AgathaGym; 
   lanceGym = new LanceGym; 
   championChamber = new ChampionChamber; 

   //set the user's current space
   currentSpace = indigoPlateau; 
}



/*
* Summary: frees each pointer
* Param: none
* Returns: nothing
*/
void Game::destroyTrain()
{

   delete indigoPlateau; 
   delete loreleiGym; 
   delete brunoGym; 
   delete agathaGym; 
   delete lanceGym; 
   delete championChamber; 

} 



/*
* Summary: show Pikachu's health
* Param: none
* Returns: nothing
*/
void Game::showHealth()
{
   cout << "-------------------------------------" << endl; 
   cout << "| Pikachu HP: " << player->getStrength() << " / " << 
                               player->getMaxStrength() << " |" << endl; 
   cout << "-------------------------------------" << endl; 
} 



/*
* Summary: fills each gym with a leader, name and pokemon
* Param: none
* Returns: nothing
*/
void Game::setupGyms()
{ 
   //set a name, leader and pokemon for each space as needed
   indigoPlateau->setGymName("Indigo Plateau");  

   loreleiGym->setGymLeader("Lorelei"); 
   loreleiGym->setGymName("Lorelei's Gym"); 
   loreleiGym->setDefender(new Lapras);

   brunoGym->setGymLeader("Bruno"); 
   brunoGym->setGymName("Bruno's Gym"); 
   brunoGym->setDefender(new Machamp); 

   agathaGym->setGymLeader("Agatha"); 
   agathaGym->setGymName("Agatha's Gym"); 
   agathaGym->setDefender(new Gengar); 
   
   lanceGym->setGymLeader("Lance"); 
   lanceGym->setGymName("Lance's Gym"); 
   lanceGym->setDefender(new Dragonite); 

   championChamber->setGymName("Champion Chamber"); 
 
} 

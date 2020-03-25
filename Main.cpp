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
#include <string>
#include <ctime>// for rand and srand time 
#include <cstdlib> 
#include "Game.hpp" //included all header files
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
using std::cin;
using std::endl;
using std::string; 

int main()
{  
   //seed srand with time
   srand(time(NULL));    

   int menuChoice = 0;  

   Game G1; 
   IndigoPlateau I1; 
   do
   { 
      //print the menu after each game is completed
      cout << endl; 
      cout << "             Pokemon: The Elite 4 showdown" << endl; 
      cout << endl; 
      cout << "1. Play " << endl; 
      cout << "2. Exit " << endl; 
      cout << endl; 
      
      cout << "Please enter an option" << endl; 

      menuChoice = I1.integerInputVal(1,2); 
      cout << endl;    
        
      if (menuChoice >=1 && menuChoice <= 2)
      { 
         switch(menuChoice)
         { 
            case 1: //initiate the game
            {  
               G1.instructions();  
               break;      
            } 
            case 2: //exit the game
            { 
               cout << "Exiting the game." << endl;
               break;  
            } 
            default: 
            { 
               cout << "Exiting the game." << endl;
               break;  
            }
         }
      }  
   } while(menuChoice != 2); 

   return 0;
}


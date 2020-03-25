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
#include "Pikachu.hpp" //included all header files
#include "Die.hpp"
#include "Pokemon.hpp"
#include "Lapras.hpp"
#include "Machamp.hpp"
#include "Gengar.hpp"
#include "Dragonite.hpp"

using std::cout;
using std::endl;
using std::cin;
using std::string; 

/*
* Summary: copy constructor
* Param: name, armor, strength and lives
* Returns: nothing
*/
Pokemon::Pokemon(string nameIn,int armorIn,int strengthPointsIn,
                     int maxStrengthPointsIn,int livesIn)
{  
   name = nameIn;   
   armor = armorIn;  
   lives = livesIn;   
   strengthPoints = strengthPointsIn;
   maxStrengthPoints = maxStrengthPointsIn;
   userName = " ";   
   isDead = false;  
}



/*
* Summary: constructor
* Param: none
* Returns: nothing
*/
Pokemon::Pokemon()
{ 
   name = " " ;
   armor = 0;
   lives = 1;
   strengthPoints = 0;
   isDead = false;
}



/*
* Summary: destructor
* Param: none
* Returns: nothing
*/
Pokemon::~Pokemon()
{

}


/*
* Summary: gets armor 
* Param: none
* Returns: armor value
*/
int Pokemon::getArmor()
{ 
   return armor; 
} 



/*
* Summary: gets strength
* Param: none
* Returns: returns strength
*/
int Pokemon::getStrength()
{ 
   return strengthPoints; 
} 



/*
* Summary: gets strength
* Param: none
* Returns: returns strength
*/
int Pokemon::getMaxStrength()
{ 
   return maxStrengthPoints; 
} 



/*
* Summary: gets name of charcter
* Param: none
* Returns: returns name
*/
string Pokemon::getName()
{ 
   return name; 
}


 
/*
* Summary: gets username of charcter
* Param: none
* Returns: returns username
*/
string Pokemon::getUserName()
{ 
   return userName; 
} 



/*
* Summary: sets username of charcter
* Param: none
* Returns: nothing
*/
void Pokemon::setUserName(string userNameIn)
{ 
   userName = userNameIn; 
} 



/*
* Summary: gets the roll values of the attacker
* Param: none
* Returns: the attacker roll value for attack
*/
playerRoll Pokemon::getAttack() 
{ 
   return attackerRoll; 
} 



/*
* Summary: gets the roll values of the defender
* Param: none
* Returns: the defender roll value for defense
*/
playerRoll Pokemon::getDefense()
{ 
   return defenderRoll; 
} 



/*
* Summary: sets the strength after an attack and checks if character died
* Param: strength
* Returns: 
*/
void Pokemon::setStrength(int strengthIn)
{
   strengthPoints = strengthIn; 
   
   if(strengthPoints <=0) 
   { 
      lives--;
      
      if(lives == 0)
      {  
         cout << getName() << " has died." << endl;
         isDead = true;  
      } 
      
      else
      { 
         cout << getName() << " has lost a life. They have " << lives <<
              " remaining." << endl;
      }  
   } 
}

 

/*
* Summary: checks if character has died by returning if isDead is true
* Param: none
* Returns: isDead
*/
bool Pokemon::isAlive() 
{ 
   return !isDead; 
} 



/*
* Summary: heals the winner of the round by a randomly chosen amount
* Param: none
* Returns: nothing
*/
void Pokemon::recover()
{ 
   int currentStrength = 0; 
   currentStrength = getStrength(); 
   
   //check if character is Harry Potter and set max strength accordingly    
   int maxStrength = 0;
   if (getName() == "Harry Potter" && lives == 1) 
   { 
       maxStrength = 20; 
   } 
   else 
   { 
      maxStrength = getMaxStrength(); 
   } 
   //determind random recovery points based on max strength
   int recoveryPoints = 0; 
   recoveryPoints = rand()% maxStrength +1; 
    
   //if they fully recover, print message
   if(currentStrength + recoveryPoints >= maxStrength)
   {
      cout << getUserName() << " recovered " << recoveryPoints << 
                             " points of it's starting health!" << endl;   
      cout << getUserName() << " has recovered 100 percent of it's health" 
                          << endl;
      setStrength(maxStrength); 
      cout << getUserName() << "'s strength is now " << getStrength() 
           << endl; 
   } 
   else //if they do not fully recover, print their recovery
   {    
      cout << getUserName() << " recovered " << recoveryPoints <<
           " points of it's starting health!" << endl;
      setStrength(currentStrength + recoveryPoints); 
      cout << getUserName() << "'s strength is now " << getStrength()
           << endl; 
   }   

}

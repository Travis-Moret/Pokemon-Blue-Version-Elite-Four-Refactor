
pokemon.o: Main.o Die.o Game.o Space.o IndigoPlateau.o LoreleiGym.o BrunoGym.o AgathaGym.o LanceGym.o ChampionChamber.o Pokemon.o Pikachu.o Lapras.o Machamp.o Gengar.o Dragonite.o 
	g++ -std=c++11 Main.o Die.o Game.o Space.o IndigoPlateau.o LoreleiGym.o BrunoGym.o AgathaGym.o LanceGym.o ChampionChamber.o Pokemon.o Pikachu.o Lapras.o Machamp.o Gengar.o Dragonite.o -o pogo 

Main.o: Main.cpp
	g++ -std=c++11 -c Main.cpp

Die.o: Die.hpp Die.cpp
	g++ -std=c++11 -c Die.cpp

Game.o: Game.hpp Game.cpp
	g++ -std=c++11 -c Game.cpp

Space.o: Space.hpp Space.cpp
	g++ -std=c++11 -c Space.cpp

IndigoPlateau.o: IndigoPlateau.hpp IndigoPlateau.cpp
	g++ -std=c++11 -c IndigoPlateau.cpp

LoreleiGym.o: LoreleiGym.hpp LoreleiGym.cpp
	g++ -std=c++11 -c LoreleiGym.cpp

BrunoGym.o: BrunoGym.hpp BrunoGym.cpp
	g++ -std=c++11 -c BrunoGym.cpp

AgathaGym.o: AgathaGym.hpp AgathaGym.cpp
	g++ -std=c++11 -c AgathaGym.cpp

LanceGym.o: LanceGym.hpp LanceGym.cpp
	g++ -std=c++11 -c LanceGym.cpp

ChampionChamber.o: ChampionChamber.hpp ChampionChamber.cpp
	g++ -std=c++11 -c ChampionChamber.cpp

Pokemon.o: Pokemon.hpp Pokemon.cpp
	g++ -std=c++11 -c Pokemon.cpp

Pikachu.o: Pikachu.hpp Pikachu.cpp
	g++ -std=c++11 -c Pikachu.cpp

Lapras.o: Lapras.hpp Lapras.cpp
	g++ -std=c++11 -c Lapras.cpp

Machamp.o: Machamp.hpp Machamp.cpp
	g++ -std=c++11 -c Machamp.cpp

Gengar.o: Gengar.hpp Gengar.cpp
	g++ -std=c++11 -c Gengar.cpp

Dragonite.o: Dragonite.hpp Dragonite.cpp
	g++ -std=c++11 -c Dragonite.cpp

clean: 
	rm *.o pogo 

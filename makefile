# File Name: Makefile
# Name: Travis Moret


# Compiler
CXX = g++

# Compiler Flags
CXXFLAGS = -std=c++0x -g

# Unused flags
#CXXFLAGS += -v -O3 -pedantic-errors -Wall

# Compiler Flags passed when linking
LDFLAGS = -lboost_date_time

# Compiler flags from libraries
#LDLIBS = 

# Valgrind Options
VOPT = --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes

# Project Name
PROJ = pogo

# Zip Name
ZIP = pokemon
 
# Source Files
SRCS = Main.cpp Die.cpp Game.cpp Space.cpp IndigoPlateau.cpp LoreleiGym.cpp BrunoGym.cpp AgathaGym.cpp LanceGym.cpp ChampionChamber.cpp Pokemon.cpp Pikachu.cpp Lapras.cpp Machamp.cpp Gengar.cpp Dragonite.cpp

# Object Files (created from each source file)
OBJS = $(SRCS:.cpp=.o)

# Linking
# All header files will be brought in as dependencies
${PROJ}: ${OBJS} 
	${CXX} ${LDFLAGS} ${OBJS} -o ${PROJ}

${OBJS}: ${SRCS}  
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)


# Names of tags that aren't files. 
# Program would not run otherwise if a file by one of these names existed
.PHONY: default debug clean zip

# Commands that can be given after "make" 

# Invoke to clean the files to start from scratch
clean:
	rm -f ${PROJ} ${OBJS}

# Invoke to zip all files up or update zipped files
zip: 
	zip $(ZIP).zip *.cpp *.hpp makefile

# Invoke to run valgrind debugging
debug: $(PROJ)
	@valgrind $(VOPT) ./$(PROJ)

default: clean $(PROJ) debug

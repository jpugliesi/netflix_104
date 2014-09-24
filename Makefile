Sources= main.cpp Movie.cpp
Executable=project
MainObject=main.o

CFlags= -g -c
LDFlags=
ObjectDir=obj/
SourceDir=src/
BinDir=bin/

CC=g++
RM=rm

#!!!!!DO NOT EDIT ANYTHING UNDER THIS LINE!!!!!
Objects := $(Sources:.cpp=.o)
CSources=$(addprefix $(SourceDir),$(Sources))
CObjects=$(addprefix $(ObjectDir),$(Objects))
CExecutable=$(addprefix $(BinDir),$(Executable))

all: $(CSources) $(CExecutable)

$(CExecutable): $(CObjects) $(BinDir)
	$(CC) $(LDFlags) $(ObjectDir)$(MainObject) -o $@

$(ObjectDir)%.o: $(SourceDir)%.cpp $(ObjectDir)
	$(CC) $(CFlags) $< -o $@

$(ObjectDir):
	mkdir obj

$(BinDir):
	mkdir bin

.PHONY: clean
clean:
	rm -rf $(ObjectDir) $(BinDir)

Sources= test.cpp Movie.cpp User.cpp
Executable=project
TExecutable=test
TestObject=test.o
MainObject=main.o

CFlags= -g -c
LDFlags=
ObjectDir=obj/
SourceDir=src/
BinDir=bin/

CC=g++
RM=rm

Objects := $(Sources:.cpp=.o)
CSources=$(addprefix $(SourceDir),$(Sources))
CObjects=$(addprefix $(ObjectDir),$(Objects))
MainExecutable=$(addprefix $(BinDir),$(Executable))
TestExecutable=$(addprefix $(BinDir),$(TExecutable))

all: $(CSources) $(MainExecutable) $(TestExecutable)

#This should be changed to link the $(MainObject) Basically useless until the movie app is implemented
$(MainExecutable): $(CObjects) $(BinDir)
	$(CC) $(LDFlags) $(ObjectDir)$(TestObject) -o $@

$(TestExecutable): $(CObjects) $(BinDir)
	$(CC) $(LDFlags) $(ObjectDir)$(TestObject) -o $@


$(ObjectDir)%.o: $(SourceDir)%.cpp $(ObjectDir)
	$(CC) $(CFlags) $< -o $@

$(ObjectDir):
	mkdir obj

$(BinDir):
	mkdir bin

.PHONY: clean
clean:
	rm -rf $(ObjectDir) $(BinDir)

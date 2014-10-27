Sources= test.cpp Movie.cpp User.cpp
Main=main.cpp
Executable=project
TExecutable=test
TestObject=test.o
MainObject=main.o
Headers=**/*.h

CFlags= -g -c
GTEST_CPPFLAGS = -Wall -g -I$(LibDir) -Wextra -pthread -std=gnu++0x
LDFlags=
ObjectDir=obj/
LibDir=lib/
BinDir=bin/
TestDir = test/

# Test Cases
_TEST_CASES=$(patsubst $(TestDir)%,$(ObjectDir)%,$(wildcard $(TestDir)*.cpp))
TEST_CASES=$(patsubst %.cpp,%.test.o,$(_TEST_CASES))

CC=g++
RM=rm

Objects := $(Sources:.cpp=.o)
CSources=$(addprefix $(LibDir),$(Sources))
CObjects=$(addprefix $(ObjectDir),$(Objects))
MainExecutable=$(addprefix $(BinDir),$(Executable))
TestExecutable=$(addprefix $(BinDir),$(TExecutable))

all: $(CSources) $(MainExecutable) $(TestExecutable)

#This should be changed to link the $(MainObject) Basically useless until the movie app is implemented
$(MainExecutable): $(CObjects) $(BinDir)
	$(CC) $(LDFlags) $(ObjectDir)$(MainObject) -o $@

$(TestExecutable): $(CObjects) $(BinDir)
	$(CC) $(LDFlags) $(ObjectDir)$(TestObject) -o $@


$(ObjectDir)%.o: $(LibDir)%.cpp $(Headers) $(ObjectDir) $(MainObject) 
	$(CC) $(CFlags) $< -o $@
	
$(MainObject): $(Main)
	$(CC) $(CFlags) $(Main) -o $(ObjectDir)$(MainObject)

$(ObjectDir):
	mkdir obj

$(BinDir):
	mkdir bin

# Rules for compiling and running all test cases in 'test folder'
$(ObjectDir)%.test.o: $(TestDir)%.cpp $(LibDir)* $(BinDir).dirstamp
	$(CC) $(GTEST_CPPFLAGS) $(GTEST_LL) -c $< -o $@

$(BinDir)MergeSortTests: $(TEST_CASES) $(LibDir)
	$(CC) $(GTEST_CPPFLAGS) $(ObjectDir)$^ $(GTEST_LL) -o $@

# Rule to ensure the $(BinDir) directory exist or it'll create it.
$(BinDir).dirstamp:
	-@mkdir -p $(BinDir) && touch $@

.PHONY: clean
.PHONY: tests

tests: $(BinDir)MergeSortTests
	-@$(BinDir)MergeSortTests
	-@echo "--- All Tested!---"

clean:
	rm -rf $(ObjectDir) $(BinDir)

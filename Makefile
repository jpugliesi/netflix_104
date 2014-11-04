# Detecting OS
UNAME_S=$(shell uname -s)
ifeq ($(UNAME_S),Linux)
    CC=g++-4.8
    GTEST_LL=-I /usr/local/opt/gtest/include/ -lgtest_main -lpthread
else
    ifeq ($(UNAME_S),Darwin)
        CC=g++
        GTEST_LL=-I /usr/local/opt/gtest/include/ -L /usr/local/opt/gtest/lib/ -lgtest_main -lgtest -lpthread
    else
        CC=g++
        GTEST_LL=-I /usr/local/opt/gtest/include/ -L /usr/local/lib/ -lgtest_main -lgtest -lpthread
    endif
endif

Sources=Movie.cpp User.cpp test.cpp
Main=main.cpp
Executable=project
TExecutable=test
TestObject=test.o
MainObject=main.o
Headers=**/*.h

CFlags= -g -c -Ilib/
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

Netflix = Netflix.o

all: $(MainExecutable) $(TestExecutable) $(CSources)

#This should be changed to link the $(MainObject) Basically useless until the movie app is implemented
$(MainExecutable): $(CObjects) $(BinDir) $(Netflix) $(MainObject)
	$(CC) $(LDFlags) $(ObjectDir)$(MainObject) obj/Netflix.o obj/Movie.o obj/User.o -o $@

$(TestExecutable): $(CObjects) $(BinDir)
	$(CC) $(LDFlags) $(ObjectDir)$(TestObject) -o $@


$(ObjectDir)%.o: $(LibDir)%.cpp $(ObjectDir) 
	$(CC) $(CFlags) $< -o $@
	
$(MainObject):
	$(CC) $(CFlags) $(Main) -o $(ObjectDir)$(MainObject)

$(Netflix): $(CObjects)
	$(CC) $(CFlags) lib/Netflix.cpp -o obj/Netflix.o

$(ObjectDir):
	mkdir obj

$(BinDir):
	mkdir bin

# Rules for compiling and running all test cases in 'test folder'
$(ObjectDir)%.test.o: $(TestDir)%.cpp $(LibDir)* $(BinDir).dirstamp
	$(CC) $(GTEST_CPPFLAGS) $(GTEST_LL) -c $< -o $@

$(BinDir)MergeSortTests: $(TEST_CASES) $(LibDir)
	$(CC) $(GTEST_CPPFLAGS) $(TEST_CASES) $(GTEST_LL) -o $@

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

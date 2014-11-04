#include "./lib/Netflix.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

/*** Global file variable names ***/

int main(int argc, char ** argv){

  Netflix netflix;
  //Check if user provides us with the main data file
  if (argc < 2){
    std::cout << "USAGE: " << argv[0] << " <MAIN_DATA_FILE>" << std::endl;
    return 1;
  }

  std::string input_file = argv[1];

  if(netflix.initializeData(input_file)){
  
    //The files were read properly.
    //Launch the interactive experience
    int choice;
    do{
      choice = 3;
      choice = netflix.getMenuInput();
      
      switch(choice){

        case 1: if(netflix.loginUser()){
                  //movie prompts
                  int choice;
                  do{
                    choice = netflix.getMovieInput();
                    
                    switch(choice){

                      case 1: netflix.searchMoviesPrompt();
                              break;
                      case 2: netflix.searchMoviesByKewordPrompt();
                              break;
                      case 3: //return current movie
                              netflix.getCurrentUser()->returnMovie();
                              break;
                      case 4: //View Queue
                              netflix.modifyQueuePrompt();
                              break;
                      case 5: break;
                      default: break;
                      
                    }
                
                  } while(choice != 5);
                  
                }
                break;
        case 2: std::cout << "Creating a new user" << std::endl;
                netflix.createNewUser();
                break;
        case 3: break;
        default: break;
        
      }
  
    } while(choice != 3);
    
  }

  return 0;

}



#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "lib/Set.h"
#include "lib/Map.h"
#include "lib/Movie.cpp"
#include "lib/User.cpp"
#include "lib/NoSuchElementException.h"

int main(int argc, char ** argv){

  //Check if user provides us with the main data file
  if (argc < 2){
    std::cout << "USAGE: " << argv[0] << " <MAIN_DATA_FILE>" << std::endl;
    return 1;
  }

  //Important Variables
  
  // A Map of all of the application's users
  //  It will be filled on each run of the program, by reading through the appropriate 
  //  users data file
  Map<std::string, User*> users;
  
  // A Map of all of the application's movies
  //  It will be filled on each run of the program, by reading through the appropriate 
  //  users data file
  Map<std::string, Movie*> movies;

  // Keywords for all movies in the application
  Map<std::string, Set<Movie*> > movies_by_keyword;

  

  
  /*if(initialize()){
    
  }*/
  
  return 0;

}

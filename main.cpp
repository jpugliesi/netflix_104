#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "lib/Set.h"
#include "lib/Map.h"
#include "lib/Movie.cpp"
#include "lib/User.cpp"
#include "lib/NoSuchElementException.h"

bool initializeData(std::string input_file, 
                    Map<std::string, User*> & users, 
                    Map<std::string, Movie*> & movies, 
                    Map<std::string, Set<Movie*> > & movies_by_keyword);

bool initializeUserData(std::string user_data_file, Map<std::string, User*> & users);

bool initializeMovieData(std::string movie_data_file, 
                         Map<std::string, Movie*> & movies, 
                        Map<std::string, Set<Movie*> > & movies_by_keyword);

bool tokenizeLine(std::string line, std::vector<std::string> & words);
bool parseCommand(std::string line, std::string & command, std::string & parameter);

bool loginUser(Map<std::string, User*> & users);
void createNewUser(Map<std::string, User*> & users);
void addNewUser(Map<std::string, User*> & users, std::string username);

int getMenuInput();
int getInput();

/*** Global file variable names ***/

std::string _user_data_file;      
std::string _movie_data_file;

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

  std::string input_file = argv[1];

  if(initializeData(input_file, users, movies, movies_by_keyword)){
  
    //The files were read properly.
    //Launch the interactive experience
    int choice;
    do{
      choice = getMenuInput();
      
      switch(choice){

        case 1: std::cout << "Logging In" << std::endl;
                if(loginUser(users)){
                  //movie prompts
                }
                break;
        case 2: std::cout << "Creating a new user" << std::endl;
                createNewUser(users);
                break;
        case 3: break;
        default: break;
        
      }
  
    } while(choice != 3);
    
  }
  
  /******* clean up! *******/
  //delete all of the allocated User objects
  try{
    users.first();
    while(true){
      delete users.getCurrentValue();
      users.next();
    }

  } catch (NoSuchElementException &e){
    //went through all elements
  }

  //delete all of the allocated Movie objects
  try{
    movies.first();
    while(true){
      delete movies.getCurrentValue();
      movies.next();
    }

  } catch (NoSuchElementException &e){
    //went through all elements
  }

  return 0;

}

bool initializeData(std::string input_file, 
                    Map<std::string, User*> & users, 
                    Map<std::string, Movie*> & movies, 
                    Map<std::string, Set<Movie*> > & movies_by_keyword){

  //close it!!
  //Open the main data file
  std::ifstream main_data_file(input_file.c_str());

  if(main_data_file.is_open()){
  
    std::string user_data, movie_data;

    //Save file names from the main data file
    std::getline(main_data_file, user_data);
    std::getline(main_data_file, movie_data);

    //Output the names for testing
    //std::cout << user_data << std::endl << movie_data << std::endl;

    if(initializeUserData(user_data, users) && initializeMovieData(movie_data, movies, movies_by_keyword)){

      //Both files are properly set up, so return true
      _user_data_file = user_data;
      _movie_data_file = movie_data;
      //Print out all of the users (for debugging)
      try{
        users.first();
        while(true){
          std::cout << users.getCurrentKey() << ": " << users.getCurrentValue()->getName() << std::endl;
          try{
            users.next();
          } catch (NoSuchElementException &e){
            // no more elements
            break;
          }
        }
      } catch (NoSuchElementException &e){
        std::cerr << "User map is empty" << std::endl;
      }

      try{
        movies.first();
        while(true){
          std::cout << movies.getCurrentKey() << std::endl;
          try{
            movies.next();
          } catch (NoSuchElementException &e){
            // no more elements
            break;
          }
        }
      } catch (NoSuchElementException &e){
        std::cerr << "User map is empty" << std::endl;
      }
      
    }
    
  } else {

    std::cerr << "The provided data file doesn't appear to exist. Try another one." << std::endl;
    return 0;
    
  }

  main_data_file.close();

  return 1;
  
}

/* Reads the specified User data file, stores the data in the users Map
 * PRECONDITION: there is a user data file with correctly formatted information, and an empty users Map
 * POSTCONDITION: The user data file information is added to the users Map
 */
bool initializeUserData(std::string user_data_file, Map<std::string, User*> & users){

  std::ifstream user_data(user_data_file.c_str());

  if(user_data.is_open()){
    std::string line = "";

    //iterate through all of the file's lines
    User * new_user;
    std::string id, name;
    while(std::getline(user_data, line)){
      //iterate over all lines in the file, tokenizing them
      std::string command, parameters;
      if(!parseCommand(line, command, parameters)){
        //Something went wrong parsing the command
        user_data.close();
        return 0;
      } else {
        //call the appropriate action for the command
        if(command == "BEGIN"){
          id = parameters;
        } else if (command == "NAME:"){
          name = parameters;
        } else if (command == "END"){
          new_user = new User(id, name);
          users.add(new_user->getID(), new_user);
        }
      }
    }
  } else {
    std::cerr << "It looks like the file doesn't exist. Please be sure to specify the entire file's path \
                  in the main data file (i.e. data/users.dat)" << std::endl;
    user_data.close();
    return 0;
  }

  user_data.close();
  
  return 1;
  

}

/* Reads the specified Movie data file, stores the data in the movies and movies_by_keyword Map
 * PRECONDITION: there is a movie data file with correctly formatted information, 
 *  and an empty movies and movies_by_keyword Map
 * POSTCONDITION: The movie data file information is added to the movies Map, 
 *  and keywords are organized in the movies_by_keyword map
 */
bool initializeMovieData(std::string movie_data_file, 
                         Map<std::string, Movie*> & movies, 
                        Map<std::string, Set<Movie*> > & movies_by_keyword){

  std::ifstream movie_data(movie_data_file.c_str());

  if(movie_data.is_open()){
    std::string line = "";

    //iterate through all of the file's lines
    Movie * new_movie;
    std::string name;
    std::vector<std::string> keywords;
    while(std::getline(movie_data, line)){
      //iterate over all lines in the file, tokenizing them
      std::string command, parameters;
      if(!parseCommand(line, command, parameters)){
        //Something went wrong parsing the command
        movie_data.close();
        return 0;
      } else {
        //call the appropriate action for the command
        if(command == "BEGIN"){
          name = parameters;
        } else if (command == "KEYWORD:"){
          keywords.push_back(parameters);
        } else if (command == "END"){
          new_movie = new Movie(name);
          movies.add(new_movie->getTitle(), new_movie);
        }
      }
    }
  } else {
    std::cerr << "It looks like the file doesn't exist. Please be sure to specify the entire file's path \
                  in the main data file (i.e. data/movies.dat)" << std::endl;
    movie_data.close();
    return 0;
  }

  movie_data.close();


  return 1;

}

bool parseCommand(std::string line, std::string & command, std::string & parameters){

  std::vector<std::string> words;
  if(!tokenizeLine(line, words)){
    //something must have gone wrong in splitting up the line. Exit the funciton
    return 0;
  } else {

    //We have the line tokenized now. Now, determine what the command is
    command = words[0];

    for(int i = 1; i < words.size(); i++){
      //consolidate names into single parameters
      parameters += words[i];
      if(i != words.size()-1){
        //Add a space between first and last name
        parameters += " ";
      }
    }
  }

  return 1;
  
}

/*************** Log In Functions ***************/
/************************************************/


bool loginUser(Map<std::string, User*> & users){

  std::string username;

  std::cout << "ID: ";
  std::cin >> username;

  std::cin.clear();
  std::cin.ignore(10000, '\n');

  try{
    users.get(username);
  } catch(NoSuchElementException &e){
    std::cout << "Invalid ID." << std::endl;
    return false;
  }
  std::cout << "Logged in" << std::endl;
  return true;

}

void createNewUser(Map<std::string, User*> & users){

  do{
    std::string username, name;
    std::cout << "Enter a user ID: ";
    std::cin >> username;

    std::cin.clear();
    std::cin.ignore(10000, '\n');

    try{
      users.get(username);
    } catch (NoSuchElementException &e){
      //Add New User
      addNewUser(users, username);
      return;
    }
    std::cout << "ID already Exists." << std::endl;
  } while(true);

  std::cin.clear();
  std::cin.ignore(10000, '\n');

  return;

}

void addNewUser(Map<std::string, User*> & users, std::string username){

  std::cin.clear();
  std::cin.ignore(10000, '\n');
  
  std::string name = "";
  std::cout << "Enter a Name: ";
  std::getline(std::cin, name);
  
  User * newUser = new User(username, name);
  users.add(username, newUser);
  //Add to users file as well
  std::fstream user_file(_user_data_file.c_str(), std::fstream::app);
  std::string id_header = "BEGIN " + username + "\n";
  std::string name_value = "NAME: " + name + "\n";

  //Add User to Data file
  user_file << id_header;
  user_file << name_value;
  user_file << "END";

  user_file.close();

  std::cin.clear();
  std::cin.ignore(10000, '\n');

  return;
 
}


/*************** Utility Functions **************/
/************************************************/
// Splits a line up by its words, adding the words to the referenced words vector
bool tokenizeLine(std::string line, std::vector<std::string> & words){
  std::stringstream ss;
  ss << line;
  std::string word;

  //store each line's words individually in a vector
  while(ss >> word){
    words.push_back(word);

    if(ss.fail()){
      std::cerr << "Error parsing a line. Check that your file is correctly formatted" << std::endl;
      return 0;
    }
  }

  ss.clear();
  ss.str("");
  return 1;
}

int getMenuInput(){

  int choice;
  do
  {
    
    std::cout << "1. Log in" << std::endl;
    std::cout << "2. Create new user" << std::endl;
    std::cout << "3. Quit" << std::endl;

    choice = getInput();
  } while(choice == -1);

  return choice;
}

int getInput(){

  int x;

  std::cin >> x;

  if (std::cin.fail() || x > 3 || x < 1){

    std::cin.clear();
    std::cin.ignore(10000, '\n'); //clear inputs up to 10,000 characters, or first newline
    std::cout << "Invalid Input. Enter a value 1-3: " << std::endl; //prompt user again if the user screwed up
    x = -1; //jump to while statement
  }
  //a good character entered

  std::cin.ignore(100000, '\n'); //clear the stream
  
  return x;
}



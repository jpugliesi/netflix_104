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
                    Map<std::string, Set<Movie*>* > & movies_by_keyword);

bool initializeUserData(std::string user_data_file, Map<std::string, User*> & users);

bool initializeMovieData(std::string movie_data_file, 
                         Map<std::string, Movie*> & movies, 
                        Map<std::string, Set<Movie*>* > & movies_by_keyword);

bool tokenizeLine(std::string line, std::vector<std::string> & words);
bool parseCommand(std::string line, std::string & command, std::string & parameter);

bool loginUser(Map<std::string, User*> & users);
void createNewUser(Map<std::string, User*> & users);
void addNewUser(Map<std::string, User*> & users, std::string username);

int getMenuInput();
int getMovieInput();
int getInput(int start_range, int end_range);

void searchMoviesPrompt(Map<std::string, Movie*> & movies);
void searchMoviesByKewordPrompt(Map<std::string, Movie*> & movies, Map<std::string, Set<Movie*>* > & movies_by_keyword);
void printMovie(Movie* movie, bool print_keywords);


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
  Map<std::string, Set<Movie*>* > movies_by_keyword;

  std::string input_file = argv[1];

  if(initializeData(input_file, users, movies, movies_by_keyword)){
  
    //The files were read properly.
    //Launch the interactive experience
    int choice;
    do{
      choice = 3;
      choice = getMenuInput();
      
      switch(choice){

        case 1: if(loginUser(users)){
                  //movie prompts
                  int choice;
                  do{
                    choice = getMovieInput();
                    
                    switch(choice){

                      case 1: searchMoviesPrompt(movies);
                              break;
                      case 2: searchMoviesByKewordPrompt(movies, movies_by_keyword);
                              break;
                      case 3: break;
                      default: break;
                      
                    }
                
                  } while(choice != 3);
                  
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
  Map<std::string, User*>::Iterator usersIt;
  for(usersIt = users.begin(); usersIt != users.end(); ++usersIt){
    delete (*usersIt).second;
  }

  //delete all of the allocated Movie objects
  Map<std::string, Movie*>::Iterator moviesIt;
  for(moviesIt = movies.begin(); moviesIt != movies.end(); ++moviesIt){
    delete (*moviesIt).second;
  }

  Map<std::string, Set<Movie*>* >::Iterator keywordsIt;
  for(keywordsIt = movies_by_keyword.begin(); keywordsIt != movies_by_keyword.end(); ++keywordsIt){
    delete (*keywordsIt).second;
  }

  return 0;

}

bool initializeData(std::string input_file, 
                    Map<std::string, User*> & users, 
                    Map<std::string, Movie*> & movies, 
                    Map<std::string, Set<Movie*>* > & movies_by_keyword){

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

    }
    
  } else {

    std::cerr << "The provided data file doesn't appear to exist. Try another one." << std::endl;
    main_data_file.close();
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
                        Map<std::string, Set<Movie*>* > & movies_by_keyword){

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
          movies.add(new_movie->getLowerTitle(), new_movie);
          for(int i = 0; i < keywords.size(); i++){
            std::string word = keywords[i];
            //Transform keyword to lowercase for easy comparison
            for(int i = 0; word[i]; i++) word[i] = tolower(word[i]);
            //Add keyword to a movie
            new_movie->addKeyword(word);
            
            try{
              Set<Movie*>* existing_movies_set = movies_by_keyword.get(word);
              //keyword already exists. Merge new movie set with old one and store back in keywords map
              //Set<Movie*>* combined_movies = existing_movies_set->setUnion(*word_movie_set);
              Set<Movie*>* combined_movies = new Set<Movie*>(*existing_movies_set);
              combined_movies->add(new_movie);
              movies_by_keyword.remove(word);
              movies_by_keyword.add(word, combined_movies);
            } catch (NoSuchElementException &e){
              //keyword Doesn't exist in the map. Add word/Movie association to the map
              //Add movies to keywords (in the movies_by_keywords set)
              Set<Movie*>* word_movie_set = new Set<Movie*>;
              word_movie_set->add(new_movie);
              //check if movies_by_keyword map already contains the keyword
              movies_by_keyword.add(word, word_movie_set);
            }
          }          
          //clear the keywords vector to not add duplicate keywords
          keywords.clear();
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
  std::getline(std::cin, username);
  std::cin.sync();

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
    std::string username, name, dummy;
    std::cout << "Enter a user ID: ";
    std::getline(std::cin, username);

    try{
      users.get(username);
    } catch (NoSuchElementException &e){
      //Add New User
      addNewUser(users, username);
      return;
    }
    std::cout << "ID already Exists." << std::endl;
  } while(true);

  return;

}

void addNewUser(Map<std::string, User*> & users, std::string username){

  std::string name;
  std::cout << "Enter a Name: ";

  std::getline(std::cin, name);
 
  User * newUser = new User(username, name);
  users.add(username, newUser);
  //Add to users file as well
  std::fstream user_file(_user_data_file.c_str(), std::fstream::app | std::fstream::out);
  std::string id_header = "BEGIN " + username + "\n";
  std::string name_value = "NAME: " + name + "\n";

  //Add User to Data file
  user_file << id_header;
  user_file << name_value;
  user_file << "END" << "\n";

  user_file.close();

  return;
 
}

/*************** Movie Functions ****************/
/************************************************/

void searchMoviesPrompt(Map<std::string, Movie*> & movies){

  std::string movie;
  std::cout << "Enter a movie title: " << std::endl;

  //Search for movie in the movies Map
  std::getline(std::cin, movie);
  try{
    for(int i = 0; movie[i]; i++) movie[i] = tolower(movie[i]); 
    Movie * search_movie = movies.get(movie);
    printMovie(search_movie, true);
  } catch (NoSuchElementException &e){
    //movie DNE
    std::cout << "Movie Not Found." << std::endl;
  }

}
void searchMoviesByKewordPrompt(Map<std::string, Movie*> & movies, Map<std::string, Set<Movie*>* > & movies_by_keyword){

  std::string keyword;
  std::cout << "Enter a keyword: " << std::endl;

  //search for movies that contain the keyword, or the title of the movie
  std::getline(std::cin, keyword);
  bool found_movie_title = false;
  try{
    for(int i = 0; keyword[i]; i++) keyword[i] = tolower(keyword[i]); 
    //Find movies where title == keyword
    try{
      Movie * search_movie = movies.get(keyword);
      found_movie_title = true;
      printMovie(search_movie, false);
    } catch (NoSuchElementException &e){
      //keyword is not a title
    }

    //Find keywords that match
    Set<Movie*>* search_keyword = movies_by_keyword.get(keyword);
    try{
      search_keyword->first();
      std::cout << search_keyword->size() << " matches found" << std::endl;
      int choice;
      do{
        printMovie(search_keyword->getCurrent(), true);

        search_keyword->next();
        std::cout << "1. Next Movie" << std::endl;
        std::cout << "2. Return to menu" << std::endl;
        choice = getInput(1, 2);
      } while (choice == 1);
    } catch (NoSuchElementException &e){
      int choice;
      do{
        std::cout << "1. Return to Menu" << std::endl;
        choice = getInput(1,1);
      } while (choice != 1);
      //No more movies in the set.
    }

  } catch (NoSuchElementException &e){
    //keyword DNE
    if(!found_movie_title) std::cout << "No Match." << std::endl;
  }

}

void printMovie(Movie * movie, bool print_keywords){
  std::cout << movie->getTitle() << std::endl;
  if(print_keywords){
    try{
      Set<std::string> keywords = movie->getAllKeywords();
      keywords.first();
      while(true){
        std::cout << keywords.getCurrent() << std::endl;
        keywords.next();
      }
    } catch (NoSuchElementException &e){
      //No keywords
    }
  }
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

    choice = getInput(1,3);
  } while(choice == -1);

  return choice;
}

int getMovieInput(){

  int choice;
  do
  {
    
    std::cout << "1. Search for a movie by title" << std::endl;
    std::cout << "2. Search for a movie by keyword" << std::endl;
    std::cout << "3. Logout" << std::endl;

    choice = getInput(1,3);
  } while(choice == -1);

  return choice;
}

int getInput(int start_range, int end_range){

  int x;

  std::cin >> x;

  if (std::cin.fail() || x > end_range || x < start_range){

    std::cin.clear();
    x = -1; //jump to while statement
  }
  //a good character entered

  std::cin.clear();
  std::cin.ignore(100000, '\n'); //clear the stream
  
  return x;
}



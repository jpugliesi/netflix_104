#ifndef NETFLIX_H
#define NETFLIX_H

#include <string>
#include "Map.h"
#include "Movie.h"
#include "User.h"

class Netflix{

  public:
    
    Netflix();
    ~Netflix();
    
    bool initializeData(std::string input_file);

    bool initializeUserData(std::string);

    bool initializeMovieData(std::string);

    bool tokenizeLine(std::string line, std::vector<std::string> & words);
    bool parseCommand(std::string line, std::string & command, std::string & parameter);

    bool loginUser();
    void createNewUser();
    void addNewUser(std::string username);

    void writeUsersToFile();

    int getMenuInput();
    int getMovieInput();
    int getQueueInput();
    int getInput(int start_range, int end_range);

    void searchMoviesPrompt();
    void searchMoviesByKewordPrompt();
    void modifyQueuePrompt();

    void printMovie(Movie* movie, bool print_keywords);

    User* & getCurrentUser();

    private: 
      std::string _user_data_file;      
      std::string _movie_data_file;
      
      //Important Variables
      // A Map of all of the application's users
      //  It will be filled on each run of the program, by reading through the appropriate 
      //  users data file
      Map<std::string, User*> users;
      User* current_user;  
      // A Map of all of the application's movies
      //  It will be filled on each run of the program, by reading through the appropriate 
      //  users data file
      Map<std::string, Movie*> movies;

      // Keywords for all movies in the application
      Map<std::string, Set<Movie*>* > movies_by_keyword;

};

#endif

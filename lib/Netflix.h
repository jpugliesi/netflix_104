#ifndef NETFLIX_H
#define NETFLIX_H

#include <string>
#include <set>
#include <map>
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

    bool loginUser(std::string username);
    bool createNewUser(std::string username, std::string name);

    void writeUsersToFile();

    int getMenuInput();
    int getMovieInput();
    int getQueueInput();
    int getInput(int start_range, int end_range);

    std::set<Movie*> searchMoviesByTitle(std::string movie);
    std::set<Movie*> searchMoviesByKeyword(std::string keyword);
    void modifyQueuePrompt();

    void printMovie(Movie* movie, bool print_keywords);

    User* & getCurrentUser();
    void logoutCurrentUser();

    int orderTopOfQueue();
    int removeTopOfQueue();
    int moveToBackOfQueue();
    Movie* getTopOfQueue();
    Movie* getCurrentMovie();

    std::string getMainDataFile();

    private: 
      std::string main_data_file;
      std::string _user_data_file;      
      std::string _movie_data_file;

      int unique_id;
      
      //Important Variables
      // A Map of all of the application's users
      //  It will be filled on each run of the program, by reading through the appropriate 
      //  users data file
      std::map<std::string, User*> users;
      User* current_user;  
      // A Map of all of the application's movies
      //  It will be filled on each run of the program, by reading through the appropriate 
      //  users data file
      std::map<std::string, Movie*> movies;

      // Keywords for all movies in the application
      std::map<std::string, std::set<Movie*>* > movies_by_keyword;

      //Adjacency list for Similiarity Graph
      std::vector< std::vector< std::pair<int, double> > > s_graph;

};

#endif

#ifndef NETFLIX_H
#define NETFLIX_H

#include <string>
#include <set>
#include <map>
#include "Movie.h"
#include "User.h"
#include "Actor.h"

class Netflix{

  public:
    
    Netflix();
    ~Netflix();
    
    bool initializeData(std::string input_file);

    bool initializeUserData(std::string);

    bool initializeMovieData(std::string);

    int calculateBaconDistance(Actor* the_actor, Actor* second_actor);

    bool tokenizeLine(std::string line, std::vector<std::string> & words);
    bool parseCommand(std::string line, std::string & command, std::string & parameter);

    bool loginUser(std::string username);
    bool createNewUser(std::string username, std::string name);
    User* getUserByID(int id);

    void writeUsersToFile();

    int getMenuInput();
    int getMovieInput();
    int getQueueInput();
    int getInput(int start_range, int end_range);

    std::set<Movie*> searchMoviesByTitle(std::string movie);
    std::set<Movie*> searchMoviesByKeyword(std::string keyword);
    std::set<Movie*> searchMoviesByActor(std::string actor);
    Actor* searchActors(std::string actor);
    void modifyQueuePrompt();

    void printMovie(Movie* movie, bool print_keywords);

    User* & getCurrentUser();
    void logoutCurrentUser();

    int orderTopOfQueue();
    int removeTopOfQueue();
    int moveToBackOfQueue();
    Movie* getTopOfQueue();
    Movie* getCurrentMovie();
    Movie* getMostInterestingMovie();

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
      std::vector<User*> users_by_id;

      User* current_user;  
      // A Map of all of the application's movies
      //  It will be filled on each run of the program, by reading through the appropriate 
      //  users data file
      std::map<std::string, Movie*> movies;

      // Keywords for all movies in the application
      std::map<std::string, std::set<Movie*>* > movies_by_keyword;

      //set for actors
      std::map<std::string, std::set<Movie*> > actors;

      //Adjacency list for Similiarity Graph
      double calculateSimilarity(User* user_a, User* user_b);
      double calculateMovieInterestingness(Movie* m);

      Movie* most_interesting_movie;
      std::vector<double> calculateRefinedSimilarity(User* user);
      void createSimilarityGraph();

      std::vector< std::vector< std::pair<int, double> > >* s_graph;
      std::vector<double> refined_sim;
      
      std::map<std::string, Actor*> _actor_objects;
      std::vector<Actor*> actors_by_index;

      void createBaconGraph();
      std::vector< std::vector<int> >* bacon_graph;
};

#endif

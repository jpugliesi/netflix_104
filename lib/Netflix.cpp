#include "Netflix.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <utility>
#include "Set.h"
#include "Queue.h"
#include "Pair.h"
#include "NoSuchElementException.h"

Netflix::Netflix(){

  current_user = NULL;
}

Netflix::~Netflix(){

  writeUsersToFile();
  /******* clean up! *******/
  //delete all of the allocated User objects
  std::map<std::string, User*>::iterator usersIt;
  for(usersIt = users.begin(); usersIt != users.end(); ++usersIt){
    delete (*usersIt).second;
  }

  //delete all of the allocated Movie objects
  std::map<std::string, Movie*>::iterator moviesIt;
  for(moviesIt = movies.begin(); moviesIt != movies.end(); ++moviesIt){
    delete (*moviesIt).second;
  }

  std::map<std::string, std::set<Movie*>* >::iterator keywordsIt;
  for(keywordsIt = movies_by_keyword.begin(); keywordsIt != movies_by_keyword.end(); ++keywordsIt)  {
    delete (*keywordsIt).second;
  }


}

User* & Netflix::getCurrentUser(){
  return current_user;
}

void Netflix::logoutCurrentUser(){
  current_user = NULL;
}

bool Netflix::initializeData(std::string input_file){

  //close it!!
  //Open the main data file
  
  main_data_file = input_file;
  std::ifstream main_data_file(input_file.c_str());

  if(main_data_file.is_open()){
  
    std::string user_data, movie_data;

    //Save file names from the main data file
    std::getline(main_data_file, user_data);
    std::getline(main_data_file, movie_data);

    //Output the names for testing
    //std::cout << user_data << std::endl << movie_data << std::endl;
    bool moviesInitialized = initializeMovieData(movie_data);
    bool usersInitialized = initializeUserData(user_data);
    if(moviesInitialized && usersInitialized){

      //Both files are properly set up, so return true _user_data_file = user_data; _movie_data_file = movie_data; std::map<std::string, User*>::iterator usersIt; std::cerr << users.size() << " Users loaded" << std::endl; for(usersIt = users.begin(); usersIt != users.end(); ++usersIt){ std::cerr << (*usersIt).second->getName() << " loaded" << std::endl;
      
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
bool Netflix::initializeUserData(std::string user_data_file){

  std::ifstream user_data(user_data_file.c_str());
  if(user_data.is_open()){
    std::string line = "";

    //iterate through all of the file's lines
    User * new_user;
    Movie* currentMovie;
    std::string id, name;
    bool isQueue = false;
    bool isRatings = false;
    std::queue<Movie*> movies_to_add;
    std::map<Movie*, int> ratings_to_add;
    while(std::getline(user_data, line)){
      //iterate over all lines in the file, tokenizing them
      std::cerr << line << std::endl;
      std::string command, parameters;
      if(!parseCommand(line, command, parameters)){
        //Something went wrong parsing the command
	      std::cerr << "Command: " << command << std::endl;
	      std::cerr << "parameters: " << parameters << std::endl;
        user_data.close();
        return 0;
      } else {
        //call the appropriate action for the command
        std::cerr << "Command: " << command << std::endl;
	      std::cerr << "parameters: " << parameters << std::endl;
        if(!isQueue){
          if(!isRatings && !isQueue){
            if(command == "BEGIN"){
              if (parameters == "QUEUE"){
                isQueue = true;
                std::cerr << "It's a queue!" << std::endl;
                continue;
              } else if(parameters == "RATINGS"){
                isRatings = true;
                std::cerr << "RATINGS!" << std::endl;
                continue;
              } else {
                id = parameters;
              }
            } else if (command == "NAME:"){
              name = parameters;
            } else if (command == "END"){
              //create the user with all of their appropriate data
              new_user = new User(id, name);
              std::queue<Movie*>* queue = new_user->movieQueue();
              if(currentMovie != NULL){
                      new_user->rentMovie(currentMovie);
              }	
              while(!movies_to_add.empty()){
                std::cerr << "adding " << movies_to_add.front()->getTitle() << " to " << name << "'s queue" << std::endl;
                queue->push(movies_to_add.front());
                movies_to_add.pop();
              }
	      
              //add ratings
              std::map<Movie*, int>* users_ratings = new_user->movieRatings();
              users_ratings->insert(ratings_to_add.begin(), ratings_to_add.end());
              for(std::map<Movie*, int>::iterator i = users_ratings->begin(); i != users_ratings->end(); ++i){
                std::cout << i->first->getTitle() << " has a rating of " << i->second << std::endl;

              }

	            ratings_to_add.clear();

              std::cerr << "Creating user with id: " << id << " and Name: " << name << std::endl;
              std::pair<std::string, User*> toAdd;
              toAdd.first = new_user->getID();
              toAdd.second = new_user;
              users.insert(toAdd);

            } else if (command == "MOVIE:"){
              std::map<std::string, Movie*>::iterator it;
              
              std::cout << "Current movie: " << parameters << std::endl;
              for(int i = 0; parameters[i]; i++) parameters[i] = tolower(parameters[i]);
              it = movies.find(parameters);
              if(it != movies.end()){
                currentMovie = it->second;
              } else {
                std::cout << "That movie doesn't exist" << std::endl;
                return 0;
              }
            }
          } else if(command!= "END"){
            std::cout << "RATINGS COMMAND: " << command << std::endl;
            std::cout << "PARAMS: " << parameters << std::endl;
            std::stringstream ss;
            int rating_val;
            ss << command;
            ss >> rating_val; 
            
            std::map<std::string, Movie*>::iterator it;
            Movie* rated_movie = NULL;
            
            for(int i = 0; parameters[i]; i++) parameters[i] = tolower(parameters[i]);
            it = movies.find(parameters);
            if(it != movies.end()){
              rated_movie = it->second;
            } else {
              std::cout << "That movie doesn't exist" << std::endl;
              return 0;
            }
            
            std::pair<Movie*, int> toAdd;
            toAdd.first = rated_movie;
            toAdd.second = rating_val;
            
            ratings_to_add.insert(toAdd);
            
          } else if(command == "END" && parameters == "RATINGS"){
            std::cerr << "End of Ratings" << std::endl;
            isRatings = false;
            continue;
          }

        } else if(command != "END") {
          std::string a_movie;
          a_movie = command + " " + parameters;
          for(int i = 0; a_movie[i]; i++) a_movie[i] = tolower(a_movie[i]);

          std::map<std::string, Movie*>::iterator it;

          it = movies.find(a_movie);
          if(it != movies.end()){
            movies_to_add.push(it->second);
            std::cerr << "Movies to add now contains: " << it->second->getTitle() << std::endl;
          } else {
            std::cout << "That movie doesn't exist" << std::endl;
          }
        } else if(command == "END" && parameters == "QUEUE"){
          std::cerr << "End of Queue" << std::endl;
          isQueue = false;
          continue;
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
bool Netflix::initializeMovieData(std::string movie_data_file){

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
          std::pair<std::string, Movie*> movieToAdd;
          movieToAdd.first = new_movie->getLowerTitle();
          movieToAdd.second = new_movie;
          movies.insert(movieToAdd);
          for(int i = 0; i < keywords.size(); i++){
            std::string word = keywords[i];
            //Transform keyword to lowercase for easy comparison
            for(int i = 0; word[i]; i++) word[i] = tolower(word[i]);
            //Add keyword to a movie
            new_movie->addKeyword(word);
            
            /*try{
              //will throw NoSuchElementException if word DNE
              std::set<Movie*>* existing_movies_set = movies_by_keyword.get(word);
              //keyword already exists. Merge new movie set with old one and store back in keywords map
              //Set<Movie*>* combined_movies = existing_movies_set->setUnion(*word_movie_set);
              std::set<Movie*>* combined_movies = new std::set<Movie*>(*existing_movies_set);
              delete existing_movies_set;
              combined_movies->insert(new_movie);
              movies_by_keyword.remove(word);
              movies_by_keyword.add(word, combined_movies);
            } catch (NoSuchElementException &e){
              //keyword Doesn't exist in the map. Add word/Movie association to the map
              //Add movies to keywords (in the movies_by_keywords set)
              std::set<Movie*>* word_movie_set = new std::set<Movie*>();
              word_movie_set->insert(new_movie);
              movies_by_keyword.add(word, word_movie_set);
            }*/

            std::map<std::string, std::set<Movie*>* >::iterator it;

            it = movies_by_keyword.find(word);
            if(it != movies_by_keyword.end()){
              std::set<Movie*>* existing_movies_set = it->second;
              std::set<Movie*>* combined_movies = new std::set<Movie*>(*existing_movies_set);

              delete existing_movies_set;
              combined_movies->insert(new_movie);
              movies_by_keyword.erase(word);

              std::pair<std::string, std::set<Movie*>* > toAdd;
              toAdd.first = word;
              toAdd.second = combined_movies;
              movies_by_keyword.insert(toAdd);
              
            } else {
              //keyword Doesn't exist in the map. Add word/Movie association to the map
              //Add movies to keywords (in the movies_by_keywords set)
              std::set<Movie*>* word_movie_set = new std::set<Movie*>();
              word_movie_set->insert(new_movie);

              std::pair<std::string, std::set<Movie*>* > toAdd;
              toAdd.first = word;
              toAdd.second = word_movie_set;
              movies_by_keyword.insert(toAdd);
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

bool Netflix::parseCommand(std::string line, std::string & command, std::string & parameters){

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


bool Netflix::loginUser(std::string username){

  std::map<std::string, User*>::iterator it;
  it = users.find(username);
  if(it != users.end()){
    this->current_user = it->second;
  } else {
    std::cout << "Invalid ID." << std::endl;
    current_user = NULL;
    return false;
  }
  return true;

}

bool Netflix::createNewUser(std::string username, std::string name){

  std::map<std::string, User*>::iterator it;
  it = users.find(username);
  if(it == users.end()){
    //Add New User
    User * newUser = new User(username, name);
    std::pair<std::string, User*> toAdd;
    toAdd.first = username;
    toAdd.second = newUser;
    users.insert(toAdd);

    return true;
  }
  return false;

}

void Netflix::writeUsersToFile(){
  
  std::fstream user_file(_user_data_file.c_str(), std::fstream::out);

  std::cerr << "Writing Users to file" << std::endl;
  std::map<std::string, User*>::iterator userIt;
  for(userIt = users.begin(); userIt != users.end(); ++userIt){
  
    std::pair<std::string, User*> a_user = (*userIt);
    std::string username = a_user.first;
    std::string name = a_user.second->getName();
    std::string id_header = "BEGIN " + username + "\n";
    std::string name_value = "NAME: " + name + "\n";
    std::string current_movie;
    if(a_user.second->currentMovie() != NULL){
      current_movie = "MOVIE: " + a_user.second->currentMovie()->getTitle() + "\n";
    }

    std::queue<Movie*>* queue = new std::queue<Movie*>(*(a_user.second->movieQueue()));
    std::string queue_movie;

    //Add User to Data file
    user_file << id_header;
    user_file << name_value;
    if(a_user.second->currentMovie() != NULL){
      user_file << current_movie;
    }
    user_file << "BEGIN QUEUE \n";
    while(!queue->empty()){
      queue_movie = queue->front()->getTitle() + "\n";
      queue->pop();
      std::cerr << "Adding " << queue_movie << " to " << name_value << "'s queue" << std::endl;
      user_file << queue_movie;
    }
    user_file << "END QUEUE \n";
    
    user_file << "BEGIN RATINGS \n";
    std::map<Movie*, int>::iterator ratingsIt;
    std::stringstream ss;
    for(ratingsIt = a_user.second->movieRatings()->begin(); ratingsIt != a_user.second->movieRatings()->end(); ++ratingsIt){
      std::string title = ratingsIt->first->getTitle();
      int rating_v = ratingsIt->second;
      std::string rating_s;
      ss << rating_v;
      ss >> rating_s;
      std::cout << "Rating_s: " << rating_s << std::endl;
      std::string rating_line = rating_s + " " + title + "\n";
      std::cerr << rating_line << std::endl;
      user_file << rating_line;
    }
    user_file << "END RATINGS \n";
    user_file << "END" << "\n";
  }

  user_file.close();

}

/*************** Movie Functions ****************/
/************************************************/

std::set<Movie*> Netflix::searchMoviesByTitle(std::string movie){

  //Search for movie in the movies Map
  std::set<Movie*> result;
  std::map<std::string, Movie*>::iterator movieIt;

  for(int i = 0; movie[i]; i++) movie[i] = tolower(movie[i]);

  movieIt = movies.find(movie);
  if(movieIt != movies.end()){
    Movie* search_movie = movieIt->second;
    result.insert(search_movie);
  } else {
    std::cerr << "Movie Not Found" << std::endl;
  }

  return result;

}
std::set<Movie*> Netflix::searchMoviesByKeyword(std::string keyword){

  //search for movies that contain the keyword, or the title of the movie

  std::set<Movie*> result;

  std::map<std::string, Movie*>::iterator movieIt;
  std::map<std::string, std::set<Movie*>* >::iterator movieKeywordIt;
  
  for(int i = 0; keyword[i]; i++) keyword[i] = tolower(keyword[i]);

  //check titles first
  movieIt = movies.find(keyword);
  if(movieIt != movies.end()){
    //found a title
    result.insert(movieIt->second);
  }

  movieKeywordIt = movies_by_keyword.find(keyword);
  if(movieKeywordIt != movies_by_keyword.end()){
    //found movies with the associated keyword
    std::set<Movie*>* movies_to_add = movieKeywordIt->second;
    result.insert(movies_to_add->begin(), movies_to_add->end());
  }
  
  std::cerr << "Size: " << result.size() << std::endl;
  
  return result;

  /*try{
    for(int i = 0; keyword[i]; i++) keyword[i] = tolower(keyword[i]); 
    //Find movies where title == keyword
    try{
      search_movie = movies.find(keyword)->second;
      found_movie_title = true;
    } catch (NoSuchElementException &e){
      //keyword is not a title
    }
    
    //Find keywords that match
    std::set<Movie*>* search_keyword = movies_by_keyword.get(keyword);
    std::set<Movie*> search_keyword_copy(*search_keyword);
    if(found_movie_title){
      search_keyword_copy.insert(search_movie);
    }
    std::cerr << "Size: " << search_keyword_copy.size() << std::endl;

    return search_keyword_copy;
    
    Set<Movie*>::Iterator keywordIt;

      keywordIt = search_keyword->begin();
      std::cout << search_keyword->size() << " matches found" << std::endl;
      int choice;

      //iterate through the movies and print them out, along with options
      while(keywordIt != search_keyword->end()){

        printMovie((*keywordIt), true);

        std::cout << "1. Next Movie" << std::endl;
        std::cout << "2. Add Movie to Queue" << std::endl;
        std::cout << "3. Return to menu" << std::endl;
        choice = getInput(1, 3);
        if (choice == 2){
          //Add the movie to the user's queue
          Queue<Movie*>* users_queue = current_user->movieQueue();
          users_queue->enqueue((*keywordIt));
          std::cout << "Added " << (*keywordIt)->getTitle() << " to your Queue" << std::endl;

        } else if(choice == 1) {
          Set<Movie*>::Iterator compIt;
          ++keywordIt;
          compIt = keywordIt;
          ++compIt;

          //if the movie after the next is the last movie, only display 2 options
          if (compIt == search_keyword->end()) break;
          continue;
        } else if(choice == 3){
          break;
        }
        
      }
      
      if(choice != 3){
      
        choice = 0;
        do{
          //print the movie
          printMovie((*keywordIt), true);
          
          std::cout << "1. Add Movie to Queue" << std::endl;
          std::cout << "2. Return to Menu" << std::endl;
          choice = getInput(1,2);

          if (choice == 1){
            //Add the movie to the user's queue
            Queue<Movie*>* users_queue = current_user->movieQueue();
            users_queue->enqueue((*keywordIt));
            std::cout << "Added " << (*keywordIt)->getTitle() << " to your Queue" << std::endl;
          }
        } while (choice != 2);
        
      }*/

      /*do{
        printMovie((*keywordIt), true);

        ++keywordIt;
        if (keywordIt != search_keyword->end()){
          std::cout << "1. Next Movie" << std::endl;
          std::cout << "2. Add Movie to Queue" << std::endl;
          std::cout << "3. Return to menu" << std::endl;
          choice = getInput(1, 3);

          if (choice == 2){
            //Add the movie to the user's queue
            Queue<Movie*>* users_queue = current_user->movieQueue();
            std::cout << users_queue << std::endl;
            //std::cout << "Empty?: " << users_queue->isEmpty() << std::endl;
            //users_queue->enqueue((*keywordIt));
            
          }
        } else break;

        
      } while (keywordIt != search_keyword->end() && choice != 3);
      
      do{
        std::cout << "1. Add Movie to Queue" << std::endl;
        std::cout << "2. Return to Menu" << std::endl;
        choice = getInput(1,2);

        if (choice == 1){
          //Add the movie to the user's queue
          Queue<Movie*>* users_queue = current_user->movieQueue();
          users_queue->enqueue((*keywordIt));
        }
      } while (choice != 2);
    
  } catch (NoSuchElementException &e){
    //keyword DNE
    std::set<Movie*> set;
    if(found_movie_title){ 
      set.insert(search_movie);
    }
    return set;
  }*/

}
//******** DEPRECATED *******************
//Prompt for working with the user's queue
/*void Netflix::modifyQueuePrompt(){

  std::queue<Movie*>* users_queue = current_user->movieQueue();
    
  int choice = 0;
  while (choice != 4){
    
    if (!users_queue->isEmpty()){
      std::cout << users_queue->peekFront()->getTitle() << std::endl;
    } else {
      std::cout << "Movie queue empty" << std::endl;
    }

    choice = getQueueInput();

      if (choice == 1){
        //Order movie at top of queue
        if (current_user->currentMovie() == NULL && !(users_queue->isEmpty())){
          current_user->rentMovie(users_queue->peekFront());
          users_queue->dequeue();
          std::cout << "Ordered " << current_user->currentMovie()->getTitle() << std::endl;
        } else if(users_queue->isEmpty()){
          std::cout << "No movies in your Queue" << std::endl;
        } else {
          std::cout << "You cannot order a new movie until you return the current one" << std::endl;
        }
        return;
      } else if(choice == 2){
        //Remove movie from queue
        try{
          users_queue->dequeue();
        } catch (EmptyQueueException &e){
          std::cout << "Your queue is empty" << std::endl;
        } 
      } else if(choice == 3){
        //Move movie back to queue
        if(!users_queue->isEmpty()){
          Movie* movie = users_queue->peekFront();
          users_queue->dequeue();
          users_queue->enqueue(movie);
        } else {
          std::cout << "Your queue is empty" << std::endl;
        }
      } else return;
      
  }
  

}*/

int Netflix::orderTopOfQueue(){
  std::queue<Movie*>* users_queue = current_user->movieQueue();
  if (current_user->currentMovie() == NULL && !(users_queue->empty())){
    current_user->rentMovie(users_queue->front());
    users_queue->pop();
    return 1;
    std::cout << "Ordered " << current_user->currentMovie()->getTitle() << std::endl;
  } else if(users_queue->empty()){
    std::cout << "No movies in your Queue" << std::endl;
    return 0;
  } else {
    std::cout << "You cannot order a new movie until you return the current one" << std::endl;
  }
  return -1;
}

int Netflix::removeTopOfQueue(){
  std::queue<Movie*>* users_queue = current_user->movieQueue();
  if(!users_queue->empty()){
    users_queue->pop();
    return 1;
  }
  return 0;
}
int Netflix::moveToBackOfQueue(){

  std::queue<Movie*>* users_queue = current_user->movieQueue();

  if(!users_queue->empty()){
    Movie* movie = users_queue->front();
    users_queue->pop();
    users_queue->push(movie);
    return 1;
  } else {
    std::cout << "Your queue is empty" << std::endl;
  }
  return 0;
}

Movie* Netflix::getCurrentMovie(){

  if(current_user->currentMovie() != NULL){
  std::cerr << current_user->getName() << " has movie: " << current_user->currentMovie() << std::endl;
  } else {
    std::cerr << "In getCurrentMovie(), but the movie is NULL" << std::endl;
  }
  Movie* c_movie = current_user->currentMovie();
  return c_movie;

}

std::string Netflix::getMainDataFile(){
  return main_data_file;
}

Movie* Netflix::getTopOfQueue(){

  std::queue<Movie*>* users_queue = current_user->movieQueue();
  if(!users_queue->empty()){
    return users_queue->front();
  } else {
    return NULL;
  }
}


void Netflix::printMovie(Movie * movie, bool print_keywords){
  //Print the title
  std::cout << movie->getTitle() << std::endl;

  //if we are printing keywords, iterate through then and do so.
  if(print_keywords){
    std::set<std::string> keywords = movie->getAllKeywords();
    for (std::set<std::string>::iterator it=keywords.begin(); it!=keywords.end(); ++it)
      std::cout << *it << std::endl;
  }
}
    


/*************** Utility Functions **************/
/************************************************/
// Splits a line up by its words, adding the words to the referenced words vector
bool Netflix::tokenizeLine(std::string line, std::vector<std::string> & words){
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

int Netflix::getMenuInput(){

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

int Netflix::getMovieInput(){

  int choice;
  do
  {
    
    std::cout << "1. Search for a movie by title" << std::endl;
    std::cout << "2. Search for a movie by keyword" << std::endl;
    std::cout << "3. Return the Current Movie" << std::endl;
    std::cout << "4. View Queue" << std::endl;
    std::cout << "5. Logout" << std::endl;

    choice = getInput(1,5);
  } while(choice == -1);

  return choice;
}

int Netflix::getQueueInput(){

  int choice;
  do
  {
    
    std::cout << "1. Order Movie" << std::endl;
    std::cout << "2. Remove Movie from Queue" << std::endl;
    std::cout << "3. Move Movie to back of Queue" << std::endl;
    std::cout << "4. Return to User Menu" << std::endl;

    choice = getInput(1,4);
  } while(choice == -1);

  return choice;
}

int Netflix::getInput(int start_range, int end_range){

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



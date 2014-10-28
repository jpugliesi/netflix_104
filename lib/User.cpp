#include "User.h"
/* constructor that generates a user with the given name and ID.
While multiple users may have the same name, the ID should be unique
(e.g., an e-mail address), so that users can log in with it. */
User::User(std::string ID, std::string name){
  this->name = name;
  this->id = ID;
  this->current_movie = NULL;
}

// copy constructor  
User::User(const User & other){
  this->name = other.getName();
  this->id = other.getID();
}

//destructor
User::~User(){
}

// returns the ID associated with this user
std::string User::getID() const{
  return id;
}

// returns the name associated with this user
std::string User::getName() const{
  return name;
}

Queue<Movie*> * User::movieQueue () {

  return &movie_queue;

}
/* returns a pointer to the user's movie queue.
   This is the easiest way to ensure that you can modify the queue.
   (If you return by reference, that's also possible, but you'd need
   to be very careful not to invoke any deep copy constructors or
   assignments. A pointer is thus safer.) */

void User::rentMovie (Movie *m){
  if (current_movie == NULL){
    current_movie = m;
  } else {
    std::cout << "You already have a movie checked out. Return it before renting another." << std::endl;
  }
}
  /* sets the user's currently rented movie to m.
     If the user already has a movie checked out, then it does nothing.
     (So no overwriting the current movie.) */

void User::returnMovie (){

  if (current_movie != NULL) current_movie = NULL;

}
  /* returns the movie that the user currently has checked out.
     Does nothing if the user doesn't currently have a movie. */

Movie* User::currentMovie (){

  return current_movie;

}
  /* returns the user's current checked out movie.
     Returns NULL if the user has no movie checked out. */

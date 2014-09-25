#include "User.h"
/* constructor that generates a user with the given name and ID.
While multiple users may have the same name, the ID should be unique
(e.g., an e-mail address), so that users can log in with it. */
User::User(std::string ID, std::string name){
  this->name = name;
  this->id = ID;
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

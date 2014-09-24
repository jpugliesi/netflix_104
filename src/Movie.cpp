#include "Movie.h"
#include <iostream>

// constructor for a movie with the given title
Movie::Movie(std::string title){
  this->title = title;
}

// copy constructor
Movie::Movie(const Movie & other){

  this->title = other.getTitle();
  this->keywords = other.keywords;

}

//Deconstructor
Movie::~Movie(){
}

// returns the title of the movie
std::string Movie::getTitle() const{
  return title;
}

/* Adds the (free-form) keyword to this movie.
     If the exact same keyword (up to capitalization) was already
     associated with the movie, then the keyword is not added again. */
void Movie::addKeyword(std::string keyword){
  keywords.add(keyword);
}

/* Returns a set of all keywords associated with the movie. */
Set<std::string> Movie::getAllKeywords() const{

  return keywords;
  
}
  


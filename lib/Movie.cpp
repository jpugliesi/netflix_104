#include "Movie.h"
#include <iostream>

// constructor for a movie with the given title
Movie::Movie(std::string title){
  this->title = title;
  title_lower = title;
  for(int i = 0; title_lower[i]; i++) title_lower[i] = tolower(title_lower[i]);

  keywords = new Set<std::string>();
}

// copy constructor
Movie::Movie(const Movie & other){

  this->title = other.getTitle();
  this->keywords = new Set<std::string>(*other.keywords);

}

//Deconstructor
Movie::~Movie(){
}

// returns the title of the movie
std::string Movie::getTitle() const{
  return title;
}

// returns lowercase title
std::string Movie::getLowerTitle() const{
  return title_lower;
}

/* Adds the (free-form) keyword to this movie.
     If the exact same keyword (up to capitalization) was already
     associated with the movie, then the keyword is not added again. */
void Movie::addKeyword(std::string keyword){
  keywords->add(keyword);
}

/* Returns a set of all keywords associated with the movie. */
Set<std::string>* Movie::getAllKeywords() const{

  return keywords;
  
}
  


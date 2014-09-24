#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include "../lib/Set.h"

class Movie {
  public: 
    Movie (std::string title);       // constructor for a movie with the given title

    Movie (const Movie & other);  // copy constructor

    ~Movie ();                  // destructor

    std::string getTitle () const;   // returns the title of the movie

    void addKeyword (std::string keyword); 
      /* Adds the (free-form) keyword to this movie.
         If the exact same keyword (up to capitalization) was already
         associated with the movie, then the keyword is not added again. */

    Set<std::string> getAllKeywords () const;
      /* Returns a set of all keywords associated with the movie. */

  private:
    Set<std::string> keywords;
    std::string title;
};

#endif

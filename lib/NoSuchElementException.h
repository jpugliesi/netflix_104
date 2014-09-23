#ifndef NO_SUCH_ELEMENT_EXCEPTION_H
#define NO_SUCH_ELEMENT_EXCEPTION_H

#include <exception>
#include <stdexcept>

class NoSuchElementException : public std::exception{

  public:
    virtual const char* what() const throw (){ return "No Such Element"; } 

};

#endif

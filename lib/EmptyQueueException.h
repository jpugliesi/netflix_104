#ifndef EMPTY_QUEUE_EXCEPTION_H
#define EMPTY_QUEUE_EXCEPTION_H

#include <exception>
#include <stdexcept>

class EmptyQueueException : public std::exception{

  public:
    virtual const char* what() const throw (){ return "The Queue is empty"; } 

};

#endif

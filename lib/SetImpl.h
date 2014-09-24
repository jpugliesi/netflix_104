#include <exception>
#include <stdexcept>
#include <iostream>
#include "NoSuchElementException.h"

template <class T>
Set<T>::Set(){
}

/* Deep Copy constructor - creates deep copy of parameter set
 *
 */
template <class T>
Set<T>::Set(const Set<T> & other){

  //Deep copy.
  
}

template <class T>
Set<T>::~Set(){
}

template <class T>
Set<T>& Set<T>::operator=(const Set<T>& other){

  if (this == &other) return *this; 
  this->internalStorage = other.internalStorage;
  return *this;

}

template <class T>
int Set<T>::size() const{

  return internalStorage.size();

}

template <class T>
void Set<T>::add(T item){

  internalStorage.add(item, item);
  
}

template <class T>
void Set<T>::remove(T item){

  if (internalStorage.size() != 0){
    internalStorage.remove(item);
  }
    
}

template <class T>
bool Set<T>::contains(T item) const {

  try{
    internalStorage.get(item);
  } catch (NoSuchElementException &e){
    std::cerr << e.what() << std::endl;
    return false;
  }
  return true;

}

template <class T>
void Set<T>::merge(const Set<T> & other){

  internalStorage.merge(other.internalStorage);
}

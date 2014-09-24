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
  this->internalStorage = other.internalStorage;
  
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
    // element is not in the set
    return false;
  }
  return true;

}

template <class T>
void Set<T>::merge(const Set<T> & other){
  internalStorage.merge(other.internalStorage);
}

/************** Union and Intersection ***************/
template <class T>
Set<T> Set<T>::setUnion(const Set<T> & other) const{
  Set<T> unionSet(other);
  unionSet.merge(*this);
  return unionSet;

}

template <class T>
Set<T> Set<T>::setIntersection(const Set<T> & other) const{

  Set<T> thisCopy(*this);
  Set<T> intersectionSet;
  try{
    thisCopy.first();
    while(true){
      T element = thisCopy.getCurrent();
      if(other.contains(element)){
        intersectionSet.add(element);
      }
      try{
        thisCopy.next();
      } catch (NoSuchElementException &e){
        //End of elements
        break;
      }
    }
  } catch (NoSuchElementException &e){
    // No Elements in the Set
  }

  return intersectionSet;
  
}

/************** Iterator Methods ***************/

/*
 * Set the internal Map's iterator to its first element
 * If the Set (and thus the Map) is empty, the Map first() method
 *  will throw a NoSuchElement Exception
 */
template <class T>
void Set<T>::first(){
  this->internalStorage.first();
}

/*
 * Advance the internal Map's iterator to its next element
 * If there is no next element, the Map next() method
 *   throw a NoSuchElement Exception
 */
template <class T>
void Set<T>::next(){
  this->internalStorage.next();
}


/*
 * Get the current iterator element, from the internalStorage Map
 */
template <class T>
const T & Set<T>::getCurrent(){
  return internalStorage.getCurrentKey();
}

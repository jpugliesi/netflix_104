#include <exception>
#include <stdexcept>
#include <iostream>
#include "NoSuchElementException.h"
#include "MergeSort.h"

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

//Requires a sorted array and a target value
template <class T>
bool Set<T>::containsV(const std::vector<int> & array, int target) const{

  if(binarySearch(array, target, 0, array.size()) != -1){

    return true;

  }

  return false;

}

template <class T>
int Set<T>::binarySearch(const std::vector<int> & array, int target, int lo, int hi) const{

  if(hi < lo){

    return -1;

  }
  int mid = (hi + lo)/2;
  if(target == array[mid]) return mid;
  if(target < array[mid]) return binarySearch(array, target, lo, mid-1);
  return binarySearch(array, target, mid+1, hi);

}

template <class T>
void Set<T>::merge(const Set<T> & other){
  internalStorage.merge(other.internalStorage);
}

/************** Union and Intersection ***************/
template <class T>
Set<T> Set<T>::setUnion(const Set<T> & other) const{
  Set<T> otherSet(other);
  Set<T> thisSet(*this);
  Set<T> unionSet;

  //resultant vectors
  std::vector<T> otherV;
  std::vector<T> thisV;
  Set<T>::Iterator it;

  //copy other over into a vector
  for(it = otherSet.begin(); it != otherSet.end(); ++it){
    otherV.push_back((*it));
  }

  //copy this over into a vector
  for(it = thisSet.begin(); it != thisSet.end(); ++it){
    thisV.push_back((*it));
  }
  
  //Sort the vectors
  thisV = MergeSort::sort(thisV);
  otherV = MergeSort::sort(otherV);

  //if this doesn't contain an element of other, add that element to this (union)
  for(int i = 0; i < otherV.size(); i++){
    if(!containsV(thisV, otherV[i])){
      thisV.push_back(otherV[i]);
    }
  }

  //convert this to a union Set
  for(int i = 0; i < thisV.size(); i++){
    unionSet.add(thisV[i]);
  }

  
  return unionSet;

}

template <class T>
Set<T> Set<T>::setIntersection(const Set<T> & other) const{

  Set<T> otherSet(other);
  Set<T> thisSet(*this);
  Set<T> intersectionSet;

  //vectors for sorting
  std::vector<T> otherV;
  std::vector<T> thisV;
  std::vector<T> intersectionVector;
  Set<T>::Iterator it;

  //copy other over into a vector
  for(it = otherSet.begin(); it != otherSet.end(); ++it){
    otherV.push_back((*it));
  }

  //copy this into a vector
  for(it = thisSet.begin(); it != thisSet.end(); ++it){
    thisV.push_back((*it));
  }
  
  //Sort the vectors
  thisV = MergeSort::sort(thisV);
  otherV = MergeSort::sort(otherV);

  //check if any element of other is in this. If so, add it to the intersection vector
  for(int i = 0; i < otherV.size(); i++){
    if(containsV(thisV, otherV[i])){
      intersectionVector.push_back(otherV[i]);
    }
  }

  //transfer the intersection vector to a Set
  for(int i = 0; i < intersectionVector.size(); i++){
    intersectionSet.add(intersectionVector[i]);
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

/************** NEW Iterator Methods ***************/
template<class T>
Set<T>::Iterator::Iterator(const Set<T>* whom, bool begin){

  whoIBelongTo = whom;
  if (begin){
    mIt = whom->internalStorage.begin();
  } else {
    mIt = whom->internalStorage.end();
  }
  mItend = whom->internalStorage.end();
  
  if(mIt != mItend){
    Pair<T, T> tmp = *mIt;
    currentElement = tmp.first;
  }  
}

template<class T>
Set<T>::Iterator::Iterator(){

  whoIBelongTo = NULL;

}
template<class T>
T Set<T>::Iterator::operator*() const{

  return currentElement;

}

template<class T>
typename Set<T>::Iterator Set<T>::Iterator::operator++(){

  //Note that this doesn't account for where mIt != mItend
  ++mIt;
  try{
    Pair<T, T> tmp = *mIt;
    currentElement = tmp.first;
  } catch (NoSuchElementException &e){
    //error, user should not be iterating like this 
  }  
  return *this;  
}

template<class T>
typename Set<T>::Iterator Set<T>::Iterator::operator=(const Set<T>::Iterator & other){

  currentElement = other.currentElement;
  mIt = other.mIt;
  mItend = other.mItend;
  whoIBelongTo = other.whoIBelongTo;

  return *this;

}

template<class T>
bool Set<T>::Iterator::operator==(const typename Set<T>::Iterator & other) const{

  return (mIt == other.mIt && whoIBelongTo == other.whoIBelongTo);

}

template<class T>
bool Set<T>::Iterator::operator!=(const typename Set<T>::Iterator & other) const{

  return !(*this == other);

}

template<class T>
typename Set<T>::Iterator Set<T>::begin() const{

  return Set<T>::Iterator(this, true);

}

template<class T>
typename Set<T>::Iterator Set<T>::end() const{

  return Set<T>::Iterator(this, false);

}


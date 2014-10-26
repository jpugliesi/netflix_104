#include <exception>
#include <iostream>
#include <stdexcept>
#include "NoSuchElementException.h"

template<class keyType, class valueType>
Map<keyType, valueType>::Map(){
  head = NULL;
  tail = NULL;
  map_size = 0;
  currentItemO = head;
}

/* Deep Copy Constructor - creates a deep copy of parameter array
 *
 *
 */
template<class keyType, class valueType>
Map<keyType, valueType>::Map(const Map<keyType, valueType> & other){

  this->head = NULL;
  this->tail = NULL;
  map_size = 0;
  
  for(MapItem<keyType, valueType>* item = other.head; item != NULL; item = item->next){
    this->add(item->key, item->value);
  }

}

template<class keyType, class valueType>
Map<keyType, valueType>::~Map(){
  
  MapItem<keyType, valueType> *p = head, *q = NULL;
  while(p != NULL){

    q = p->next;
    delete p;
    p = q;

  }

}

template<class keyType, class valueType>
Map<keyType, valueType>& Map<keyType, valueType>::operator=(const Map<keyType, valueType>& other){
  if (this == &other) return *this;
  MapItem<keyType, valueType> *p = head, *q = NULL;
  while(p != NULL){
    q = p->next;
    delete p;
    p = q;
  }
  
  //set appropriate size
  map_size = other.map_size;
  this->head = NULL;
  this->tail = NULL;

  //add all of other's map elements to this one
  for(MapItem<keyType, valueType>* item = other.head; item != NULL; item = item->next){
    this->add(item->key, item->value);
  }

  return *this;
  
}

template<class keyType, class valueType>
int Map<keyType, valueType>::size() const{
  //return map_size;
  int count = 0;
  for(MapItem<keyType, valueType> * p = head; p != NULL; p=p->next){
    count++;
  }
  return count;
}

template<class keyType, class valueType>
void Map<keyType, valueType>::add(keyType key, valueType value){
  bool success = false;
  this->getMapItem(key, success);

  if(!success){
    MapItem<keyType, valueType> * item = new MapItem<keyType, valueType>;
    item->key = key;
    item->value = value;
    if (head == NULL){
    
      item->prev = head;
      item->next = tail;
      head = item;
      tail = item;
      
    } else {

      item->prev = NULL;
      item->next = head;
      item->next->prev = item;
      head = item;

    }
    
    this->map_size++;
  } 

}

template<class keyType, class valueType>
void Map<keyType, valueType>::remove(keyType key){

  bool success = false;
  MapItem<keyType, valueType> * tempItem = getMapItem(key, success);

  if(success){
    if(tempItem == head){
      head = tempItem->next;
    } else {
      tempItem->prev->next = tempItem->next;
    }
    if(tempItem->next != NULL){
      tempItem->next->prev = tempItem->prev;
    }else{
      tail = tempItem->prev;
    }
    this->map_size--;

    delete tempItem;
  }
}


template<class keyType, class valueType>
const valueType & Map<keyType, valueType>::get(const keyType & key) const {
  
  for (MapItem<keyType, valueType> * p = head; p != NULL; p = p->next){
    if (key == p->key){
      return p->value;
    }
  }

  throw NoSuchElementException();

}

template<class keyType, class valueType>
void Map<keyType, valueType>::merge(const Map<keyType, valueType> & other){

  bool success = false;
  for(MapItem<keyType, valueType> * p = other.head; p != NULL; p = p->next){
    MapItem<keyType, valueType> * ownItem = this->getMapItem(p->key, success);
    if (!success){
      //The Item doesn't exist in our map, so we'll add it.
      this->add(p->key, p->value);
    }
    success = false;
  }
  
}

template<class keyType, class valueType>
MapItem<keyType, valueType>* Map<keyType, valueType>::getMapItem(keyType key, bool & success) const{
  
  MapItem<keyType, valueType> * item = NULL;
  success = false;
  
  for (MapItem<keyType, valueType> * p = head; p != NULL; p = p->next){
      if (key == p->key){
        item = p;
        success = true;
      }
  }
  return item;
  
}

//ghetto iterator

template<class keyType, class valueType>
void Map<keyType, valueType>::first(){

  if (this->size() > 0){
    //The Map isn't empty
    currentItemO = head;
    return;
  }
  //If the map is empty, throw an exception
  throw NoSuchElementException();
  
}

template<class keyType, class valueType>
void Map<keyType, valueType>::next(){

  if (currentItemO->next != NULL){
    currentItemO = currentItemO->next;
    return;
  }
  throw NoSuchElementException();

}

template<class keyType, class valueType>
const keyType & Map<keyType, valueType>::getCurrentKey (){
  if (currentItemO != NULL){
    return currentItemO->key;
  }
  throw NoSuchElementException();

}

template<class keyType, class valueType>
const valueType & Map<keyType, valueType>::getCurrentValue (){
  if (currentItemO != NULL){
    return currentItemO->value;
  }
  throw NoSuchElementException();
  
}

//Real Iterator
template<class keyType, class valueType>
Map<keyType, valueType>::Iterator::Iterator(const Map<keyType, valueType>* whom, MapItem<keyType, valueType>* item){

  currentItem = item;
  if (currentItem != NULL){
    currentPair = new Pair<keyType, valueType>(currentItem->key, currentItem->value);
  } else {
    currentPair = NULL;
  }
  whoIBelongTo = whom;

}

//Generic Constructor for Map Iterator
//Defaults to NULL, head
template<class keyType, class valueType>
Map<keyType, valueType>::Iterator::Iterator(){
  currentItem = NULL;
  currentPair = NULL;
  whoIBelongTo = NULL;
}

// return the current (key, value) pair the iterator is at
template<class keyType, class valueType>
Pair<keyType, valueType> Map<keyType, valueType>::Iterator::operator* () const{

  if (currentPair != NULL){
    return *currentPair;
  } else {
    //Prevent returning a NULL pair value
    throw NoSuchElementException();
  }
  
}

// advances the iterator (pre-increment)
template<class keyType, class valueType>
typename Map<keyType,valueType>::Iterator Map<keyType, valueType>::Iterator::operator++ (){

  currentItem = currentItem->next;
  delete currentPair;
  if (currentItem != NULL){
    currentPair = new Pair<keyType, valueType>(currentItem->key, currentItem->value);
  } else {
    currentPair = NULL;
  }
  return *this;

}

// assigns the other iterator to this iterator and returns this
template<class keyType, class valueType>
typename Map<keyType,valueType>::Iterator Map<keyType, valueType>::Iterator::operator= (const Map<keyType,valueType>::Iterator & other){

  currentItem = other.currentItem;
  currentPair = other.currentPair;
  whoIBelongTo = other.whoIBelongTo;
  
  return *this;
  
}

// returns whether this iterator is equal to the other iterator
template<class keyType, class valueType>
bool Map<keyType, valueType>::Iterator::operator== (const typename Map<keyType,valueType>::Iterator & other) const{

  return ((currentItem == other.currentItem) && (whoIBelongTo == other.whoIBelongTo));

}

template<class keyType, class valueType>
bool Map<keyType, valueType>::Iterator::operator!= (const typename Map<keyType,valueType>::Iterator & other) const{

  return !(*this == other);

}

// returns an iterator initialized to the first element
template<class keyType, class valueType>
typename Map<keyType,valueType>::Iterator Map<keyType,valueType>::begin () const{

  return Map<keyType, valueType>::Iterator(this, head);

}

/* returns an iterator initialized past the last element,
to designate that the end of the map has been reached. */
template<class keyType, class valueType>
typename Map<keyType,valueType>::Iterator Map<keyType,valueType>::end () const{

  return Map<keyType, valueType>::Iterator(this, NULL);

}

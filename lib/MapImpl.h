#include <exception>
#include <iostream>
#include <stdexcept>
#include "NoSuchElementException.h"

template<class keyType, class valueType>
Map<keyType, valueType>::Map(){
  head = NULL;
  tail = NULL;
  map_size = 0;
  currentItem = head;
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

template<class keyType, class valueType>
void Map<keyType, valueType>::first(){

  if (this->size() > 0){
    //The Map isn't empty
    currentItem = head;
    return;
  }
  //If the map is empty, throw an exception
  throw NoSuchElementException();
  
}

template<class keyType, class valueType>
void Map<keyType, valueType>::next(){

  if (currentItem->next != NULL){
    currentItem = currentItem->next;
    return;
  }
  throw NoSuchElementException();

}

template<class keyType, class valueType>
const keyType & Map<keyType, valueType>::getCurrentKey (){
  if (currentItem != NULL){
    return currentItem->key;
  }
  throw NoSuchElementException();

}

template<class keyType, class valueType>
const valueType & Map<keyType, valueType>::getCurrentValue (){
  if (currentItem != NULL){
    return currentItem->value;
  }
  throw NoSuchElementException();
  
}

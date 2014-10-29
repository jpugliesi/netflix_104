#include "EmptyQueueException.h"

template <class T>
Queue<T>::Queue(){
  head = NULL;
  tail = NULL;
  size = 0;
}

template <class T>
Queue<T>::Queue(const Queue<T> & other){
  head = NULL;
  tail = NULL;

  Node<T>* tmp = other.head;
  while(tmp != 0){
    this->enqueue(tmp->getItem());
    tmp = tmp->getNext();
  }
  size = other.size;
}

template <class T>
Queue<T>::~Queue(){

  while(head != 0){
    Node<T>* toDelete = head;
    head = head->getNext();

    toDelete->setNext(0);
    delete toDelete;
  }
  
}


/* adds the item to the end of the queue.
   The same item may be added many times. */
template <class T>
void Queue<T>::enqueue(const T & item){

  Node<T>* newItem = new Node<T>(item, NULL);
  
  if(size == 0){
    head = newItem;
  } else {
    tail->setNext(newItem);
  }
  tail = newItem;
  size++;

   

}

/* removes the front element of the queue. 
     Throws an EmptyQueueException when called on an empty queue.
     EmptyQueueException should inherit from std::exception. */
template <class T>
void Queue<T>::dequeue(){

  if(size != 0){

    Node<T>* toDelete = head;
    head = head->getNext();

    toDelete->setNext(0);
    delete toDelete;
    size--;


  } else {

    throw EmptyQueueException();
    
  }

}
  
     
/* returns the front element of the queue. 
     Throws an EmptyQueueException when called on an empty queue.
     EmptyQueueException should inherit from std::exception. */
template <class T>
const T & Queue<T>::peekFront (){

  if(size != 0){

    return head->getItem();
    
  } else {
  
    throw EmptyQueueException();
    
  }

}

/* returns whether the queue is empty. */
template <class T>
bool Queue<T>::isEmpty (){

  if(size == 0) return true;
  return false;
}

#ifndef NODE_H
#define NODE_H

template<class ItemType>
class Node{

  private:
    ItemType item;
    Node<ItemType>* next;

  public:
    Node();
    Node(const ItemType& item);
    Node(const ItemType& item, Node<ItemType>* nextNode);
    void setItem(const ItemType& item);
    void setNext(Node<ItemType>* nextNode);
    const ItemType& getItem() const;
    Node<ItemType>* getNext() const;

};
#include "NodeImp.h"
#endif

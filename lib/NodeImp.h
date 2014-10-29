template<class ItemType>
Node<ItemType>::Node(){
  this->item = 0;
  next = 0;
}

template<class ItemType>
Node<ItemType>::Node(const ItemType& item){
  this->item = item;
  next = 0;
}

template<class ItemType>
Node<ItemType>::Node(const ItemType& item, Node<ItemType>* nextNode){

  this->item = item;
  next = nextNode;

}

template<class ItemType>
void Node<ItemType>::setItem(const ItemType& item){

  this->item = item;

}

template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNode){

  next = nextNode;

}

template<class ItemType>
const ItemType& Node<ItemType>::getItem() const{

  return this->item;

}

template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const{

  return next;

}

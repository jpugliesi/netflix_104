#ifndef _MAP_H
#define _MAP_H

template <class keyType, class valueType>
struct MapItem
{
  keyType key;
  valueType value;
  MapItem<keyType, valueType> *prev, *next;
};


template <class keyType, class valueType>
class Map
{
  public:
    Map ();  // constructor for a new empty map
    Map (const Map<keyType, valueType> & other); //deep copy constructor

    ~Map (); // destructor

    Map<keyType, valueType>& operator=(const Map<keyType, valueType>& other); // =

    int size () const; // returns the number of key-value pairs

    void add (const keyType key, const valueType value); 
      /* Adds a new association between the given key and the given value.
         If the key already has an association, it should do nothing.
      */

    void remove (const keyType key);
     /* Removes the association for the given key.
        If the key has no association, it should do nothing. */

    const valueType & get (const keyType & key) const;
     /* Returns the value associated with the given key.
        If the key existed in the map, success should be set to true.
        If the key has no association, it should set success to false. */

    const keyType & getCurrentKey ();
    const valueType & getCurrentValue ();

    void merge (const Map<keyType, valueType> & other);
     /* Adds all the key-value associations of other to the current map.
        If both maps (this and other) contain an association for the same
        key, then the one of this is used. */

    /* Traversal Methods */

    void first();
    void next();

  private:
     /* The head and tail of the linked list you're using to store
        all the associations. */

     MapItem <keyType, valueType> *head, *tail;

     int map_size;

     MapItem<keyType, valueType> * getMapItem(keyType key, bool & success) const;
     
     MapItem<keyType, valueType> * currentItem;

};

#include "MapImpl.h"
#endif

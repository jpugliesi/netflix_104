#ifndef SET_H
#define SET_H

#include "Map.h"

template <class T>
class Set
{
  public:
    Set ();  // constructor for a new empty set
    Set (const Set<T> & other); //deep copy constructor

    ~Set (); // destructor

    Set& operator=(const Set<T>& other);

    int size () const; // returns the number of elements in the set

    void add (const T item); 
      /* Adds the item to the set.
         If the item is already in the set, it should do nothing.
      */

    void remove (const T item);
     /* Removes the item from the set.
        If the item was not in the set, it should do nothing. */

    bool contains (const T item) const;
     /* Returns whether the item is in the set. */

    void merge (const Set<T> & other);
     /* Adds all elements of other to this set. 
        However, will not create duplicates, i.e., it ignores elements
        already in the set. */

    /* Union and Intersection Methods */
    Set<T> setUnion (const Set<T> & other) const;
    // Returns the union of this and other. Does not alter this.

    Set<T> setIntersection (const Set<T> & other) const;
    // Returns the intersection of this and other. Does not alter this.

    /* Iterator functions */
    void first();
    void next();
    const T & getCurrent();

  private:
    Map<T, T> internalStorage;
     /* You should use a Map (your own implementation) to store your set.
        It is part of your assignment to figure out what types you 
        need for the keyType and valueType. */

     /* If you like, you can add further data fields and private
        helper methods. */
        
};

#include "SetImpl.h"
#endif

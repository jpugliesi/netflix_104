#include <iostream>
#include <string>
#include <vector>
#include "Set.h"
#include "MergeSort.h"
#include "Map.h"
#include "Movie.cpp"
#include "User.cpp"
#include "Queue.h"
#include "NoSuchElementException.h"

int main(){

  std::cout << std::endl << "Basic Construction, Add, and Get Methods" << std::endl;
  std::cout << "------------------------------" << std::endl << std::endl;

  std::cout << "------- Sets -------" << std::endl << std::endl;
  Set<int> s1, s2;
  //Add 1-9 to set s1
  std::cout << "Add 1-9 to Set1" << std::endl;
  for(int i = 0; i < 10; i++){
    s1.add(i);
    std::cout << "S1 contains " << i << ": " << s1.contains(i) << std::endl;
  }

  std::cout << "Add 11-19 to Set2" << std::endl;
  for(int i = 11; i < 20; i++){
    s2.add(i);
    std::cout << "S2 contains " << i << ": " << s2.contains(i) << std::endl;
  }

  std::cout << "Assign s2 to s1 (i.e. s1=s2)" << std::endl;
  s1 = s2;

  for(int i = 0; i < 20; i++){
    std::cout << "S1 contains " << i << ": " << s1.contains(i) << std::endl;
  }

  std::cout << std::endl << "------- Maps -------" << std::endl << std::endl;
  Map<int, int> m1, m2;

  //Add 1-9 to set m1
  std::cout << "Add 1-9 to Map1" << std::endl;
  for(int i = 0; i < 10; i++){
    m1.add(i, i);
    try{
      std::cout << "M1 key: " << i << " value: " << m1.get(i) << std::endl;
    } catch (NoSuchElementException &e){
      std::cout << e.what() << std::endl;
    }
  }

  std::cout << "Add 11-19 to Map2" << std::endl;
  for(int i = 11; i < 20; i++){
    m2.add(i, i);
    try{
      std::cout << "M2 key: " << i << " value: " << m2.get(i) << std::endl;
    } catch (NoSuchElementException &e){
      std::cout << e.what() << std::endl;
    }

  }

  std::cout << "Assign m2 to m1 (i.e. m1=m2)" << std::endl;
  m1 = m2;

  for(int i = 0; i < 20; i++){
    try{
      std::cout << "M1 key: " << i << " value: " << m1.get(i) << std::endl;
    } catch (NoSuchElementException &e){
      std::cout << e.what() << std::endl;
    }
  }

  std::cout << std::endl << "-------- Iterator Tests ---------" << std::endl << std::endl;
  
  std::cout << "Creating an empty Map" << std::endl;
  Map<int, int> emptyMap;
  try{
    std::cout << "Try to set the iterator to first (should throw an exception since its empty)" << std::endl;
    emptyMap.first();
    std::cout << "Then we'll try to access its next item (again should throw an exception)" << std::endl;
    emptyMap.next();
  } catch (NoSuchElementException &e){
    std::cerr << e.what() << std::endl;
    std::cout << "The empty map is empty!!" << std::endl;
  }

  std::cout << "Creating an empty Set" << std::endl << std::endl;
  Set<int> emptySet;
  try{
    std::cout << "Try to set the iterator to first (should throw an exception since its empty)" << std::endl;
    emptySet.first();
  } catch (NoSuchElementException &e){
    std::cerr << e.what() << std::endl;
  }

  std::cout << std::endl << "Working Iterator Tests" << std::endl;
  std::cout << "------------------------------" << std::endl << std::endl;

  std::cout << "Iterate through the map1" << std::endl;
  m1.first();
  while(true){
    std::cout << "Key: " << m1.getCurrentKey() << " Value: " << m1.getCurrentValue() << std::endl;
    try{
      m1.next();
    } catch (NoSuchElementException &e){
      std::cerr << e.what() << std::endl;
      break;
    }
  }

  try{
    s1.first();
  } catch (NoSuchElementException &e){  
    std::cout << "Oops this shouldn't have an exception..." << std::endl;
  }
  while(true){
    std::cout << s1.getCurrent() << std::endl;
    try{
      s1.next();
    } catch (NoSuchElementException &e){
      std::cerr << e.what() << std::endl;
      break;
    }
  }

  std::cout << std::endl << "Deep Copy Tests" << std::endl;
  std::cout << "------------------------------" << std::endl << std::endl;

  std::cout << "Maps first. The Original contains:" << std::endl;
  Map<int, int> theOriginal;
  for(int i = 0; i < 10; i++){
    theOriginal.add(i, i);
    std::cout << "Key: " << i << " Value: " << theOriginal.get(i) << std::endl;
  }
  std::cout << "The Original's final size: " << theOriginal.size() << std::endl;

  
  std::cout << "Do the copy. The Copy contains:" << std::endl;
  Map<int, int> theCopy(theOriginal);
  for(int i = 0; i < 10; i++){
    std::cout << "Key: " << i << " Value: " << theCopy.get(i) << std::endl;
  }
  std::cout << "The copy's final size: " << theCopy.size() << std::endl;

  std::cout << std::endl << "Empty copy tests (These should be size=0)" << std::endl;
  Map<int, int> theOriginal2;
  std::cout << "The Original's size: " << theOriginal2.size() << std::endl;
  Map<int, int> theCopy2(theOriginal2);
  std::cout << "The Copy's size: " << theCopy2.size() << std::endl;


  std::cout << std::endl << "Now Sets. The Original contains:" << std::endl;
  Set<int> theOriginalSet;
  for(int i = 0; i < 10; i++){
    theOriginalSet.add(i);
    std::cout << "Set contains: " << theOriginalSet.contains(i) << std::endl;
  }
  std::cout << "The Original's final size: " << theOriginalSet.size() << std::endl;

  
  std::cout << "Do the copy. The Copy contains:" << std::endl;
  Set<int> theCopySet(theOriginalSet);
  for(int i = 0; i < 10; i++){
    std::cout << "Copy Set contains: " << i << "? " << theCopySet.contains(i) << std::endl;
  }
  std::cout << "The copy's final size: " << theCopySet.size() << std::endl;

  std::cout << std::endl << "Empty copy tests (these should be size=0)" << std::endl;
  Set<int> theOriginalSet2;
  std::cout << "The Original Set's size: " << theOriginalSet2.size() << std::endl;
  Set<int> theCopySet2(theOriginalSet2);
  std::cout << "The Copy Set's size: " << theCopySet2.size() << std::endl;



  std::cout << std::endl << "Union and Intersection Tests" << std::endl;
  std::cout << "------------------------------" << std::endl << std::endl;

  std::cout << "Start out with two sets that have union and intersection:" << std::endl;

  Set<int> set1, set2;
  for(int i = 0; i < 5; i++){
    set1.add(i);
    std::cout << "Set 1 contains: " << i << std::endl;
  }
  for(int i = 3; i < 10; i++){
    set2.add(i);
    std::cout << "Set 2 contains: " << i << std::endl;
  }

  Set<int> unionSet, intersectionSet;
  unionSet = set1.setUnion(set2);
  intersectionSet = set1.setIntersection(set2);
  std::cout << "The Union of the sets is: (should be 0-9)" << std::endl;
  try{
    unionSet.first();
  } catch(NoSuchElementException &e){
    std::cout << e.what() << std::endl;
  }
  while(true){
    std::cout << unionSet.getCurrent() << " ";
    try{
      unionSet.next();
    } catch (NoSuchElementException &e){
      // NO more
      break;
    }
  }
  std::cout << std::endl;

  std::cout << "The Intersection of the sets is: (should be 3, 4)" << std::endl;
  try{
    intersectionSet.first();
  } catch(NoSuchElementException &e){
    std::cout << e.what() << std::endl;
  }
  while(true){
    std::cout << intersectionSet.getCurrent() << " ";
    try{
      intersectionSet.next();
    } catch (NoSuchElementException &e){
      // NO more
      break;
    }
  } 
  std::cout << std::endl;
  



  std::cout << std::endl << "Movie Class Tests" << std::endl;
  std::cout << "------------------------------" << std::endl << std::endl;
  
  Movie movie("Pulp Fiction");
  movie.addKeyword("Comedy");
  movie.addKeyword("Action");
  movie.addKeyword("Violent");
  movie.addKeyword("Dark");
  movie.addKeyword("Awesome");

  std::cout << "Here are " << movie.getTitle() << "'s keywords: " << std::endl;
  Set<std::string> theKeywords = movie.getAllKeywords();
  try{
    theKeywords.first();
  } catch (NoSuchElementException &e){
    std::cerr << e.what() << std::endl;
    std::cerr << "Aparently No keywords for this movie... But there should be!" << std::endl;
  }
  while(true){
    std::cout << "\t" << theKeywords.getCurrent() << std::endl;
    try{
      theKeywords.next();
    } catch (NoSuchElementException &e){
      //No more keywords
      break;
    }
  }
  
  std::cout << std::endl << "New Iterator Tests" << std::endl;
  std::cout << "------------------------------" << std::endl << std::endl;
  std::cout << "Creating map" << std::endl;

  Map<int, std::string> mapA;

  std::cout << "Creating map iterators" << std::endl;

  Map<int, std::string>::Iterator itA, itB;

  std::cout << "Inserting 0 to 5 into mapA" << std::endl;

  mapA.add(0, "zero");
  mapA.add(1, "one");
  mapA.add(2, "two");
  mapA.add(3, "three");
  mapA.add(4, "four");
  mapA.add(5, "five");

  std::cout << "Printing out the contents of mapA" << std::endl;

  for(itA = mapA.begin(); itA != mapA.end(); ++itA) {
    std::cout << "Key: " << (*itA).first << ", Value: " << (*itA).second << std::endl;
  }

  std::cout << "Removing 3 from mapA" << std::endl;

  mapA.remove(3);

  std::cout << "Starting the iterator at the second item in the set" << std::endl;

  itA = mapA.begin();
  itB = itA;
  for(++itB; itB != mapA.end(); ++itB) {
    std::cout << "Key: " << (*itB).first << ", Value: " << (*itB).second << std::endl;
  }

  std::cout << "Creating map" << std::endl;

  Set<int> setA;

  std::cout << "Creating map iterators" << std::endl;

  Set<int>::Iterator itC, itD;

  std::cout << "Inserting 0 to 5 into setA" << std::endl;

  setA.add(0);
  setA.add(1);
  setA.add(2);
  setA.add(3);
  setA.add(4);
  setA.add(5);

  std::cout << "Printing out the contents of setA" << std::endl;
  
  for(itC = setA.begin(); itC != setA.end(); ++itC) {
    std::cout << "Key: " << (*itC) << ", Value: " << (*itC) << std::endl;
  }

  std::cout << "Removing 3 from setA" << std::endl;

  setA.remove(3);

  std::cout << "Starting the iterator at the second item in the set" << std::endl;

  itC = setA.begin();
  itD = itC;
  for(++itD; itD != setA.end(); ++itD) {
    std::cout << "Key: " << (*itD) << ", Value: " << (*itD) << std::endl;
  }

  std::cout << std::endl << "Unit Tests Finished" << std::endl;

  std::cout << std::endl << "MergeSort Tests" << std::endl;
  std::cout << "------------------------------" << std::endl << std::endl;

  std::vector<int> items;
  for(int i = 10; i > 0; i--) items.push_back(i);
  std::vector<int> sorted;
  sorted = MergeSort::sort(items);
  for(int i = 0; i < sorted.size(); i++){
    std::cout << sorted.at(i);
  }
  
  return 0;
}

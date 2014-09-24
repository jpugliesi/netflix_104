#include <iostream>
#include <string>
#include "../lib/Set.h"
#include "../lib/Map.h"
#include "../lib/NoSuchElementException.h"

int main(){

  std::cout << "------- Sets -------" << std::endl << std::endl;
  Set<int> s1, s2;
  //Add 1-9 to set s1
  for(int i = 0; i < 10; i++){
    s1.add(i);
    std::cout << "S1 contains " << i << ": " << s1.contains(i) << std::endl;
  }

  for(int i = 11; i < 20; i++){
    s2.add(i);
    std::cout << "S2 contains " << i << ": " << s2.contains(i) << std::endl;
  }

  s1 = s2;

  for(int i = 0; i < 20; i++){
    std::cout << "S1 contains " << i << ": " << s1.contains(i) << std::endl;
  }

  std::cout << "------- Maps -------" << std::endl << std::endl;
  Map<int, int> m1, m2;

  //Add 1-9 to set m1
  for(int i = 0; i < 10; i++){
    m1.add(i, i);
    try{
      std::cout << "M1 key: " << i << " value: " << m1.get(i) << std::endl;
    } catch (NoSuchElementException &e){
      std::cout << e.what() << std::endl;
    }
  }

  for(int i = 11; i < 20; i++){
    m2.add(i, i);
    try{
      std::cout << "M2 key: " << i << " value: " << m2.get(i) << std::endl;
    } catch (NoSuchElementException &e){
      std::cout << e.what() << std::endl;
    }

  }

  m1 = m2;

  for(int i = 0; i < 20; i++){
    try{
      std::cout << "M1 key: " << i << " value: " << m1.get(i) << std::endl;
    } catch (NoSuchElementException &e){
      std::cout << e.what() << std::endl;
    }
  }

  m1.first();
  while(true){
    std::cout << m1.getCurrentKey() << m1.getCurrentValue() << std::endl;
    try{
      m1.next();
    } catch (NoSuchElementException &e){
      std::cerr << e.what() << std::endl;
      break;
    }
  }
  return 0;
}

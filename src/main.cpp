#include <iostream>
#include <string>
#include "../lib/Set.h"
#include "../lib/Map.h"

int main(){

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

  return 0;
}

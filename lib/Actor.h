#ifndef ACTOR_H
#define ACTOR_H
#include <string>

class Actor{

  public:
    Actor(std::string name, int index){
      this->name = name;
      this->index = index;
    }
    
    std::string getName(){

      return name;

    }
    void setName(std::string name){

      this->name = name;

    }

    int getIndex(){ return index; }

  private:
    int index;
    std::string name;
};

#endif

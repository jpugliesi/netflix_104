#include <utility>

class PairPrioritize{

  public:
    int operator() (const std::pair<int, double>& p1, const std::pair<int, double>& p2){

      return p1.second < p2.second;

    }

};

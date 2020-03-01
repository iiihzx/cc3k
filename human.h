#ifndef HUMAN_H_
#define HUMAN_H_
#include <vector>
#include "pc.h"

class Human: public PC {
  public:
    Human( std::vector<int> pos );
    ~Human();
};

#endif


#ifndef RH_H_
#define RH_H_
#include <vector>
#include "potion.h"

class RH: public Potion {
  public:
    RH(std::vector<int> pos);
    ~RH();
};

#endif


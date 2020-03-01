#ifndef PH_H_
#define PH_H_
#include <vector>
#include <string>
#include "potion.h"

class PH: public Potion {
  public:
    PH(std::vector<int> pos);
    ~PH();
};

#endif


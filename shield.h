#ifndef SH_H_
#define SH_H_
#include <vector>
#include "potion.h"

class SH: public Potion {
  public:
    SH(std::vector<int> pos);
    ~SH();
};

#endif


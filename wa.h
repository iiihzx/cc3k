#ifndef WA_H_
#define WA_H_
#include <vector>
#include "potion.h"

class WA: public Potion {
  public:
    WA(std::vector<int> pos);
    ~WA();
};

#endif


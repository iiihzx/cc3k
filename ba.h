#ifndef BA_H_
#define BA_H_
#include <vector>
#include "potion.h"

class BA: public Potion {
  public:
    BA(std::vector<int> pos);
    ~BA();
};

#endif


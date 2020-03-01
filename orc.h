#ifndef ORC_H_
#define ORC_H_
#include <vector>
#include "pc.h"

class Orc: public PC {
  public:
    Orc(std::vector<int> pos);
    ~Orc();
};

#endif


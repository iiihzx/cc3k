#ifndef BD_H_
#define BD_H_
#include <vector>
#include "potion.h"

class BD: public Potion {
  public:
    BD(std::vector<int> pos);
    ~BD();
};

#endif


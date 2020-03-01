#ifndef FINAL_H_
#define FINAL_H_
#include "enemy.h"
#include "pc.h"
#include <vector>

class FINAL: public Enemy {
  public:
    FINAL(std::vector<int> pos);
    ~FINAL();
};

#endif


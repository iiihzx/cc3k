#ifndef GOBLIN_H_
#define GOBLIN_H_
#include "enemy.h"
#include "pc.h"
#include <vector>
#include <ctime>
#include <memory>

class Goblin: public Enemy {
    bool thief;
  public:
    Goblin(std::vector<int> pos);
    std::string attack(std::shared_ptr<PC> c,bool dlc) override;
    ~Goblin();
};

#endif


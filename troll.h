#ifndef TROLL_H_
#define TROLL_H_
#include "enemy.h"
#include "pc.h"
#include <vector>
#include <ctime>
#include <memory>
#include <cmath>

class Troll: public Enemy {
    public:
    Troll(std::vector<int> pos);
    std::string attack(std::shared_ptr<PC> c,bool dlc) override;
    ~Troll();
};

#endif


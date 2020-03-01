#ifndef VAMPIRE_H_
#define VAMPIRE_H_
#include "enemy.h"
#include "pc.h"
#include <vector>
#include <ctime>
#include <memory>
#include <cmath>

class Vampire: public Enemy {
    public:
    Vampire(std::vector<int> pos);
    std::string attack(std::shared_ptr<PC> c,bool dlc) override;
    ~Vampire();
};

#endif


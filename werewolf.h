#ifndef WEREWOLF_H_
#define WEREWOLF_H_
#include "enemy.h"
#include <vector>

class Werewolf: public Enemy {
    public:
    Werewolf(std::vector<int> pos);
    ~Werewolf();
};

#endif


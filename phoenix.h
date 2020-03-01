#ifndef PHOENIX_H_
#define PHOENIX_H_
#include "enemy.h"
#include <vector>

class Phoenix: public Enemy {
    public:
    Phoenix(std::vector<int> pos);
    ~Phoenix();
    std::string beAttacked(int damage,int re);
};

#endif


#ifndef AS_H_
#define AS_H_
#include "enemy.h"
#include "pc.h"
#include <vector>

class AS: public Enemy {
    public:
    AS(std::vector<int> pos);
    ~AS();
};

#endif


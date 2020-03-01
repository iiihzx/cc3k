#ifndef MIDTERM_H_
#define MIDTERM_H_
#include "enemy.h"
#include "pc.h"
#include <vector>

class MIDTERM: public Enemy {
    public:
    MIDTERM(std::vector<int> pos);
    ~MIDTERM();
};

#endif


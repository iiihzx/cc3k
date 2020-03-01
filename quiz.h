#ifndef QUIZ_H_
#define QUIZ_H_
#include "enemy.h"
#include "pc.h"
#include <vector>

class QUIZ: public Enemy {
    public:
    QUIZ(std::vector<int> pos);
    ~QUIZ();
};

#endif


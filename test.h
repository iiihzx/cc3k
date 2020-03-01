#ifndef TEST_H_
#define TEST_H_
#include "enemy.h"
#include "pc.h"
#include <vector>

class TEST: public Enemy {
    public:
    TEST(std::vector<int> pos);
    ~TEST();
};

#endif


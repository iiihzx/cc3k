#ifndef MERCHANT_H_
#define MERCHANT_H_
#include "enemy.h"
#include <vector>

class Merchant: public Enemy {
    public:
    Merchant(std::vector<int> pos);
    ~Merchant();
};

#endif


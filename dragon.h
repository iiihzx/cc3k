#ifndef DRAGON_H_
#define DRAGON_H_
#include "enemy.h"
#include <vector>
#include <memory>
#include <ctime>
#include <string>
#include <sstream>
#include "gold.h"

class Dragon: public Enemy {
    std::shared_ptr<Gold> Dhoard;
    public:
    Dragon(std::vector<int> pos, std::shared_ptr<Gold> Dhoard);
    ~Dragon();
    std::string beAttacked(int damage, int re) override;
    std::string attack(std::shared_ptr<PC> c,bool dlc) override;
    void setgptr(std::shared_ptr<Gold> Dhoard);
};

#endif


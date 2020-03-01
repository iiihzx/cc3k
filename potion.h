#ifndef POTION_H_
#define POTION_H_
#include <vector>
#include <string>
#include "item.h"

class Potion: public Item {
    int effect;
  public:
    Potion(std::vector<int> pos, std::string name, char diaplay, int effect);
    int geteffect();
};

#endif


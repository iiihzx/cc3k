#ifndef GOLD_H_
#define GOLD_H_
#include <string>
#include <vector>
#include "item.h"

class Gold: public Item {
    int amount;
  public:
    Gold(std::vector<int> pos, std::string name, char display, bool pickable, int amount);
    int getamount() const;
    ~Gold();
};

#endif


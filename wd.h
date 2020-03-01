#ifndef WD_H_
#define WD_H_
#include <vector>
#include "potion.h"

class WD: public Potion {

  public:
    WD(std::vector<int> pos);
    ~WD();
};

#endif


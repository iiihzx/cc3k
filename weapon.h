#ifndef WP_H_
#define WP_H_
#include <vector>
#include "potion.h"

class WP: public Potion {

  public:
    WP(std::vector<int> pos);
    ~WP();
};

#endif


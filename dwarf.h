#ifndef DWARF_H_
#define DWARF_H_
#include <vector>
#include "pc.h"

class Dwarf: public PC {
  public:
    Dwarf( std::vector<int> pos);
    ~Dwarf();
};

#endif


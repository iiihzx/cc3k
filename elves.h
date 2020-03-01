#ifndef ELVES_H_
#define ELVES_H_
#include <vector>
#include "pc.h"

class Elves: public PC{
public:
    Elves( std::vector<int> pos);
    ~Elves();
};

#endif


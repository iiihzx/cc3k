#include<vector>
#include "dwarf.h"
using namespace std;

Dwarf::Dwarf(std::vector<int> pos): 
        PC{pos,100,20,30,0,100,"Dwarf",'@'} {}

Dwarf::~Dwarf() {}


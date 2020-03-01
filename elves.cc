#include<vector>
#include "elves.h"
using namespace std;

Elves::Elves( std::vector<int> pos): 
    PC{pos,140,30,10,0,140,"Elves",'@'} {}

Elves::~Elves() {}


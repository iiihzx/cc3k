#include<vector>
#include "human.h"
using namespace std;

Human::Human( std::vector<int> pos ): 
        PC{pos,140,20,20,0,140,"Human",'@'} {}

Human::~Human() {}


#include <vector>
#include <string>
#include "weapon.h"
using namespace std;

WP::WP(vector<int> pos): 
    Potion{pos, "WP",'%', 10} {}


WP::~WP() {}


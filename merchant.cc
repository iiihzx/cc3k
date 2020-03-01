#include "merchant.h"
#include "enemy.h"
using namespace std;

Merchant::Merchant(vector<int> pos) : Enemy{pos,30,70,5,0,30,"Merchant",'M',false,false} {}
Merchant::~Merchant() {}


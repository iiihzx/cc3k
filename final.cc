#include "final.h"
#include "enemy.h"
using namespace std;

FINAL::FINAL(vector<int> pos) : Enemy{pos,200,80,32,30,200,"FINAL",'f',true,true} {}
FINAL::~FINAL() {}


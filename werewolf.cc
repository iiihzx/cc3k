#include "werewolf.h"
#include "enemy.h"
using namespace std;

Werewolf::Werewolf(vector<int> pos) : Enemy{pos,120,30,5,1,120,"Werewolf",'W',true,false} {}
Werewolf::~Werewolf() {}


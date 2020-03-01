#include "quiz.h"
#include "enemy.h"
using namespace std;

QUIZ::QUIZ(vector<int> pos) : Enemy{pos,125,56,20,10,125,"QUIZ",'q',true,true} {}
QUIZ::~QUIZ() {}


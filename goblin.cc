#include "goblin.h"
using namespace std;

Goblin::Goblin(vector<int> pos) : Enemy{pos,70,5,10,1,70,"Goblin",'N',true,false} {
    srand(time(NULL));
    int num = rand() % 4;
    if (num == 0) {
        thief = true;
    } else {
        thief = false;
    }
}

string Goblin::attack(shared_ptr<PC> c,bool dlc) {
    string re;
    string s=getname();
    srand(time(NULL));
    int temp=rand()%2;
    if(temp==0){
        double attk = getAtk();
        double def_c = c->getDef();
        int damage = ceil((100/(100 + def_c)) * attk);
        re += "You are attacked by " + s + ", lose " + c->beAttacked(damage) + " HP.";
    } else if(temp==1){
        re += s + " miss attack.";
    }
    if (thief == true&&dlc) {
        int num = rand() % 2;
        if (num == 0 && c->getGold() > 0) {
            c->addgold(-1);
            re += " Opps! Goblin steals ONE gold from you!";
        }
    }
    re += "\n";
    return re;
}

Goblin::~Goblin() {}


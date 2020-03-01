#include "vampire.h"
#include "enemy.h"
using namespace std;

Vampire::Vampire(vector<int> pos) : Enemy{pos,50,25,25,1,50,"Vampire",'V',true,false} {}

string Vampire::attack(shared_ptr<PC> c,bool dlc) {
    string re;
    string s=getname();
    srand(time(NULL));
    int temp=rand()%2;
    if(temp==0){
        double attk = getAtk();
        double def_c = c->getDef();
        int damage = ceil((100/(100 + def_c)) * attk);
        int chance = rand() % 3;
        if (chance == 0 && dlc==1) {
            double hp = c->getHP();
            damage += ceil(hp * 0.1);
            re += "You are attacked by " + s + ", lose " + c->beAttacked(damage) + " HP(include stolen health by Vampire).\n";
        } else {
            re += "You are attacked by " + s + ", lose " + c->beAttacked(damage) + " HP.\n";
        }
    } else if(temp==1){
        re += s + " miss attack.\n";
    }
    return re;
}

Vampire::~Vampire() {}


#include "troll.h"
#include "enemy.h"
using namespace std;

Troll::Troll(vector<int> pos) : Enemy{pos,120,25,15,1,120,"Troll",'T',true,false} {}

string Troll::attack(shared_ptr<PC> c,bool dlc) {
    string re;
    string s=getname();
    srand(time(NULL));
    int temp=rand()%2;
    if(temp==0){
        double attk = getAtk();
        double def_c = c->getDef();
        int damage = ceil((100/(100 + def_c)) * attk);
        re += "You are attacked by " + s + ", lose " + c->beAttacked(damage) + " HP.\n";
    } else if(temp==1){
        re += s + " miss attack.\n";
    }
    if(dlc){
    double hp = getHP();
    hp = ceil(hp * 0.1 + hp);
    if (hp > 120) hp = 120;
    setHP(hp);
    re+="Troll recovered, and get 10% HP back. Carry On!\n";
    }
    return re;
}

Troll::~Troll() {}


#include "dragon.h"
#include "enemy.h"
#include "pc.h"
using namespace std;

Dragon::Dragon(vector<int> pos, shared_ptr<Gold> Dhoard): 
    Enemy{pos,150,20,20,0,150,"Dragon",'D',true,false}, Dhoard{Dhoard} {}

Dragon::~Dragon() {}


string Dragon::beAttacked(int damage,int re) {
    string s;
    int temp = getHP() - damage;
    if(temp > 0){
        setHP(temp);
        ostringstream s_temp;
        s_temp << temp;
        s += getname() + " is attacked by pc, " + s_temp.str() + " HP left.\n";
    } else {
        setdead();
        Dhoard->setpickable();
        s += "Dragon is slain.\n";
    }
    return s;
}

string Dragon::attack(shared_ptr<PC> c,bool dlc) {
    string s;
    int dhy = Dhoard->getitempos().front();
    int dhx = Dhoard->getitempos().back();
    int cy = c->getPos().front();
    int cx = c->getPos().back();
    if((dhx == cx && (dhy == cy + 1 || dhy == cy - 1)) || 
       (dhx == cx - 1 && (dhy == cy + 1 || dhy == cy - 1 || dhy == cy)) ||
       (dhx == cx + 1 && (dhy == cy + 1 || dhy == cy - 1 || dhy == cy))) {
        int temp=rand()%2;
        if(temp==0){
        double attk = getAtk();
        double def_c = c->getDef();
        int damage = ceil((100/(100 + def_c)) * attk);
        c->beAttacked(damage);
        ostringstream s_damage;
        s_damage << damage;
        s += getname() + " causes " + s_damage.str() + " damage.\n";
        } else if(temp==1){
            s += getname() + " miss attack.\n";
        }
    }
    return s;
}

void Dragon::setgptr(shared_ptr<Gold> Dhoard){
    this->Dhoard=Dhoard;
}


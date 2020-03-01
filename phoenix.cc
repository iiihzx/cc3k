#include "phoenix.h"
#include "enemy.h"
using namespace std;

Phoenix::Phoenix(vector<int> pos): Enemy{pos,70,5,10,1,70,"Phoenix",'X',true,false} {}

Phoenix::~Phoenix() {}

string Phoenix::beAttacked(int damage,int re) {
    string s;
    int temp = getHP() - damage;
    if(temp > 0){
        setHP(temp);
        ostringstream s_temp;
        s_temp << temp;
        s += getname() + " is attacked by pc, " + s_temp.str() + " HP left.\n";
    } else {
        setdead();
        s += "Phoenix is slain.\n";
        if(re){
        s +="Congratulations,now you have returned to maxHP!\n";
        }
    }
    return s;
}


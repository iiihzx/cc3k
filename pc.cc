#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <cmath>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "pc.h"
#include "gold.h"
#include "potion.h"
#include "enemy.h"
using namespace std;


void PC::setBS(){
    hasBS = 1;
}

string PC::beAttacked(int damage){
    int temp = getHP();
    double damage_change = damage;
    if (hasBS == true) {
        damage_change = ceil(damage_change / 2);
    }
    temp -= damage_change;
    ostringstream s_damage_change;
    s_damage_change << damage_change;
    if (temp <= 0){
        setdead();
    } else {
        setHP(temp);
    }
    return s_damage_change.str();;
}

PC::~PC() {}

vector<int> PC::nextpos(string direction){
    vector<int> new_pos = getPos();
    if (direction == "no"){
        new_pos.at(0)=new_pos.at(0)-1; 
    } else if (direction == "so"){
        new_pos.at(0)=new_pos.at(0)+1;
    } else if (direction == "we"){
        new_pos.at(1)=new_pos.at(1)-1;
    } else if (direction == "ea"){
        new_pos.at(1)=new_pos.at(1)+1;
    } else if (direction == "ne"){
        new_pos.at(0)=new_pos.at(0)-1;
        new_pos.at(1)=new_pos.at(1)+1;
    } else if(direction == "se"){
        new_pos.at(0)=new_pos.at(0)+1;
        new_pos.at(1)=new_pos.at(1)+1;
    } else if(direction == "sw"){
        new_pos.at(0)=new_pos.at(0)+1;
        new_pos.at(1)=new_pos.at(1)-1;
    } else if(direction == "nw"){
        new_pos.at(0)=new_pos.at(0)-1;
        new_pos.at(1)=new_pos.at(1)-1;
    }
    return new_pos;
}

string PC::move(string direction, vector< vector<char> >& textDisplay, vector< shared_ptr<Gold> >& gold, bool DLC) {
    vector<int> next = nextpos(direction);
    char next_c = textDisplay[next.front()][next.back()];
    vector<int> now = getPos();
    string s;
    if (next_c == '.' || next_c == '+' || next_c == '#') {
        if (next_c == '.') {
            textDisplay[next.front()][next.back()] = '@';
            if (((now.front() == 7 || now.front() == 14) && now.back() == 13) ||
                ((now.front() == 7 || now.front() == 9 || now.front() == 13 || now.front() == 18) && now.back() == 43) ||
                ((now.front() == 13 || now.front() == 15) && now.back() == 69) ||
                (now.front() == 4 && (now.back() == 29 || now.back() == 38)) ||
                (now.front() == 20 && (now.back() == 25 || now.back() == 36))) {
                textDisplay[now.front()][now.back()] = '+';
            } else {
                textDisplay[now.front()][now.back()] = '.';
            }
            setPos(next.front(), next.back());
        } else if (next_c == '+') {
            textDisplay[next.front()][next.back()] = '@';
            if ((now.back() == 13 && (now.front() < 14 && now.front() > 7)) ||
                (now.back() == 43 && (now.front() == 8 || (now.front() < 18 && now.front() > 13))) ||
                (now.back() == 69 && now.front() == 14) ||
                (now.front() == 4 && (now.back() < 38 && now.back() > 29)) ||
                (now.front() == 20 && (now.back() < 36 && now.back() > 25))) {
                textDisplay[now.front()][now.back()] = '#';
            } else {
                textDisplay[now.front()][now.back()] = '.';
            }
            setPos(next.front(), next.back());
        } else {
            textDisplay[next.front()][next.back()] = '@';
            if (((now.front() == 7 || now.front() == 14) && now.back() == 13) ||
                ((now.front() == 7 || now.front() == 9 || now.front() == 13 || now.front() == 18) && now.back() == 43) ||
                ((now.front() == 13 || now.front() == 15) && now.back() == 69) ||
                (now.front() == 4 && (now.back() == 29 || now.back() == 38))||
                (now.front() == 20 && (now.back() == 25 || now.back() == 36))) {
                textDisplay[now.front()][now.back()] = '+';
            } else {
                textDisplay[now.front()][now.back()] = '#';
            }
            setPos(next.front(), next.back());
        }
        s += "PC moves ";
        if (direction == "ea") {
            s += "East!\n";
        } else if (direction== "we") {
            s += "West!\n";
        } else if (direction == "so") {
            s += "South!\n";
        } else if (direction == "no") {
            s += "North!\n";
        } else if (direction == "ne") {
            s +=  "NorthEast!\n";
        } else if (direction == "nw") {
            s += "NorthWest!\n";
        } else if (direction == "se") {
            s +=  "SouthEast!\n";
        } else {
            s += "SouthWest!\n";
        }
    } else if (next_c == 'G' || (next_c == 'R' && DLC == true)) {
    
        for (size_t i = 0; i < gold.size(); ++i) {
            vector<int> gold_pos = gold[i]->getitempos();
            if (gold_pos.front() == next.front() && gold_pos.back() == next.back()) {
                if (gold[i]->getpickable() == true) {
                    gold[i]->setitempos(-1, -1);
                    textDisplay[next.front()][next.back()] = '@';
                    if (((now.front() == 7 || now.front() == 14) && now.back() == 13) ||
                        ((now.front() == 7 || now.front() == 9 || now.front() == 13 || now.front() == 18) && now.back() == 43) ||
                        ((now.front() == 13 || now.front() == 15) && now.back() == 69) ||
                        (now.front() == 4 && (now.back() == 29 || now.back() == 38)) ||
                        (now.front() == 20 && (now.back() == 25 || now.back() == 36))) {
                        textDisplay[now.front()][now.back()] = '+';
                    } else {
                        textDisplay[now.front()][now.back()] = '.';
                    }
                    setPos(next.front(), next.back());

                    s += "PC moves ";
                    if (direction == "ea") {
                        s += "East!\n";
                    } else if (direction== "we") {
                        s += "West!\n";
                    } else if (direction == "so") {
                        s += "South!\n";
                    } else if (direction == "no") {
                        s += "North!\n";
                    } else if (direction == "ne") {
                        s +=  "NorthEast!\n";
                    } else if (direction == "nw") {
                        s += "NorthWest!\n";
                    } else if (direction == "se") {
                        s +=  "SouthEast!\n";
                    } else {
                        s += "SouthWest!\n";
                    }
                    s += addgold(gold[i]->getamount());
                } else {
                    s += "Gold is unpickable!\n";
                    s += "Invalid movement!\n";
                }
                if (next_c == 'R') {
                    setAtk(getAtk() * 2);
                    setDef(getDef() * 2);
                    s += "You have enough review. Your attack and defence are doubled.\n";
                }
                break;
            } else continue;
        }
        } else {
        s += "Invalid movement\n";
    }
    return s;
}


string PC::usepotion(string direction, vector< vector<char> >& textDisplay, vector< shared_ptr <Potion> > &potion, bool DLC) {
    string s;
    vector<int> pos_dir = nextpos(direction);
    if (textDisplay[pos_dir.front()][pos_dir.back()] == 'P') {
        for (size_t i = 0; i < potion.size(); ++i) {
            vector<int> po_pos = potion[i]->getitempos();
            if (pos_dir.front() == po_pos.front() && pos_dir.back() == po_pos.back()) {
                if (potion[i]->getitemname() == "RH") {
                    int temp = getHP() + potion[i]->geteffect();
                    if (temp > getmaxHP()) {
                        setHP(getmaxHP());
                    } else {
                        setHP(temp);
                    }
                } else if (potion[i]->getitemname() == "PH") {
                    int temp = 0;
                    if (getname() == "Elves") {
                        temp = getHP() - potion[i]->geteffect();
                        if (temp > getmaxHP()) {
                            setHP(getmaxHP());
                        } else {
                            setHP(temp);
                        }
                    } else {
                        temp = getHP() + potion[i]->geteffect();
                    }
                    if (temp <= 0) {
                        setdead();
                    } else {
                        setHP(temp);
                    }
                } else {
                    int temp = 0;
                    if (potion[i]->getitemname() == "BA" || potion[i]->getitemname() == "WA") {
                        if (getname() == "Elves") {
                            if (potion[i]->getitemname() == "WA") {
                                temp = getAtk() - potion[i]->geteffect();
                                if (temp < 0) temp = 0;
                            } else {
                                temp = getAtk() + potion[i]->geteffect();
                            }
                        } else {
                            temp = getAtk() + potion[i]->geteffect();
                            if (temp < 0) temp = 0;
                        }
                        setAtk(temp);
                    } else {
                        if (getname() == "Elves") {
                            if (potion[i]->getitemname() == "WD") {
                                temp = getDef() - potion[i]->geteffect();
                                if (temp < 0) temp = 0;
                            } else {
                                temp = getDef() + potion[i]->geteffect();
                            }
                        } else {
                            temp = getDef() + potion[i]->geteffect();
                            if (temp < 0) temp = 0;
                        }
                        setDef(temp);
                    }
                }
                textDisplay[pos_dir.front()][pos_dir.back()] = '.';
                potion[i]->setitempos(-1, -1);
                s += getname() + " uses " + potion[i]->getitemname() + " potion!\n";
                break;
            } 
        }
    } else if (DLC == true && textDisplay[pos_dir.front()][pos_dir.back()] == '%') {
        for (size_t i = 0; i < potion.size(); ++i) {
            vector<int> po_pos = potion[i]->getitempos();
            if (pos_dir.front() == po_pos.front() && pos_dir.back() == po_pos.back()) {
                int tempatk= getAtk() + potion[i]->geteffect();
                setAtk(tempatk);
                textDisplay[pos_dir.front()][pos_dir.back()] = '.';
                potion[i]->setitempos(-1, -1);
                s += getname() + " gets a weapon! Atk increases 10 in this floor!\n";
                break;
            }
        }
    } else if (DLC == true && textDisplay[pos_dir.front()][pos_dir.back()] == '&') {
        for (size_t i = 0; i < potion.size(); ++i) {
            vector<int> po_pos = potion[i]->getitempos();
            if (pos_dir.front() == po_pos.front() && pos_dir.back() == po_pos.back()) {
                int tempdef= getDef() + potion[i]->geteffect();
                setDef(tempdef);
                textDisplay[pos_dir.front()][pos_dir.back()] = '.';
                potion[i]->setitempos(-1, -1);
                s += getname() + " gets a shield! Def increases 10 in this floor!\n";
                break;
            }
        }
    } else {
        s += "Invalid action!\n";
    }
    return s;
}

string PC::superpower(){
    string s;
    if(getGold()<5){
        s+="Don't have engouh money, see you next time!\n";
    } else{
        setGold(getGold()-5);
       int temp1=getDef()+10;
       int temp2=getAtk()+10;
       int temp3=getHP()+10;
       setDef(temp1);
       setAtk(temp2);
       if(temp3>getmaxHP()){
           setHP(getmaxHP());
       }  else{
           setHP(temp3);
       }
      s+="Already got superpower!\n";
    }
    return s;
}

string PC::attack(shared_ptr<Enemy> c,bool dlc) {
    if (c->getname() == "Merchant") {
        setAttM();
    }
    double realattack = getAtk();
    double def_c = c->getDef();
    int damage = ceil((100/(100 + def_c)) * realattack);
    if(c->getname()=="Phoenix"&& dlc){
        if(c->getHP()-damage<0){
            srand(time(NULL));
            int temp=rand()%2;
             if(temp==0){
                setHP(getmaxHP());
                return c->beAttacked(damage, 1);
             }
        }
        return c->beAttacked(damage,0);
    }
    return c->beAttacked(damage,0);
}

string PC::addgold(int gold){
    string re;
    string s=this->getname();
    int temp = gold;
    if(s=="Human"||s=="Elves"){
    } else if(s=="Dwarf" && gold > 0){
        temp *= 2;
    } else if(s=="orc" && gold > 0){
        temp=ceil(temp/2);
    }
    if (temp != 0) {
        ostringstream s_temp;
        s_temp << temp;
        re += s + " get " + s_temp.str() + " gold!\n"; 
    }
    this->setGold(temp + getGold());
    return re;
}

void PC::setAttM() {
    attM = true;
}

bool PC::getAttM() const {
    return attM;
}


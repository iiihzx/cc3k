#include "enemy.h"
#include "character.h"
#include "chamber.h"
#include "pc.h"
using namespace std;

Enemy::Enemy(vector<int> pos, int HP, int Atk, int Def, int gold, int maxHP, string name, char display, bool hostile, bool hascompass) : 
Character{pos,HP,Atk,Def,gold,maxHP,name,display}, hostile{hostile}, hascompass{hascompass} {}

Enemy::~Enemy(){}

void Enemy::sethostile(bool state) {
    hostile = state;
}

void Enemy::setcompass() {
    hascompass = true;
}

bool Enemy::gethostile() const{
    return hostile;
}

bool Enemy::getcompass() const{
    return hascompass;
}

string Enemy::beAttacked(int damage,int re){
    string s;
     int temp=getHP()-damage;
      if(temp>0){
        setHP(temp);
        ostringstream s_temp;
        s_temp << temp;
        s += getname() + " is attacked by pc, " + s_temp.str() + " HP left.\n";
      } else {
        s += getname() + " is slain.\n";
        setdead();
    }
    return s;
}
void Enemy::setematk(std::shared_ptr<PC> c){
    if (getname() == "ASSIGNMENT") {
        if (c->getGold() > 2) {
            setAtk(22);
        }
        if (c->getGold() > 5) {
            setAtk(11);
        }
    } else if (getname() == "QUIZ") {
        if (c->getGold() > 12) {
            setAtk(28);
        }
        if (c->getGold() > 15) {
            setAtk(14);
        }

    } else if (getname() == "TEST") {
        if (c->getGold() > 25) {
            setAtk(32);
        }
        if (c->getGold() > 30) {
            setAtk(16);
        }
    } else if (getname() == "MIDTERM") {
        if (c->getGold() > 40) {
            setAtk(36);
        }
        if (c->getGold() > 50) {
            setAtk(18);
        }
    } else if (getname() == "FINAL") {
        if (c->getGold() > 68) {
            setAtk(40);
        }
        if (c->getGold() > 75) {
            setAtk(20);
        }
    }
}

void Enemy::setemdef(std::shared_ptr<PC> c){
    if (getname() == "ASSIGNMENT") {
        if (c->getGold() > 2) {
            setDef(8);
        }
        if (c->getGold() > 5) {
            setDef(4);
        }
    } else if (getname() == "QUIZ") {
        if (c->getGold() > 12) {
            setDef(10);
        }
        if (c->getGold() > 15) {
            setDef(5);
        }
    } else if (getname() == "TEST") {
        if (c->getGold() > 25) {
            setDef(12);
        }
        if (c->getGold() > 30) {
            setDef(6);
    }
    } else if (getname() == "MIDTERM") {
         if (c->getGold() > 40) {
            setDef(14);
        }
        if (c->getGold() > 50) {
            setDef(7);
        }
    } else if (getname() == "FINAL") {
        if (c->getGold() > 68) {
            setDef(16);
        }
        if (c->getGold() > 75) {
            setDef(8);
        }
    }
}


string Enemy::attack(shared_ptr<PC> c,bool dlc){
    if (dlc) {
        setematk(c);
        setemdef(c);
    }
    string re;
    string s=getname();
    srand(time(NULL));
    if((s!="Merchant"&&hostile==1)||(s=="Merchant"&&(c->getAttM()==1))){
        int temp=rand()%2;
        if(temp==0){
            double attk = getAtk();
            double def_c = c->getDef();
            int damage = ceil((100/(100 + def_c)) * attk);
            re += "You are attacked by " + s + ", lose " + c->beAttacked(damage) + " HP.\n";
        } else if(temp==1){
            re += s + " miss attack.\n";
        }
    }
    return re;
}


string Enemy::move(vector<vector<char> >& textdisplay,vector<int> stairpos, shared_ptr<PC> c, bool dlc){
    string re;
    string s=getname();
    int row=getPos().front();
    int col=getPos().back();
    if(textdisplay[row-1][col]=='@'||
            textdisplay[row-1][col+1]=='@'||
            textdisplay[row][col+1]=='@'||
            textdisplay[row+1][col+1]=='@'||
            textdisplay[row+1][col]=='@'||
            textdisplay[row+1][col-1]=='@'||
            textdisplay[row][col-1]=='@'||
            textdisplay[row-1][col-1]=='@'){
            re += attack(c,dlc);
    } else{
        if(s!="Dragon"){
            int det=rand()%8;
            if (det == 0){
                row-=1; 
            } else if (det == 1){
                row+=1;
            } else if (det == 2){
                col-=1;
            } else if (det == 3){
                col+=1;
            } else if (det == 4){
                row-=1;
                col+=1;
            } else if(det == 5){
                row+=1;
                col+=1;
            } else if(det == 6){
                row+=1;
                col-=1;
            } else if(det == 7){
                row-=1;
                col-=1;
            }
            if(textdisplay[row][col]=='.'&&(stairpos.front()!=row||stairpos.back()!=col)){
                char ed=getdisplay();
                textdisplay[getPos().front()][getPos().back()]='.';
                setPos(row,col);
                textdisplay[row][col]=ed;
                if(textdisplay[row-1][col]=='@'||
                    textdisplay[row-1][col+1]=='@'||
                    textdisplay[row][col+1]=='@'||
                    textdisplay[row+1][col+1]=='@'||
                    textdisplay[row+1][col]=='@'||
                    textdisplay[row+1][col-1]=='@'||
                    textdisplay[row][col-1]=='@'||
                    textdisplay[row-1][col-1]=='@'){
                    re += attack(c,dlc);
                }
            }
        }
    }
    return re;
}


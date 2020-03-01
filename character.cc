#include <vector>
#include <string>
#include <memory>
#include "character.h"
using namespace std;

Character::Character(vector<int> pos, int HP, int Atk, int Def, int gold, int maxHP, string name, char display):
    pos{pos}, HP{HP}, Atk{Atk}, Def{Def}, gold{gold}, maxHP{maxHP}, name{name}, display{display}, dead{false} {}

vector<int> Character::getPos() const {
    return pos;
}

void Character::setPos(int y, int x) { // y is row, x is col
    pos[0] = y;
    pos[1] = x;
}

int Character::getHP() const {
    return HP;
}

void Character::setHP(int HP) {
    this->HP = HP;
}

int Character::getGold() const {
    return gold;
}

void Character::setGold(int gold) {
    this->gold = gold;
}

void Character::setAtk(int atk) {
    this->Atk = atk;
}
void Character::setDef(int def) {
    this->Def = def;
}

int Character::getAtk() const {
    return Atk;
}

int Character::getDef() const {
    return Def;
}

int Character::getmaxHP() const {
    return maxHP;
}

char Character::getdisplay() const {
    return display;
}

string Character::getname() const {
    return name;
}

void Character::setdead() {
    dead = true;
}

bool Character::getdead() const {
    return dead;
}


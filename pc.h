#ifndef PC_H_
#define PC_H_
#include <vector>
#include <string>
#include <memory>
#include <sstream>
#include "character.h"

class Gold;
class Potion;
class Enemy;

class PC: public Character {
    bool hasBS;
    bool attM;

  public:
    PC(std::vector<int> pos, int HP, int Atk, int Def, int gold, int maxHP, std::string name, char display):
        Character{pos, HP, Atk, Def, gold, maxHP, name, display}, hasBS{false},attM{false}{};
    virtual ~PC() = 0;
    std::vector<int> nextpos(std::string direction);
    std::string move(std::string direction, std::vector< std::vector<char> >& textDisplay, std::vector<std::shared_ptr<Gold> >& gold, bool DLC);
    std::string usepotion(std::string direction, std::vector< std::vector<char> >& textDisplay, std::vector< std::shared_ptr<Potion> >& potion, bool DLC);
    bool getAttM() const;
    void setAttM();
    std::string addgold(int gold);
    std::string attack(std::shared_ptr<Enemy> c,bool dlc);
    std::string beAttacked(int damage);
    void setBS();
    std::string superpower();
};



#endif


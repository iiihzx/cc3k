#ifndef CHARACTER_H_
#define CHARACTER_H_
#include <vector>
#include <string>
#include <memory>

class Character {
    std::vector<int> pos;
    int HP;
    int Atk;
    int Def;
    int gold;
    int maxHP;
    std::string name;
    char display;
    bool dead;
  protected: 
    void setHP(int HP);
    void setGold(int gold);
    void setdead();
  public:
    Character(std::vector<int> pos, int HP, int Atk, int Def, int gold, int maxHP, std::string name, char display);
    std::vector<int> getPos() const;
    void setPos(int y, int x); // y is row, x is col
    int getHP() const;
    int getAtk() const;
    int getDef() const;
    int getGold() const;
    int getmaxHP() const;
    char getdisplay() const;
    std::string getname() const;
    bool getdead() const;
    void setAtk(int atk);
    void setDef(int def);
};

#endif


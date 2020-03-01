#ifndef ENEMY_H_
#define ENEMY_H_
#include <vector>
#include <string>
#include <memory>
#include <cmath>
#include <iostream>
#include <sstream>
#include "character.h"
class Chamber;
class PC;

class Enemy: public Character {
    bool hostile;
    bool hascompass;
    
  protected:
    void sethostile(bool state);
  
  public:
    Enemy(std::vector<int> pos, int HP, int Atk, int Def, int gold, int maxHP, std::string name, char display, bool hostile, bool hascompass);
    bool gethostile() const;
    ~Enemy();
    bool getcompass() const;
    std::string move(std::vector<std::vector<char> >& textdisplay,std::vector<int> stairpos,std::shared_ptr<PC> c,bool dlc);
    virtual std::string attack(std::shared_ptr<PC> c,bool dlc);
    virtual std::string beAttacked(int damage,int re);
    void setematk(std::shared_ptr<PC> c);
    void setemdef(std::shared_ptr<PC> c);
    void setcompass();
};

#endif


#ifndef FLOOR_H_
#define FLOOR_H_
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include "enemy.h"
#include "chamber.h"
#include "potion.h"
#include "pc.h"
#include "gold.h"
#include "human.h"
#include "dwarf.h"
#include "elves.h"
#include "orc.h"
#include "rh.h"
#include "ph.h"
#include "wa.h"
#include "wd.h"
#include "ba.h"
#include "bd.h"
#include "weapon.h"
#include "student.h"
#include "shield.h"
#include "werewolf.h"
#include "dragon.h"
#include "goblin.h"
#include "merchant.h"
#include "phoenix.h"
#include "troll.h"
#include "vampire.h"
#include "as.h"
#include "quiz.h"
#include "test.h"
#include "midterm.h"
#include "final.h"


class Floor {
    int level;
    int sroom;
    int bslevel;
    bool mapdefault;
    bool DLC = false;
    std::vector<int> stairpos;
    std::vector< std::vector<char> > textdisplay;
    std::shared_ptr<PC> user;
    std::vector< std::shared_ptr<Enemy> > allenemy;
    std::vector< std::shared_ptr<Chamber> > allchamber;
    std::vector< std::shared_ptr<Potion> > allpotion;
    std::vector< std::shared_ptr<Gold> > allgold;
    std::string mapfilename;

  public:
    void setlevel();
    void setmapdefault(bool ismapdefault);
    void genstair();
    void genChamber();
    void genPC(std::string name);
    void genEnemy();
    void genGold();
    void genPotion();
    void prettyprint(std::string s);
    std::string move(std::string direction);
    void setFloor(std::string name, std::string mapfile);
    void resetFloor();
    void cleanFloor();
    std::string use(std::string direction);
    std::string attack(std::string direction);
    void readFloor(std::string name , std::string mapfile);
    int score();
    void win();
    void restart();
    void setdlc();
    std::string sp();
};

#endif


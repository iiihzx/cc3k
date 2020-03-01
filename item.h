#ifndef ITEM_H_
#define ITEM_H_
#include <string>
#include <vector>

class Item {
    std::vector<int> pos;
    std::string name;
    char display;
    bool pickable;

  protected:
    void desetitempos(int y, int x);

  public:
    Item(std::vector<int> pos, std::string name, char display, bool pickable);
    std::string getitemname() const;
    std::vector<int> getitempos() const;
    char getitemdisplay() const;
    bool getpickable() const;
    void setitempos(int y, int x);
    void setpickable();
};

#endif


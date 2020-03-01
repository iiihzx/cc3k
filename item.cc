#include <vector>
#include <string>
#include "item.h"
using namespace std;

Item::Item(vector<int> pos, string name, char display, bool pickable): 
    pos{pos}, name{name}, display{display}, pickable{pickable} {}

string Item::getitemname() const {
    return name;
}

void Item::desetitempos(int y, int x) {
    pos[0] = y;
    pos[1] = x;
}

void Item::setitempos(int y, int x) {
    desetitempos(y, x);
}

vector<int> Item::getitempos() const {
    return pos;
}

char Item::getitemdisplay() const {
    return display;
}

bool Item::getpickable() const {
    return pickable;
}

void Item::setpickable() {
    pickable = true;
}


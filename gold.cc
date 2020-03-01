#include <vector>
#include <string>
#include "gold.h"
using namespace std;

Gold::Gold(vector<int> pos, string name, char display, bool pickable, int amount):
    Item{pos, name, display, pickable}, amount{amount} {}

int Gold::getamount() const {
    return amount;
}

Gold::~Gold() {}


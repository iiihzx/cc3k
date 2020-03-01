#include "potion.h"
#include <string>
#include <vector>
using namespace std;

Potion::Potion(vector<int> pos, string name, char display, int effect):
      Item{pos, name, display, true}, effect{effect} {}

int Potion::geteffect() {
    return effect;
}


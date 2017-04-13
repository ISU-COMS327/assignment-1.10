#ifndef OBJECT_H
#define OBJECT_H
#include <string>
#include "numeric.h"

class Object {
    public:
        char getSymbol();
        int x;
        int y;
        string name;
        string description;
        string type;
        string color;
        int hit_bonus;
        Numeric * damage_bonus;
        int dodge_bonus;
        int defense_bonus;
        int weight;
        int speed_bonus;
        int special_attribute;
        int value;
};
#endif

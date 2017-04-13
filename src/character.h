#ifndef __CHARACTER_H
#define __CHARACTER_H
#include "numeric.h"

class Character {
    public:
        string id;
        int speed;
        int hitpoints;
        Numeric * attack_damage;
        int x;
        int y;
        void damage(int amount);
        bool isAlive();
        bool is(Character * other);
        Character();
};
#endif

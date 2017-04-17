#ifndef __MONSTER_H
#define __MONSTER_H

#include "character.h"

class Monster : public Character{
    public:
        string name;
        string description;
        string color;
        char symbol;
        vector<string> abilities;
        int last_known_player_x;
        int last_known_player_y;
        int decimal_type;

        int getAttackDamage();
        void resetPlayerLocation();
        int getDecimalType();
        Monster() : Character() {}
        ~Monster() {};
};
#endif

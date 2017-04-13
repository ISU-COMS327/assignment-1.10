#include "monster.h"

void Monster :: resetPlayerLocation() {
    last_known_player_x = 0;
    last_known_player_y = 0;
}

int Monster :: getAttackDamage() {
    return attack_damage->roll();
}

int Monster :: getDecimalType() {
    int decimal_type = 0;
    for (size_t i = 0; i < abilities.size(); i++) {
        string ability = abilities[i];
        if (ability.compare("SMART") == 0) {
            decimal_type ++;
        }
        if (ability.compare("TELE") == 0) {
            decimal_type += 2;
        }
        if (ability.compare("TUNNEL") == 0) {
            decimal_type += 4;
        }
        if (ability.compare("ERRATIC") == 0) {
            decimal_type += 8;
        }
    }
    return decimal_type;
}

#include "character.h"
#include "util.h"

void Character :: damage(int amount) {
    hitpoints -= amount;
}

void Character :: regenerateHealth(int turn) {
    int turn_delta = turn - turn_health_regenerated;
    int regen = (max_hitpoints * 0.001) * turn_delta;
    hitpoints = min(hitpoints + regen, max_hitpoints);
    turn_health_regenerated = turn;
}

bool Character :: isAlive() {
    return hitpoints > 0;
}

bool Character :: is(Character * other) {
    return other != NULL && id.compare(other->id) == 0;
}

Character :: Character() {
    id = generateRandomString(40);
    turn_health_regenerated = 0;
}

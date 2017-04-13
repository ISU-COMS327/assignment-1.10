#include "character.h"
#include "util.h"

void Character :: damage(int amount) {
    hitpoints -= amount;
}

bool Character :: isAlive() {
    return hitpoints > 0;
}

bool Character :: is(Character * other) {
    return other != NULL && id.compare(other->id) == 0;
}

Character :: Character() {
    id = generateRandomString(40);
}

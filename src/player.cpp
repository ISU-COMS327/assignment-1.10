#include "player.h"

int Player :: getSpeed() {
    int my_speed = speed;
    for (size_t i = 0; i < equipment.size(); i++) {
        Object * object = equipment[i];
        if (object) {
            my_speed += object->speed_bonus;
        }
    }
    return my_speed;
}

int Player :: getAttackDamage() {
    int damage = attack_damage->roll();
    for (size_t i = 0; i < equipment.size(); i++) {
        Object * object = equipment[i];
        if (object) {
            damage += object->damage_bonus->roll();
        }
    }
    return damage;
}

bool Player :: canPickUpObject() {
    return inventory.size() < (size_t) MAX_INVENTORY_SIZE;
}

void Player :: addObjectToInventory (Object * object) {
    inventory.push_back(object);
}

string Player :: viewInventoryObjectAt(int index) {
    return inventory[index]->description;
}

void Player :: equipObjectAt(int index) {
    Object * object = inventory[index];
    if (object) {
        int equipmentIndex = getIndexToSwapEquipmentWith(object->type);
        Object * equippedObject = equipment[equipmentIndex];
        if (equippedObject) {
            inventory[index] = equippedObject;
        }
        else {
            inventory.erase(inventory.begin() + index);
        }
        equipment[equipmentIndex] = object;
    }
}

int Player :: getIndexToSwapEquipmentWith(string type) {
    vector<int> indexes = getIndexOfEquipmentType(type);
    for (size_t i = 0; i < indexes.size(); i++) {
        int index = indexes[i];
        if (!equipment[index]) {
            return index;
        }
    }
    return indexes[0];
}

vector<int> Player :: getIndexOfEquipmentType(string type) {
    vector<int> indexes;
    if (!type.compare("WEAPON")) {
        indexes.push_back(0);
    }
    if (!type.compare("OFFHAND")) {
        indexes.push_back(1);
    }
    if (!type.compare("RANGED")) {
        indexes.push_back(2);
    }
    if (!type.compare("ARMOR")) {
        indexes.push_back(3);
    }
    if (!type.compare("HELMET")) {
        indexes.push_back(4);
    }
    if (!type.compare("CLOAK")) {
        indexes.push_back(5);
    }
    if (!type.compare("GLOVES")) {
        indexes.push_back(6);
    }
    if (!type.compare("BOOTS")) {
        indexes.push_back(7);
    }
    if (!type.compare("AMULET")) {
        indexes.push_back(8);
    }
    if (!type.compare("LIGHT")) {
        indexes.push_back(9);
    }
    if (!type.compare("RING")) {
        indexes.push_back(10);
        indexes.push_back(11);
    }
    return indexes;
}


int Player :: getNumberOfItemsInInventory() {
    return inventory.size();
}

bool Player :: objectExistsInInventoryAt(int index) {
    if (index < 0 || (size_t) index > inventory.size() - 1) {
        return false;
    }
    return inventory[index] != NULL;
}

Object * Player :: getInventoryItemAt(int index) {
    return inventory[index];
}

int Player :: equipmentSlots() {
    return equipment.size();
}

string Player :: equipmentSlotToString(int index) {
    string type = getEquipmentTypeFromIndex(index);
    string message = type + ": ";
    Object * object = equipment[index];
    if (object) {
        message += object->name;
    }
    else {
        message += "Empty";
    }
    return message;
}

string Player :: getEquipmentTypeFromIndex(int index) {
    if (index == 0) {
        return "WEAPON";
    }
    if (index == 1) {
        return "OFFHAND";
    }
    if (index == 2) {
        return "RANGED";
    }
    if (index == 3) {
        return "ARMOR";
    }
    if (index == 4) {
        return "HELMET";
    }
    if (index == 5) {
        return "CLOAK";
    }
    if (index == 6) {
        return "GLOVES";
    }
    if (index == 7) {
        return "BOOTS";
    }
    if (index == 8) {
        return "AMULET";
    }
    if (index == 9) {
        return "LIGHT";
    }
    if (index == 10 || 11) {
        return "RING";
    }
    return "Unknown";
}

bool Player :: equipmentExistsAt(int index) {
    if (index < 0 || (size_t) index > equipment.size() - 1) {
        return false;
    }
    return equipment[index] != NULL;
}

Object * Player :: getEquipmentAt(int index) {
    return equipment[index];
}

void Player :: takeOffEquipment(int index) {
    Object * item = equipment[index];
    equipment[index] = NULL;
    inventory.push_back(item);
}

void Player :: removeInventoryItemAt(int index) {
    inventory.erase(inventory.begin() + index);
}

Player :: Player() : Character() {
    attack_damage = new Numeric("0+1d4");
    speed = 10;
    hitpoints = 500;
    for (int i = 0; i < 12; i++) {
        equipment.push_back(NULL);
    }
}

Player :: ~Player() {
    inventory.clear();
}

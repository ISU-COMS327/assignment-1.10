#include <iostream>
#include "monster_template.h"
#include "util.h"

using namespace std;

string MonsterTemplate::getName() {
    return name;
}

void MonsterTemplate::setName(string n) {
    name = n;
}

string MonsterTemplate::getDescription() {
    return description;
}

void MonsterTemplate::setDescription(string d) {
    description = d;
}

vector<string> MonsterTemplate::getColors() {
    return colors;
}

void MonsterTemplate::setColors(vector<string> c) {
    colors = c;
}

char MonsterTemplate::getSymbol() {
    return symbol;
}

void MonsterTemplate::setSymbol(char c) {
    symbol = c;
}

Numeric * MonsterTemplate ::getSpeed() {
    return speed;
}

void MonsterTemplate::setSpeed(Numeric * s) {
    speed = s;
}

vector<string> MonsterTemplate::getAbilities() {
    return abilities;
}

void MonsterTemplate::setAbilities(vector<string> a) {
    abilities = a;
}

Numeric * MonsterTemplate::getHitpoints() {
    return hitpoints;
}

void MonsterTemplate::setHitpoints(Numeric * h) {
    hitpoints = h;
}

Numeric * MonsterTemplate::getAttackDamage() {
    return attack_damage;
}


void MonsterTemplate::setAttackDamage(Numeric * a) {
    attack_damage = a;
}

bool MonsterTemplate::isValid() {
    return !name.empty() && !description.empty() && colors.size() > 0 && speed->isValid() \
          && abilities.size() > 0 && hitpoints->isValid() && attack_damage->isValid() \
          && symbol;
}

string MonsterTemplate::toString() {
    return name + "\n" + description + "\n" + symbol + "\n" + vector_to_string(colors)\
           + "\n" + speed->toString() + "\n" + hitpoints->toString()\
           + "\n" + attack_damage->toString();
}

Monster * MonsterTemplate::makeMonster() {
    Monster * m = new Monster();
    m->last_known_player_x = 0;
    m->last_known_player_y = 0;
    m->name = name;
    m->description = description;
    m->color = colors[0];
    m->symbol = symbol;
    m->speed = speed->roll();
    m->abilities = abilities;
    m->hitpoints = hitpoints->roll();
    m->max_hitpoints = m->hitpoints;
    m->decimal_type = 0;
    m->attack_damage = attack_damage;
    return m;
}

MonsterTemplate::MonsterTemplate() {
    name = "";
    description = "";
    colors.clear();
    abilities.clear();
}

MonsterTemplate :: ~MonsterTemplate() {
    colors.clear();
    abilities.clear();
}

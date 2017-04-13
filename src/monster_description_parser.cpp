#include <iostream>
#include <fstream>
#include <string>
#include "util.h"
#include "monster_description_parser.h"

const string NAME_KEYWORD = "NAME";
const string DESC_KEYWORD = "DESC";
const string COLOR_KEYWORD = "COLOR";
const string SPEED_KEYWORD = "SPEED";
const string ABILITIES_KEYWORD = "ABIL";
const string HITPOINTS_KEYWORD = "HP";
const string ATTACK_DAMAGE_KEYWORD = "DAM";
const string SYMBOL_KEYWORD = "SYMB";

MonsterDescriptionParser::MonsterDescriptionParser(string filepath) {
    this->filepath = filepath;
}

void MonsterDescriptionParser::parseFile() {
    vector<MonsterTemplate> new_monsters;
    MonsterTemplate * current_monster = NULL;
    string line;
    ifstream file;
    file.open(filepath);
    if (!file.is_open()) {
        throw "Could not open file";
    }
    getline(file, line);
    if (line.compare("RLG327 MONSTER DESCRIPTION 1") != 0) {
        throw "Invalid first line of file";
    }
    bool exception_raised = false;
    while (getline(file, line)) {
        if (line.compare("BEGIN MONSTER") == 0) {
            current_monster = new MonsterTemplate();
            exception_raised = false;
        }
        else if (exception_raised) {
            continue;
        }
        else {
            try{
                if (starts_with(line, NAME_KEYWORD)) {
                    line.erase(0, (NAME_KEYWORD + " ").length());
                    current_monster->setName(line);
                }
                else if(starts_with(line, DESC_KEYWORD)) {
                    string description = "";
                    while (getline(file, line) && line.compare(".") != 0) {
                        if (line.length() > 77) {
                            throw "Description line too long";
                        }
                        description += line.substr(0, 77) + "\n";
                    }
                    description.erase(description.end() - 1, description.end());
                    current_monster->setDescription(description);
                }
                else if (starts_with(line, COLOR_KEYWORD)) {
                    line.erase(0, (COLOR_KEYWORD + " ").length());
                    current_monster->setColors(split(line, " "));
                }
                else if (starts_with(line, SPEED_KEYWORD)) {
                    line.erase(0, (SPEED_KEYWORD + " ").length());
                    Numeric * speed = new Numeric(line);
                    current_monster->setSpeed(speed);
                }
                else if(starts_with(line, ABILITIES_KEYWORD)) {
                    line.erase(0, (COLOR_KEYWORD + " ").length());
                    current_monster->setAbilities(split(line, " "));
                }
                else if (starts_with(line, HITPOINTS_KEYWORD)) {
                    line.erase(0, (HITPOINTS_KEYWORD + " ").length());
                    Numeric * hp = new Numeric(line);
                    current_monster->setHitpoints(hp);
                }
                else if (starts_with(line, ATTACK_DAMAGE_KEYWORD)) {
                    line.erase(0, (ATTACK_DAMAGE_KEYWORD + " ").length());
                    Numeric * attack = new Numeric(line);
                    current_monster->setAttackDamage(attack);
                }
                else if (starts_with(line, SYMBOL_KEYWORD)) {
                    line.erase(0, (SYMBOL_KEYWORD + " ").length());
                    current_monster->setSymbol(line[0]);
                }
                else if (line.compare("END") == 0) {
                    if (current_monster->isValid()) {
                        new_monsters.push_back(*current_monster);
                    }
                }

            }
            catch(...) {
                exception_raised = true;
            }
        }
    }
    monster_templates = new_monsters;
    file.close();

}

void MonsterDescriptionParser::printMonsters() {
    for (int i = 0; i < monster_templates.size(); i++) {
        cout << monster_templates[i].toString() << endl;
        cout << "\n";
    }
}

vector<MonsterTemplate> MonsterDescriptionParser::getMonsterTemplates() {
    return monster_templates;
}

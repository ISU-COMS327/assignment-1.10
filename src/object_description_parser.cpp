#include <iostream>
#include <fstream>
#include <string>
#include "util.h"
#include "object_description_parser.h"

const string NAME_KEYWORD = "NAME";
const string DESC_KEYWORD = "DESC";
const string TYPE_KEYWORD = "TYPE";
const string COLOR_KEYWORD = "COLOR";
const string HIT_BONUS_KEYWORD = "HIT";
const string DAMAGE_BONUS_KEYWORD = "DAM";
const string DODGE_BONUS_KEYWORD = "DODGE";
const string DEFENSE_BONUS_KEYWORD = "DEF";
const string WEIGHT_KEYWORD = "WEIGHT";
const string SPEED_BONUS_KEYWORD = "SPEED";
const string SPECIAL_ATTRIBUTE_KEYWORD = "ATTR";
const string VALUE_KEYWORD = "VAL";

ObjectDescriptionParser::ObjectDescriptionParser(string filepath) {
    this->filepath = filepath;
}

void ObjectDescriptionParser::parseFile() {
    vector<ObjectTemplate> new_objects;
    ObjectTemplate * current_object = NULL;
    string line;
    ifstream file;
    file.open(filepath);
    if (!file.is_open()) {
        throw "Could not open file";
    }
    getline(file, line);
    if (line.compare("RLG327 OBJECT DESCRIPTION 1") != 0) {
        throw "Invalid first line of file";
    }
    bool exception_raised = false;
    while (getline(file, line)) {
        if (line.compare("BEGIN OBJECT") == 0) {
            current_object = new ObjectTemplate();
            exception_raised = false;
        }
        else if (exception_raised) {
            continue;
        }
        else {
            try{
                if (starts_with(line, NAME_KEYWORD)) {
                    line.erase(0, (NAME_KEYWORD + " ").length());
                    current_object->name = line;
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
                    current_object->description = description;
                }
                else if (starts_with(line, TYPE_KEYWORD)) {
                    line.erase(0, (TYPE_KEYWORD + " ").length());
                    current_object->type = line;
                }
                else if (starts_with(line, COLOR_KEYWORD)) {
                    line.erase(0, (COLOR_KEYWORD + " ").length());
                    current_object->color = line;
                }
                else if (starts_with(line, HIT_BONUS_KEYWORD)) {
                    line.erase(0, (HIT_BONUS_KEYWORD + " ").length());
                    current_object->hit_bonus = new Numeric(line);
                }
                else if (starts_with(line, DAMAGE_BONUS_KEYWORD)) {
                    line.erase(0, (DAMAGE_BONUS_KEYWORD + " ").length());
                    current_object->damage_bonus = new Numeric(line);
                }
                else if (starts_with(line, DODGE_BONUS_KEYWORD)) {
                    line.erase(0, (DODGE_BONUS_KEYWORD + " ").length());
                    current_object->dodge_bonus = new Numeric(line);
                }
                else if (starts_with(line, DEFENSE_BONUS_KEYWORD)) {
                    line.erase(0, DEFENSE_BONUS_KEYWORD.length() + 1);
                    current_object->defense_bonus = new Numeric(line);
                }
                else if(starts_with(line, WEIGHT_KEYWORD)) {
                    line.erase(0, WEIGHT_KEYWORD.length() + 1);
                    current_object->weight = new Numeric(line);
                }
                else if(starts_with(line, SPECIAL_ATTRIBUTE_KEYWORD)) {
                    line.erase(0, SPECIAL_ATTRIBUTE_KEYWORD.length() + 1);
                    current_object->special_attribute = new Numeric(line);
                }
                else if (starts_with(line, VALUE_KEYWORD)) {
                    line.erase(0, VALUE_KEYWORD.length() + 1);
                    current_object->value = new Numeric(line);
                }
                else if (starts_with(line, SPEED_BONUS_KEYWORD)) {
                    line.erase(0, (SPEED_BONUS_KEYWORD + " ").length());
                    Numeric * speed = new Numeric(line);
                    current_object->speed_bonus = speed;
                }
                else if (line.compare("END") == 0) {
                    if (current_object->isValid()) {
                        new_objects.push_back(*current_object);
                    }
                }

            }
            catch(...) {
                exception_raised = true;
            }
        }
    }
    object_templates = new_objects;
    file.close();
}

void ObjectDescriptionParser::printObjects() {
    for (int i = 0; i < object_templates.size(); i++) {
        cout << object_templates[i].toString() << endl;
        cout << "\n";
    }
}

vector<ObjectTemplate> ObjectDescriptionParser::getObjectTemplates() {
    return object_templates;
}

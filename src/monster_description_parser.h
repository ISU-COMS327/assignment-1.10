#include <vector>
#include "monster_template.h"
#include "monster.h"

using namespace std;

class MonsterDescriptionParser {
    private:
        string filepath;
        vector<MonsterTemplate> monster_templates;
    public:
        void parseFile();
        void printMonsters();
        vector<MonsterTemplate> getMonsterTemplates();
        Monster makeMonster();
        MonsterDescriptionParser(string filepath);
        ~MonsterDescriptionParser() {};
};

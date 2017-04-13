#ifndef ODP_H
#define ODP_H
#include <vector>
#include "object_template.h"

using namespace std;

class ObjectDescriptionParser {
    private:
        string filepath;
        vector<ObjectTemplate> object_templates;
    public:
        void parseFile();
        void printObjects();
        vector<ObjectTemplate> getObjectTemplates();
        ObjectDescriptionParser(string filepath);
};
#endif

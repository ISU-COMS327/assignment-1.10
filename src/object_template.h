#ifndef OBJECT_TEMPLATE_H
#define OBJECT_TEMPLATE_H
#include "numeric.h"
#include "object.h"

class ObjectTemplate {
    public:
        Object * makeObject();
        bool isValid();
        string toString();
        string name;
        string description;
        string type;
        string color;
        Numeric * hit_bonus;
        Numeric * damage_bonus;
        Numeric * dodge_bonus;
        Numeric * defense_bonus;
        Numeric * weight;
        Numeric * speed_bonus;
        Numeric * special_attribute;
        Numeric * value;
};
#endif

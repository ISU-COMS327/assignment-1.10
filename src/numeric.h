#ifndef NUMERIC_H
#define NUMERIC_H
#include <vector>
#include <string>

using namespace std;

class Numeric {
    public:
        int base;
        int dice;
        int sides;
        string toString();
        bool isValid();
        int roll();
        Numeric(string);
        Numeric();
        ~Numeric() {};
};

#endif

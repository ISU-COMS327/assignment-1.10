#include "object.h"

char Object :: getSymbol() {
    if (!type.compare("WEAPON")) {
        return '|';
    }
    if (!type.compare("OFFHAND")) {
        return ')';
    }
    if (!type.compare("RANGED")) {
        return '}';
    }
    if (!type.compare("ARMOR")) {
        return '[';
    }
    if (!type.compare("HELMET")) {
        return ']';
    }
    if (!type.compare("CLOAK")) {
        return '(';
    }
    if (!type.compare("GLOVES")) {
        return '{';
    }
    if (!type.compare("BOOTS")) {
        return '\\';
    }
    if (!type.compare("RING")) {
        return '=';
    }
    if (!type.compare("AMULET")) {
        return '"';
    }
    if (!type.compare("LIGHT")) {
        return '_';
    }
    if (!type.compare("SCROLL")) {
        return '~';
    }
    if (!type.compare("BOOK")) {
        return '?';
    }
    if (!type.compare("FLASK")) {
        return '!';
    }
    if (!type.compare("GOLD")) {
        return '$';
    }
    if (!type.compare("AMMUNITION")) {
        return '/';
    }
    if (!type.compare("FOOD")) {
        return ',';
    }
    if (!type.compare("WAND")) {
        return '-';
    }
    if (!type.compare("CONTAINER")) {
        return '%';
    }
    return '*';
}

#include "priority_queue.h"

int PriorityQueue :: size() {
    return nodes.size();
}

void PriorityQueue :: removeFromQueue(Character * character) {
    int index = -1;
    for (size_t i = 0; i < nodes.size(); i++) {
        Node existing_node = nodes[i];
        if (!existing_node.character->id.compare(character->id)) {
            index = i;
            break;
        }
    }
    if (index >= 0) {
        nodes.erase(nodes.begin() + index);
    }
}

void PriorityQueue :: insertWithPriority(Character * character, int priority) {
    Node node;
    node.character = character;
    node.priority = priority;
    if (nodes.size() == 0) {
        nodes.push_back(node);
        return;
    }
    for (size_t i = 0; i < nodes.size(); i++) {
        Node existing_node = nodes[i];
        if (priority <= existing_node.priority) {
            nodes.insert(nodes.begin() + i, node);
            return;
        }
    }
    nodes.push_back(node);
}

Node PriorityQueue :: extractMin() {
    Node min = nodes[0];
    nodes.erase(nodes.begin());
    return min;
}

void PriorityQueue :: decreasePriority(Character * character, int priority) {
    for (size_t i = 0; i < nodes.size(); i++) {
        Node existing_node = nodes[i];
        if (character->id.compare(existing_node.character->id) == 0) {
            nodes.erase(nodes.begin() + i);
            insertWithPriority(character, priority);
            return;
        }
    }
}

void PriorityQueue :: decreaseCoordPriority(struct Coordinate coord, int priority) {
    Node node;
    node.coord = coord;
    node.priority = priority;
    for (size_t i = 0; i < nodes.size(); i++) {
        Node existing_node = nodes[i];
        if (existing_node.coord.x == coord.x && existing_node.coord.y == coord.y) {
            nodes.erase(nodes.begin() + i);
            insertCoordWithPriority(coord, priority);
            return;
        }
    }

}

void PriorityQueue :: insertCoordWithPriority(struct Coordinate coord, int priority) {
    Node node;
    node.coord = coord;
    node.priority = priority;
    if (nodes.size() == 0) {
        nodes.push_back(node);
        return;
    }
    bool was_added = false;
    for (size_t i = 0; i < nodes.size(); i++) {
        Node existing_node = nodes[i];
        if (priority <= existing_node.priority) {
            nodes.insert(nodes.begin() + i, node);
            was_added = true;
            break;
        }
    }
    if (!was_added) {
        nodes.push_back(node);
    }

}

void PriorityQueue :: clear() {
    nodes.clear();
}

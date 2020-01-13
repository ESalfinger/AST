#include "headers/Node.h"

Node::Node(Node *prev, void *data, Node *next) : prev(prev), next(next), data(data) {}

Node::~Node() {}

void *Node::getData() {
    return data;
}
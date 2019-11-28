//
// Created by Elias Salfinger on 20.11.19.
//

#ifndef DLIST_NODE_H
#define DLIST_NODE_H

class Node {
public:
    Node(Node *prev, void *data, Node *next);

    ~Node();

    void *getData();
private:
    Node *prev;
    Node *next;
    void *data;

    friend class DList;

    friend class DListIterator;
};

#endif //DLIST_NODE_H

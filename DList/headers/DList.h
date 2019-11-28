//
// Created by Elias Salfinger on 20.11.19.
//

#ifndef DLIST_DLIST_H
#define DLIST_DLIST_H

#include "Node.h"
#include "IKey.h"
#include "IFIterator.h"

class DList {
public:
    DList();

    ~DList();

    void prepend(void *data);

    void append(void *data);

    bool insertAfter(void *prev, void *data);

    void *forwardSearch(IKey &key);

    void forwardRemove(void *data);

    void removeDoubles();

    void reverse();

    void printList();

    IFIterator *iterator();

protected:
    Node *tail;
    Node *head;

    void insertAfter(Node *current, void *data);

    Node *forwardSearch(Node *current, IKey &key);

private:
    void removeNode(Node *toRemove);
};

#endif //DLIST_DLIST_H

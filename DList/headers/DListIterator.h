#ifndef DLIST_DLISTITERATOR_H
#define DLIST_DLISTITERATOR_H

#include "IFIterator.h"
#include "Node.h"

class DListIterator : public IFIterator {
public:
    DListIterator(Node *start);

    ~DListIterator();

    virtual bool hasNext();

    virtual void *next();

    Node *current;
};

#endif //DLIST_DLISTITERATOR_H

//
// Created by Elias Salfinger on 20.11.19.
//

#ifndef DLIST_IFITERATOR_H
#define DLIST_IFITERATOR_H

class IFIterator {
public:
    virtual ~IFIterator() = default;

    virtual bool hasNext() = 0;

    virtual void *next() = 0;
};

#endif //DLIST_IFITERATOR_H

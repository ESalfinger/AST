//
// Created by Elias Salfinger on 20.11.19.
//

#ifndef DLIST_POINTERKEY_H
#define DLIST_POINTERKEY_H

#include "IKey.h"

class PointerKey : public IKey {
private:
    void *pointer;

public:
    PointerKey(void *pointer);

    virtual ~PointerKey();

    virtual bool matches(void *data);
};

#endif //DLIST_POINTERKEY_H

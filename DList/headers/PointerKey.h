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

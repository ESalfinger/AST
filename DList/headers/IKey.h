//
// Created by Elias Salfinger on 20.11.19.
//

#ifndef DLIST_IKEY_H
#define DLIST_IKEY_H

class IKey {
public:
    virtual ~IKey() = default;

    virtual bool matches(void *data) = 0;
};
#endif //DLIST_IKEY_H

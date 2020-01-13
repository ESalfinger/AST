//
// Created by Elias Salfinger on 16.12.19.
//

#ifndef CLUBMANAGER_SUPPORTINGMEMBER_H
#define CLUBMANAGER_SUPPORTINGMEMBER_H


#include "Member.h"

class SupportingMember : public Member {
public:
    SupportingMember(string name) : Member(name, 100, 15) {}
};


#endif //CLUBMANAGER_SUPPORTINGMEMBER_H

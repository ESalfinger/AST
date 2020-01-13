//
// Created by Elias Salfinger on 16.12.19.
//

#ifndef CLUBMANAGER_HONORARYMEMBER_H
#define CLUBMANAGER_HONORARYMEMBER_H


#include "Member.h"

class HonoraryMember : public Member{
public:
    HonoraryMember(string name) : Member(name, 0, 20) {}
};


#endif //CLUBMANAGER_HONORARYMEMBER_H

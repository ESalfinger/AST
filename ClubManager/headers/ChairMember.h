//
// Created by Elias Salfinger on 16.12.19.
//

#ifndef CLUBMANAGER_CHAIRMEMBER_H
#define CLUBMANAGER_CHAIRMEMBER_H


#include "Member.h"

class ChairMember : public Member{
public:
    ChairMember(string name, int skill) : Member(name, 0, 0), skill(skill) {}

    double getIncome() override;
    
    double getCosts() override;
private:
    int skill;
};

#endif //CLUBMANAGER_CHAIRMEMBER_H

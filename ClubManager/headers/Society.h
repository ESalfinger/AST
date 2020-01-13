//
// Created by Elias Salfinger on 16.12.19.
//

#ifndef CLUBMANAGER_SOCIETY_H
#define CLUBMANAGER_SOCIETY_H

#include "Member.h"
#include <list>

class Society : public Member{
public:
    Society(string name, const int maxMembers) : Member(name, 0, 0), maxMembers(maxMembers) {}

    void addMember(Member *newMember);

    void removeMember(int memberId);

    double getIncome() override;

    double getCosts() override;

    string toString() override;

private:
    list<Member*> members;
    const int maxMembers;
};
#endif //CLUBMANAGER_SOCIETY_H

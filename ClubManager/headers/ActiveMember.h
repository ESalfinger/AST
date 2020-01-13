//
// Created by Elias Salfinger on 16.12.19.
//

#ifndef CLUBMANAGER_ACTIVEMEMBER_H
#define CLUBMANAGER_ACTIVEMEMBER_H

#include "Member.h"

class ActiveMember : public Member {
public:
    ActiveMember(string name, double fee, double expenses, int activity) : Member(name, fee, expenses), activity(activity) {}

    double getIncome() override;

    double getCosts() override;
private:
    int activity;
};


#endif //CLUBMANAGER_ACTIVEMEMBER_H

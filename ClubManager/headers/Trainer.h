//
// Created by Elias Salfinger on 16.12.19.
//

#ifndef CLUBMANAGER_TRAINER_H
#define CLUBMANAGER_TRAINER_H

#include "ActiveMember.h"

class Trainer : public ActiveMember{
public:
    Trainer(string name, int activity) : ActiveMember(name, 10, activity * 40, activity) {}
};


#endif //CLUBMANAGER_TRAINER_H

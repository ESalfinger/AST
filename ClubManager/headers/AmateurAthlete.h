//
// Created by Elias Salfinger on 16.12.19.
//

#ifndef CLUBMANAGER_AMATEURATHLETE_H
#define CLUBMANAGER_AMATEURATHLETE_H


#include "ActiveMember.h"

class AmateurAthlete : public ActiveMember{
public:
    AmateurAthlete(string name, int activity) : ActiveMember(name, 25, activity * 3.5, activity) {}
};


#endif //CLUBMANAGER_AMATEURATHLETE_H

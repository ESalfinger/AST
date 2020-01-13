//
// Created by Elias Salfinger on 16.12.19.
//

#ifndef CLUBMANAGER_TOPATHLETE_H
#define CLUBMANAGER_TOPATHLETE_H


#include "ActiveMember.h"

class TopAthlete : public ActiveMember{
public:
    TopAthlete(string name, int activity) : ActiveMember(name, 10, activity * 7, activity) {}
};


#endif //CLUBMANAGER_TOPATHLETE_H

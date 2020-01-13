//
// Created by Elias Salfinger on 16.12.19.
//

#include "headers/ActiveMember.h"

double ActiveMember::getIncome() {
    return Member::getIncome() * 12;
}

double ActiveMember::getCosts() {
    return Member::getCosts() * 12;
}

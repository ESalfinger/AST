//
// Created by Elias Salfinger on 16.12.19.
//

#include "headers/ChairMember.h"

double ChairMember::getIncome() {
    return skill * 100;
}

double ChairMember::getCosts() {
    return getIncome() * 0.15;
}

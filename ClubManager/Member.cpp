#include "headers/Member.h"
#include <sstream>
#include <iomanip>

int Member::memberCount = 0;

double Member::getIncome() {
    return fee;
}

double Member::getCosts() {
    return expenses;
}

double Member::getSurplus() {
    return getIncome() - getCosts();
}

string Member::toString() {
    stringstream s;
    s << getMNumber() << " Name: " << name <<
    " Income: " << fixed << setprecision(2) << getIncome() <<
    " Costs: " << fixed << setprecision(2) << getCosts() <<
    " Surplus: " << fixed << setprecision(2) << getSurplus();
    return s.str();
}

const string &Member::getName() const {
    return name;
}

int Member::getMNumber() const {
    return mNumber;
}

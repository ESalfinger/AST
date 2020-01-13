#include "headers/Society.h"
#include <iomanip>
#include <sstream>

void Society::addMember(Member *newMember) {
    if (members.size() < maxMembers) {
        members.push_back(newMember);
    } else {
        cout << getName() + " can't have more than " + to_string(maxMembers) + " members!" << endl;
    }
}

void Society::removeMember(int memberId) {
    members.remove_if([memberId](const Member * val) {
        return val->getMNumber() == memberId;
    });
}

double Society::getIncome() {
    double income = 0;

    for (Member *m : members) {
        income += m->getIncome();
    }

    return income;
}

double Society::getCosts() {
    double costs = 0;

    for (Member *m : members) {
        costs += m->getCosts();
    }

    return costs;
}

string Society::toString() {
    stringstream s;
    s << getName() << " (" + to_string(members.size()) << " members) Income: "
    << fixed << setprecision(2) << getIncome() <<
    " Costs: " << fixed << setprecision(2) << getCosts() <<
    " Surplus: " << fixed << setprecision(2) << getSurplus() << "\n";

    for (Member *m : members)
        s << "\t" + m->toString() + "\n";

    string str = s.str();

    if (!str.empty() && str[str.length()-1] == '\n') {
        str.erase(str.length()-1);
    }

    return str;
}

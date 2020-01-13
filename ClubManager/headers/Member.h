//
// Created by Elias Salfinger on 16.12.19.
//

#ifndef CLUBMANAGER_MEMBER_H
#define CLUBMANAGER_MEMBER_H

#include <string>
#include <iostream>

using namespace std;

class Member {
public:
    static int memberCount;

    Member(string name, double fee, double expenses) : name(name), fee(fee), expenses(expenses) {
        mNumber = ++memberCount;
    }

    const string &getName() const;

    int getMNumber() const;

    virtual ~Member() = default;

    virtual double getIncome();

    virtual double getCosts();

    double getSurplus();

    virtual string toString();
private:
    string name;
    int mNumber;
    double fee;
    double expenses;
};

#endif //CLUBMANAGER_MEMBER_H

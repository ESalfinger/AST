//
// Created by Elias Salfinger on 19.12.19.
//

#ifndef CALENDAR_DATE_H
#define CALENDAR_DATE_H

#include <ostream>

class Date {
public:
    Date(int day, int month, int year) : day(day), month(month), year(year) {}

    virtual ~Date() = default;

    void setDate(int day, int month, int year);

    int getDay() const {
        return day;
    }

    int getMonth() const {
        return month;
    }

    int getYear() const {
        return year;
    }

    bool operator==(const Date &rhs);

    bool operator!=(const Date &rhs);

    bool operator<(const Date &rhs) const;

    bool operator<=(const Date &rhs);

    bool operator>(const Date &rhs);

    bool operator>=(const Date &rhs);

    Date &operator++();

    Date operator++(int);

    Date &operator--();

    Date operator--(int);

    Date &operator+=(int numDays);

    Date &operator-=(int numDays);

    std::string toString();

protected:
    int day;
    int month;
    int year;

private:
    int toDays() const;

    Date toDate(int days) const;
};

std::ostream &operator<<(std::ostream &out, const Date &date);

#endif //CALENDAR_DATE_H

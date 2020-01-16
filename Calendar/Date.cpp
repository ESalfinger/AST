//
// Created by Elias Salfinger on 19.12.19.
//

#include "headers/Date.h"

int Date::toDays() const {
    return year * 366 + month * 30 + day;
}

Date Date::toDate(int days) const {
    int tYear = days / 366;
    days -= tYear * 366;

    int tMonth = days / 30;
    days -= tMonth * 30;

    return Date(days, tMonth, tYear);
}

void Date::setDate(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

bool Date::operator==(const Date &rhs) {
    return toDays() == rhs.toDays();
}

bool Date::operator!=(const Date &rhs) {
    return toDays() != rhs.toDays();;
}

bool Date::operator<(const Date &rhs) const{
    return toDays() < rhs.toDays();
}

bool Date::operator<=(const Date &rhs) {
    return toDays() <= rhs.toDays();
}

bool Date::operator>(const Date &rhs) {
    return toDays() > rhs.toDays();
}

bool Date::operator>=(const Date &rhs) {
    return toDays() >= rhs.toDays();
}

Date &Date::operator++() {
    int days = toDays();
    Date d = toDate(++days);
    setDate(d.getDay(), d.getMonth(), d.getYear());
    return *this;
}

Date Date::operator++(int) {
    Date tmp(day, month, year);

    ++(*this);

    return tmp;
}

Date &Date::operator--() {
    int days = toDays();
    Date d = toDate(--days);
    setDate(d.getDay(), d.getMonth(), d.getYear());
    return *this;
}

Date Date::operator--(int) {
    Date tmp(day, month, year);

    --(*this);

    return tmp;
}

Date &Date::operator+=(int numDays) {
    int days = toDays();
    Date d = toDate(days + numDays);
    setDate(d.getDay(), d.getMonth(), d.getYear());
    return *this;
}

Date &Date::operator-=(int numDays) {
    int days = toDays();
    Date d = toDate(days - numDays);
    setDate(d.getDay(), d.getMonth(), d.getYear());
    return *this;
}

std::string Date::toString() {
    return std::to_string(day) + "." + std::to_string(month) + "." + std::to_string(year);
}

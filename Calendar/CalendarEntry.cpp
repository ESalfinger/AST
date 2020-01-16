//
// Created by Elias Salfinger on 19.12.19.
//

#include "headers/CalendarEntry.h"

CalendarEntry::CalendarEntry(int day, int month, int year, const std::string &text) : date(day, month, year),
                                                                                      text(text) {}

CalendarEntry::CalendarEntry(const Date &date, const std::string &text) : date(date), text(text) {}

CalendarEntry::~CalendarEntry() {}

void CalendarEntry::setText(const std::string &text) {
    this->text = text;
}

bool CalendarEntry::operator<(const CalendarEntry &rhs) const{
    return date < rhs.date;
}

std::ostream &operator<<(std::ostream &out, CalendarEntry &entry) {
    out << entry.getDate().toString() << "-" << entry.getText();
    return out;
}
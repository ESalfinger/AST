//
// Created by Elias Salfinger on 19.12.19.
//

#ifndef CALENDAR_CALENDARENTRY_H
#define CALENDAR_CALENDARENTRY_H

#include <iostream>
#include "Date.h"

class CalendarEntry {
public:

    CalendarEntry(int day, int month, int year, const std::string &text);

    CalendarEntry(const Date &date, const std::string &text);

    virtual ~CalendarEntry();

    Date &getDate() { return date; }

    const std::string &getText() const { return text; }

    void setText(const std::string &text);

    bool operator<(const CalendarEntry &rhs) const;

private:
    Date date;
    std::string text;
};

// output operator
std::ostream &operator<<(std::ostream &out, CalendarEntry &entry);

#endif //CALENDAR_CALENDARENTRY_H

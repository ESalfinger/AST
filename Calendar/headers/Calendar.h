//
// Created by Elias Salfinger on 19.12.19.
//

#ifndef CALENDAR_CALENDAR_H
#define CALENDAR_CALENDAR_H

#include <vector>
#include "CalendarEntry.h"

class Calendar {
public:
    Calendar();

    virtual ~Calendar();

    void addEntry(const Date &date, const std::string &text);

    void clear();

    void print();

    bool containsEntry(const std::string text) const;

    CalendarEntry *getEntry(const std::string &text);

private:
    std::vector<CalendarEntry> entries;
};


#endif //CALENDAR_CALENDAR_H

//
// Created by Elias Salfinger on 19.12.19.
//
#include "headers/Calendar.h"

Calendar::Calendar() {}

Calendar::~Calendar() {
    clear();
}

void Calendar::addEntry(const Date &date, const std::string &text) {
    CalendarEntry entry(date, text);
    entries.push_back(entry);
}

void Calendar::clear() {
    entries.clear();
}

void Calendar::print() {
    std::sort(entries.begin(), entries.end());

    for (unsigned int i = 0; i < entries.size(); i++) {
        std::cout << entries[i] << std::endl;
    }
}

bool Calendar::containsEntry(const std::string text) const {
    for (unsigned int i = 0; i < entries.size(); i++) {
        if (entries[i].getText() == text) {
            return true;
        }
    }

    return false;
}

CalendarEntry *Calendar::getEntry(const std::string &text) {
    for (unsigned int i = 0; i < entries.size(); i++) {
        if (entries[i].getText() == text) {

            return &entries[i];
        }
    }
    return nullptr;
}

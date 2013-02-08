#ifndef EVENTCLEANER_H
#define EVENTCLEANER_H

#include <string>
#include <iostream>
#include "Event.h"


class CleanerException {
public:
    explicit CleanerException(std::string m) : error(m) {}
    std::string message() { return error; }
private:
    std::string error;
};


class EventCleaner {
public:
    virtual Event clean(Event) const = 0;
};


class BuyCleaner : public EventCleaner {
public:
    Event clean(Event) const;
};

#endif

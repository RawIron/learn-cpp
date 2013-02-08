#ifndef EVENTCLEANERFACTORY_H
#define EVENTCLEANERFACTORY_H

#include <boost/smart_ptr/shared_ptr.hpp>
#include <string>
#include <iostream>
#include "EventCleaner.h"
#include "Task.h"


class EventCleanerFactory {
public:
    static boost::shared_ptr<EventCleaner> createFrom(Task) throw (CleanerException);
};

#endif

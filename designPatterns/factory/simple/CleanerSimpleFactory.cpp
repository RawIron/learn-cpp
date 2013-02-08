#include <string>
#include <iostream>
#include "CleanerSimpleFactory.h"
#include "EventCleaner.h"


boost::shared_ptr<EventCleaner> EventCleanerFactory::createFrom(Task t)
throw (CleanerException) {
    boost::shared_ptr<EventCleaner> c(new BuyCleaner());
    if (t.eventCollection == "test") {
        return c;
    }
    CleanerException e = CleanerException("no matching cleaner");
    throw e;
}


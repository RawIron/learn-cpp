#include <boost/smart_ptr/shared_ptr.hpp>
#include <string>
#include <iostream>
#include "CleanerSimpleFactory.h"
#include "EventCleaner.h"
#include "Event.h"
#include "Task.h"


int main() {
    boost::shared_ptr<EventCleaner> c;
    Task t = {"test"};
    Task s = {"bad task"};
    Event e = {1};

    try {
        c = EventCleanerFactory::createFrom(t);
        e = c->clean(e);
        std::cout << e.id;
        c = EventCleanerFactory::createFrom(s);
    } catch (CleanerException e) {
        std::cout << e.message();
    }
}


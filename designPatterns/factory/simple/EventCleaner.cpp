#include <string>
#include <iostream>
#include "EventCleaner.h"
#include "Event.h"


Event BuyCleaner::clean(Event e) const {
    e.id = 3;
    return e;
}


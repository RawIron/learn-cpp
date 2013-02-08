#ifndef OBSERVERINTERFACE_H
#define OBSERVERINTERFACE_H
#include "Event.h"

class ObserverInterface {
    public:
    virtual void deliver(Event event) = 0;
};

#endif

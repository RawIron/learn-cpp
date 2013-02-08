#ifndef OBSERVER_H
#define OBSERVER_H
#include "ObserverInterface.h"
#include "Event.h"

class Observer : public ObserverInterface {
    public:
    void deliver(Event event);
    void print() const;
    private:
    Event delivered;
};

#endif

#include "Observer.h"

void Observer::deliver(Event e) {
    delivered = e;
    print();
}

void Observer::print() const {
    delivered.print();
}

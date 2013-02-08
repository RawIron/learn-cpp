#include <vector>
#include "Event.h"
#include "Observable.h"


void Observable::subscribe(ObserverInterface *o) {
    std::vector<ObserverInterface*>::iterator it;
    it = observers.begin();
    it = observers.insert(it, o);
    return;
}

void Observable::unsubscribe(ObserverInterface *o) {
    std::vector<ObserverInterface*>::iterator it;
    for (it=observers.begin(); it<observers.end(); it++) {
        if ((*it) == o) {
            observers.erase(it);
        }
    }
    return;
}

void Observable::notify() {
    Event e;
    std::vector<ObserverInterface*>::iterator it;
    for (it=observers.begin(); it<observers.end(); it++) {
        (*it)->deliver(e);
    }
    return;
}

int Observable::countObservers() const {
    return observers.size();
}

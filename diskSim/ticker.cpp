#include <iostream>
#include <vector>

#include "ticker.h"


void Ticker::tick() {
    ++ticks;
    notifyAll();
}
void Ticker::tick(int nTimes) {
    ticks += nTimes;
    notifyAll();
}
int Ticker::currentTick() const {
    return ticks;
}


void Ticker::subscribe(TicListener* observer) {
    observers.push_back(observer);
}

void Ticker::unsubscribe(TicListener* observer) {
    for (oIterator it = observers.begin(); it != observers.end(); ++it) {
        if (*it == observer) {
            observers.erase(it);
            break;
        }
    }
}

bool Ticker::has(TicListener* observer) const {
    for (cIterator it = observers.begin(); it != observers.end(); ++it) {
        if (*it == observer) {
            return true;
        }
    }
    return false;
}

void Ticker::notifyAll() {
    for (oIterator it = observers.begin(); it != observers.end(); ++it) {
        (*it)->update(ticks);
    }
    for (oIterator it = observers.begin(); it != observers.end(); ++it) {
        (*it)->trigger();
    }
}


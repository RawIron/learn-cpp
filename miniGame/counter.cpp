#include "counter.h"

Counter::Counter() :current(0), totalIn(0), totalOut(0) {
}

int Counter::increase() {
    return ++current;
}

int Counter::increase(int quantity) {
    current += quantity;
    return current;
}

int Counter::getCurrent() {
    return current;
}

Counter counterFactory() {
    return Counter();
}

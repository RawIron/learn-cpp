#include <iostream>
#include "Observer.h"
#include "Observable.h"

int main() {
    int oc;
    Observer o;
    Observable counter;

    oc = counter.countObservers();
    std::cout << oc;
    counter.subscribe(&o);
    counter.subscribe(&o);

    counter.notify();
    oc = counter.countObservers();
    std::cout << oc;

    counter.unsubscribe(&o);
    counter.unsubscribe(&o);
    oc = counter.countObservers();
    std::cout << oc;
}


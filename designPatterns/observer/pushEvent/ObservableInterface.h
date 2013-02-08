#ifndef OBSERVABLEINTERFACE_H
#define OBSERVABLEINTERFACE_H
#include "ObserverInterface.h"

class ObservableInterface {
    public:
    virtual void subscribe(ObserverInterface *o) = 0;
    virtual void unsubscribe(ObserverInterface *o) = 0;
    virtual void notify() = 0;
};

#endif

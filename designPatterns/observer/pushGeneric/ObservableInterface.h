#ifndef OBSERVABLEINTERFACE_H
#define OBSERVABLEINTERFACE_H
#include "ObserverInterface.h"

template <typename TYPE>
class ObservableInterface {
    public:
    virtual void subscribe(ObserverInterface<TYPE> *o) = 0;
    virtual void unsubscribe(ObserverInterface<TYPE> *o) = 0;
    virtual void notify(TYPE) = 0;
};

#endif

#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <list>
#include "ObserverInterface.h"
#include "ObservableInterface.h"


template <typename TYPE>
class Observable : public ObservableInterface<TYPE> {
    public:
    virtual void subscribe(ObserverInterface<TYPE> *o);
    virtual void unsubscribe(ObserverInterface<TYPE> *o);
    virtual void notify(TYPE event);
    private:
    std::list<ObserverInterface<TYPE>* > observers;
    typename std::list<ObserverInterface<TYPE>* >::iterator it;
};


template <typename TYPE>
void Observable<TYPE>::notify(TYPE event) {
    for (it = observers.begin(); it != observers.end(); it++) {
        (*it)->deliverNews(event);
    }
}

template <typename TYPE>
void Observable<TYPE>::subscribe(ObserverInterface<TYPE> *o) {
    it = observers.begin();
    it = observers.insert(it, o);
}

template <typename TYPE>
void Observable<TYPE>::unsubscribe(ObserverInterface<TYPE> *o) {
    for (it = observers.begin(); it != observers.end(); it++) {
        if ((*it) == o) {
            it = observers.erase(it);
        }
    }
}

#endif

#ifndef OBSERVABLE_H
#define OBSERVABLE_H
#include <vector>
#include "ObserverInterface.h"
#include "ObservableInterface.h"

class Observable : public ObservableInterface {
    public:
    void subscribe(ObserverInterface *o);
    void unsubscribe(ObserverInterface *o);
    void notify();
    int countObservers() const;
    private:
    std::vector<ObserverInterface*> observers;
};

#endif

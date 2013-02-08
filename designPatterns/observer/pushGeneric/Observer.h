#ifndef OBSERVER_H
#define OBSERVER_H
#include <iostream>
#include <queue>
#include "ObserverInterface.h"


template <typename T> class Observer;
template <typename T> void listNews(Observer<T>&);

template <typename TYPE>
class Observer : public ObserverInterface<TYPE> {
    public:
    virtual void deliverNews(TYPE message);
    friend void listNews<TYPE>(Observer<TYPE> &o);
    private:
    std::queue<TYPE> delivered;
};


template <typename TYPE>
void Observer<TYPE>::deliverNews(TYPE message) {
    delivered.push(message);
    return;
};


template <typename TYPE>
void listNews(Observer<TYPE> &o) {
    while (!o.delivered.empty()) {
        std::cout << o.delivered.front();
        o.delivered.pop();
    }
}

#endif

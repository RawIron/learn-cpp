#include <iostream>
#include <vector>


#ifndef __TICKER__
#define __TICKER__

#include "tickerListener.h"
class TicListener;

class Ticker {
    public:
    Ticker() : ticks(0) {}
    virtual ~Ticker() {}
    void subscribe(TicListener*);
    void unsubscribe(TicListener*);
    bool has(TicListener*) const;
    void notifyAll();

    void tick();
    void tick(int nTimes);
    int currentTick() const;

    private:
    int ticks;
    std::vector<TicListener*> observers;
    typedef std::vector<TicListener*>::iterator oIterator;
    typedef std::vector<TicListener*>::const_iterator cIterator;
};

#endif

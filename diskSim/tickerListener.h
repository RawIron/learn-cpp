#include <iostream>
#include <vector>

#ifndef __TICKERLISTENER__
#define __TICKERLISTENER__

#include "ticker.h"
class Ticker;

class TicListener {
    public:
    TicListener() : ticker(nullptr), ticks(0), key(0) {}
    explicit TicListener(int assigned) : ticker(nullptr), ticks(0), key(assigned) {}
    virtual ~TicListener() {}
    void subscribeAt(Ticker* t);
    void update(int ticks);
    int latestTick() const;
    virtual void trigger() = 0;
    friend bool operator==(const TicListener& lhs, const TicListener& rhs);

    private:
    Ticker* ticker;
    int ticks;
    int key;
};

#endif

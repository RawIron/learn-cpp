#include <iostream>
#include <vector>

#include "tickerListener.h"

void TicListener::subscribeAt(Ticker* t) {
    ticker = t;
    ticker->subscribe(this);
}
void TicListener::update(int clockTicks) {
    ticks = clockTicks;
}
int TicListener::latestTick() const {
    return ticks;
}

bool operator==(const TicListener& lhs, const TicListener& rhs) {
    return (lhs.key == rhs.key);
}


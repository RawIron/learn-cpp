#include <iostream>
#include <string>

#include "player.h"
#include "achievement.h"
#include "counter.h"


void initPlayer();
void initAchievement();
void initCounter();

int main() {
    std::string message("Game starts");
    std::cout << message <<std::endl;

    initPlayer();
    initAchievement();
    initCounter();
}


void initPlayer() {
    Player pl = playerFactory();
    pl.levelUp();
    if (pl.overLevel(1)) {
        dumpPlayer(pl);
    }
}

void initAchievement() {
    Achievement am = achievementFactory("BigRunner");
    am.achieved();
    am.achieved(2);
    if (am.gotAward()) {
        std::cout << "got " << am.getName() << std::endl;
    }
}

void initCounter() {
    Counter c = counterFactory();
    c.increase();
    c.increase(2);
    if (c.getCurrent()) {
        std::cout << "got " << c.getCurrent() << std::endl;
    }
}


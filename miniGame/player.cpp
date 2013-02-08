#include <iostream>
#include <assert.h>
#include "player.h"


Player::Player() : name("batman"), level(1) {
}

std::string Player::getName() {
    return name;
}

bool Player::levelUp() {
    assert(level>0);
    ++level;
    return true;
}

bool Player::overLevel(int required) {
    assert(required>0);
    return (level >= required);
}


Player playerFactory() {
    return Player();
}

void dumpPlayer(const Player& player) {
    std::cout << player.getName() <<std::endl;
}


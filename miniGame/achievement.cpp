#include "achievement.h"

Achievement::Achievement(std::string itemName)
:name(itemName),counter(0),threshold(3) {
}

std::string Achievement::getName() {
    return name;
}

int Achievement::achieved() {
    return ++counter;
}

int Achievement::achieved(int count) {
    counter += count;
    return counter;
}

bool Achievement::gotAward() {
    return (counter >= threshold);
}


Achievement achievementFactory(std::string name) {
    return Achievement(name);
}

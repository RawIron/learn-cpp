#ifndef ACHIEVEMENT_H
#define ACHIEVEMENT_H

#include <string>

class Achievement {
    public:
    explicit Achievement(std::string);
    std::string getName();
    int achieved();
    int achieved(int);
    bool gotAward();

    private:
    std::string name;
    int counter;
    int threshold;
};

Achievement achievementFactory(std::string);

#endif

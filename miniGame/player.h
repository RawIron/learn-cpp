#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
    public:
    explicit Player();
    std::string getName();
    bool levelUp();
    bool overLevel(int);

    private:
    std::string name;
    long id;
    int level;
};

Player playerFactory();
void dumpPlayer(const Player&);

#endif

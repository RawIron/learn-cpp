#include <iostream>
#include "Plant.h"
#include "LinearGrowth.h"


int main() {
    GrowBehavior *g;
    g = new LinearGrowth();
    Plant p(g);
    std::cout << g->grow();
    std::cout << p.grow();
}


#include "Plant.h"

Plant::Plant(GrowBehavior *g): grows(g), growth(0.0) {}

double Plant::grow() {
    return grows->grow();
}


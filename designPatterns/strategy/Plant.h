#ifndef PLANT_H
#define PLANT_H

#include <string>
#include "GrowBehavior.h"


class Plant {
    public:
    explicit Plant(GrowBehavior*);
    double grow();

    private:
    std::string name;
    GrowBehavior *grows;
    double growth;
};

#endif

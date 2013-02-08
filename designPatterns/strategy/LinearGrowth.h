#ifndef LINEARGROWTH_H
#define LINEARGROWTH_H

#include "GrowBehavior.h"


class LinearGrowth : public GrowBehavior {
    public:
    double grow() const;
};

#endif

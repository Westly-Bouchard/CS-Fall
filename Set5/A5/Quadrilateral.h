#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

#include "Polygon.h"

class Quadrilateral : public Polygon {
    public:
        Quadrilateral();
};

class Rhombus : public Quadrilateral {
    public:
        bool validate() override;
};

#endif

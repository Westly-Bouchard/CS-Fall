#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Polygon.h"

class Triangle : public Polygon {
    public:
        Triangle();
};

class ScaleneTriangle : public Triangle {
    public:
        bool validate() override;
};

class IsoscelesTriangle : public Triangle {
    public:
        bool validate() override;
};

class EquilateralTriangle : public Triangle {
    public:
        bool validate() override;
};

#endif

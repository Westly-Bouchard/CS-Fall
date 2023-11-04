
#include "Quadrilateral.h"
#include "Triangle.h"

#include <iostream>
using namespace std;

Quadrilateral::Quadrilateral() {
    this->numVertices = 4;
    this->vertices = new Coordinate[4];
}

bool Rhombus::validate() {
    float side1 = calcLength(vertices[0], vertices[1]);
    float side2 = calcLength(vertices[1], vertices[2]);
    float side3 = calcLength(vertices[2], vertices[3]);
    float side4 = calcLength(vertices[3], vertices[0]);

    IsoscelesTriangle t1;
    t1.setCoordinate(0, vertices[0]);
    t1.setCoordinate(1, vertices[1]);
    t1.setCoordinate(2, vertices[2]);

    IsoscelesTriangle t2;
    t2.setCoordinate(0, vertices[0]);
    t2.setCoordinate(1, vertices[2]);
    t2.setCoordinate(2, vertices[3]);

    return (
        t1.validate() && t2.validate() &&
        side1 == side2 && side2 == side3 && side3 == side4
    );
}

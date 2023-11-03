
#include "Quadrilateral.h"
#include "Triangle.h"

Quadrilateral::Quadrilateral() {
    this->numVertices = 4;
    this->vertices = new Coordinate[4];
}

bool Rhombus::validate() {
    double side1 = calcLength(vertices[0], vertices[1]);
    double side2 = calcLength(vertices[1], vertices[2]);
    double side3 = calcLength(vertices[2], vertices[3]);
    double side4 = calcLength(vertices[3], vertices[0]);

    Triangle t1;
    t1.setCoordinate(0, vertices[0]);
    t1.setCoordinate(1, vertices[1]);
    t1.setCoordinate(2, vertices[2]);

    Triangle t2;
    t2.setCoordinate(0, vertices[0]);
    t2.setCoordinate(1, vertices[2]);
    t2.setCoordinate(2, vertices[3]);

    return (
        t1.validate() && t2.validate() &&
        side1 == side2 && side2 == side3 && side3 == side4
    );
}

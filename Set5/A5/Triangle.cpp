
#include "Coordinate.h"
#include "Triangle.h"

bool isTriangle(const double side1, const double side2, const double side3);

Triangle::Triangle() {
    this->numVertices = 3;
    this->vertices = new Coordinate[3];
}

bool ScaleneTriangle::validate() {
    double side1 = calcLength(vertices[0], vertices[1]);
    double side2 = calcLength(vertices[1], vertices[2]);
    double side3 = calcLength(vertices[2], vertices[0]);

    return (
        isTriangle(side1, side2, side3) &&
        side1 != side2 &&
        side1 != side3 &&
        side3 != side2
    );
}

bool IsoscelesTriangle::validate() {
    double side1 = calcLength(vertices[0], vertices[1]);
    double side2 = calcLength(vertices[1], vertices[2]);
    double side3 = calcLength(vertices[2], vertices[0]);

    return (
        isTriangle(side1, side2, side3) && (
            side1 == side2 || side1 == side3 || side2 == side3
        )
    );
}

bool EquilateralTriangle::validate() {
    double side1 = calcLength(vertices[0], vertices[1]);
    double side2 = calcLength(vertices[1], vertices[2]);
    double side3 = calcLength(vertices[2], vertices[0]);

    return (
        isTriangle(side1, side2, side3) &&
        side1 == side2 && side2 == side3
    );
}

bool isTriangle(const double side1, const double side2, const double side3) {
    return (
        side1 != 0 && side2 != 0 && side3 != 0 &&
        side1 + side2 > side3 &&
        side1 + side3 > side2 &&
        side2 + side3 > side1
    );
}

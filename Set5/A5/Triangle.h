#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Polygon.h"

/**
 * @brief Abstract triangle class
 * 
 */
class Triangle : public Polygon {
    public:
        /**
         * @brief Construct a new Triangle object
         *        Sets numVertices to 3 and the vertices array to nullptr
         */
        Triangle();
};

/**
 * @brief Concrete Scalene Triangle class 
 * 
 */
class ScaleneTriangle : public Triangle {
    public:
        /**
         * @brief Validates whether the coordinates contained represent a geometrically valid
         *        scalene triangle. Checks the following:
         *          - That all three sides are nonzero and the sum of any two sides is greater than
         *            the third
         *          - That all three sides are of different length
         * 
         * @return true the triangle is valid
         * @return false the triangle is invalid
         */
        bool validate() override;
};

/**
 * @brief Concrete Isosceles Triangle class
 * 
 */
class IsoscelesTriangle : public Triangle {
    public:
        /**
         * @brief Validates whether the coordinates contained represent a geometrically valid
         *        isosceles triangle. Checks the following:
         *          - That all three sides are nonzero and the sum of any two sides is greater than
         *            the third
         *          - That at least two of the sides are equal in length
         * 
         * @return true the triangle is valid
         * @return false the triangle is invalid
         */
        bool validate() override;
};

/**
 * @brief Concrete Equilateral Triangle class
 * 
 */
class EquilateralTriangle : public Triangle {
    public:
        /**
         * @brief Validates whether the coordinates contained represent a geometrically valid
         *        equilateral triangle. Checks the following:
         *          - That all three sides are nonzero and the sum of any two sides is greater than
         *            the third
         *          - That all three sides are of equal length
         * 
         * @return true the triangle is valid
         * @return false the triangle is invalid
         */
        bool validate() override;
};

#endif

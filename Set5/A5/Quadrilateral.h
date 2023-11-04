#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

#include "Polygon.h"

/**
 * @brief Abstract Quadrilateral class
 * 
 */
class Quadrilateral : public Polygon {
    public:
        /**
         * @brief Construct a new Quadrilateral object
         *        Sets numVertices to 4 and the vertices array to nullptr
         * 
         */
        Quadrilateral();
};

/**
 * @brief Concrete Rhombus class
 * 
 */
class Rhombus : public Quadrilateral {
    public:
        /**
         * @brief Validates whether the coordinates contained represent a geometrically valid
         *        rhombus. Checks the following:
         *          - That the four sides form two isosceles triangles
         *          - That the four sides are of equal length
         * 
         * @return true if the rhombus is valid
         * @return false if the rhombus is invalid
         */
        bool validate() override;
};

#endif

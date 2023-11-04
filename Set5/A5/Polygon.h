#ifndef POLYGON_H
#define POLYGON_H

#include <SFML/Graphics.hpp>

#include "Coordinate.h"

class Polygon {
    public:

        /**
         * @brief Construct a new Polygon object
         * 
         */
        Polygon();

        virtual ~Polygon();

        /**
         * @brief Set the Color object
         * 
         * @param color color to set
         */
        void setColor(sf::Color color);

        /**
         * @brief Draw the polygon to the given SFML render window
         * 
         * @param renderer SFML render window to draw to
         */
        void draw(sf::RenderWindow& renderer);

        /**
         * @brief Set the specified coordinate index in the polygon's internal array
         * 
         * @param index coordinate to set
         * @param coord coordinate data to place in the array location
         */
        void setCoordinate(int index, Coordinate coord);

        /**
         * @brief Validate the polygon
         * 
         * @return true if the polygon is valid
         * @return false if the polygon is invalid
         */
        virtual bool validate() = 0;

    private:
        sf::Color color;

    protected:
        short numVertices;
        Coordinate* vertices;

};

/**
 * @brief Helper function for calculating side lengths
 * 
 * @param coord1 start point of the side
 * @param coord2 end point of the side
 * @return double the length of the given side
 */
double calcLength(const Coordinate& coord1, const Coordinate& coord2);

#endif

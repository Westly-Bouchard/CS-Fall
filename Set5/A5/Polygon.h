#ifndef POLYGON_H
#define POLYGON_H

#include <SFML/Graphics.hpp>

#include "Coordinate.h"

class Polygon {
    public:
        Polygon();

        virtual ~Polygon();

        void setColor(sf::Color color);

        void draw(sf::RenderWindow& renderer);

        void setCoordinate(int index, Coordinate coord);

        virtual bool validate();

    private:
        sf::Color color;

    protected:
        short numVertices;
        Coordinate* vertices;

};

double calcLength(const Coordinate& coord1, const Coordinate& coord2);

#endif

//
// Created by Westly Bouchard on 11/20/23.
//

#ifndef CELL_H
#define CELL_H

#include <iostream>

#include <SFML/Graphics.hpp>

class Cell {
public:
    /**
     * @brief Default constructor
     *
     * Defaults are: (0, 0), Wall Type
     */
    Cell();

    /**
     * @brief Construct a new Cell object
     * @param row Positional row argument
     * @param col Positional column argument
     * @param type type of cell, either Start, End, Space, or Wall
     */
    Cell(int row, int col, char type);

    void draw(sf::RenderWindow& renderer) const;

    /**
     * @brief Set the color of the cell
     * @param color color to set to
     */
    void setColor(sf::Color color);

    /**
     * @brief Get the type of the cell
     * @return Start('S'), End('E'), Space('.'), or Wall('#')
     */
    char getType() const;

    int getRow() const;

    int getCol() const;

private:
    int row;
    int col;

    char type;

    sf::RectangleShape shape;
};

std::ostream& operator<<(std::ostream& os, Cell c);

#endif //CELL_H

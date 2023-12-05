//
// Created by Westly Bouchard on 11/20/23.
//

#include "Cell.h"

using namespace sf;

Cell::Cell(const int row, const int col, const char type) : row(row), col(col), type(type), visitFlag(false), neighborFlag(false) {
    Color cellColor;
    switch (type) {
        case 'S':
            cellColor = Color::Green;
            break;

        case 'E':
            cellColor = Color::Red;
            break;

        case '#':
            cellColor = Color::Black;
            break;

        case '.':
            cellColor = Color::White;
            break;

        default:
            throw std::invalid_argument("Type is invalid");
    }

    shape.setSize(Vector2f(15., 15.));
    shape.setPosition(15 * col, 15 * row);
    shape.setFillColor(cellColor);
}

Cell::Cell() : Cell(0, 0, '#') {}

void Cell::draw(RenderWindow& renderer) const {
    renderer.draw(shape);
}

void Cell::setColor(const Color color) {
    shape.setFillColor(color);
}

char Cell::getType() const {
    return type;
}

int Cell::getRow() const {
    return row;
}

int Cell::getCol() const {
    return col;
}

void Cell::visit() {
    visitFlag = true;
    if (type == '.') setColor(Color(255, 0, 255));
}

bool Cell::visited() const {
    return visitFlag;
}

bool Cell::isNeighbor() const {
    return neighborFlag;
}

void Cell::makeNeighbor() {
    std::cout << "Neighbor Made" << std::endl;
    neighborFlag = true;
}



std::ostream& operator<<(std::ostream& os, const Cell c) {
    os << c.getType();
    return os;
}
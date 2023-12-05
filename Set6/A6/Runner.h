//
// Created by Westly Bouchard on 11/20/23.
//

#ifndef RUNNER_H
#define RUNNER_H

#include <SFML/Graphics.hpp>

#include "Cell.h"
#include "Matrix.hpp"

struct Coordinate {
    int x;
    int y;

    Coordinate(int row, int col);
};

class ARunner {
public:
    ARunner(Matrix<Cell>& maze) : solved(false), maze(maze) {}

    virtual ~ARunner();

    virtual void takeSolutionStep() = 0;

    void draw(sf::RenderWindow& renderer) const;

    bool isSolved() const;

protected:
    bool solved;
    Matrix<Cell>& maze;
};

#endif //RUNNER_H

//
// Created by Westly Bouchard on 11/29/23.
//

#include "Runner.h"

ARunner::~ARunner() = default;

Coordinate::Coordinate(const int row, const int col) {
    y = row;
    x = col;
}

void ARunner::draw(sf::RenderWindow& renderer) const {
    for (int i = 0; i < maze.getRows(); i++) {
        for (int j = 0; j < maze.getCols(); j++) {
            maze.get(i, j).draw(renderer);
        }
    }
}

bool ARunner::isSolved() const {
    return solved;
}
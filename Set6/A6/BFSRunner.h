//
// Created by Westly Bouchard on 11/29/23.
//

#ifndef BFSRUNNER_H
#define BFSRUNNER_H

#include <queue>

#include "Cell.h"
#include "Matrix.hpp"
#include "Runner.h"

class BFSRunner final : public ARunner {
public:
    BFSRunner(Matrix<Cell>& maze, int startRow, int startCol);

    void takeSolutionStep() override;

private:
    std::queue<Coordinate> toSearch;
};



#endif //BFSRUNNER_H

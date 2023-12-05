//
// Created by Westly Bouchard on 11/30/23.
//

#ifndef DFSRUNNER_H
#define DFSRUNNER_H
#include <stack>

#include "Runner.h"


class DFSRunner final : public ARunner {
public:
    DFSRunner(Matrix<Cell>& maze, int startRow, int startCol);

    void takeSolutionStep() override;

private:
    std::stack<Coordinate> toSearch;
};



#endif //DFSRUNNER_H

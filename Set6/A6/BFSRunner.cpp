//
// Created by Westly Bouchard on 11/29/23.
//

#include "BFSRunner.h"

using namespace std;

BFSRunner::BFSRunner(Matrix<Cell>& maze, const int startRow, const int startCol) : ARunner(maze) {
    toSearch.emplace(startRow, startCol);
    maze.get(startRow, startCol).visit();
}


void BFSRunner::takeSolutionStep() {

    // cout << "Taking step" << endl;
    if (solved) return;

    if (!toSearch.empty()) {
        // Grab the next cell in the queue to search
        Coordinate currCell = toSearch.front();
        // Pop the cell off the stack
        toSearch.pop();

        // If the cell is the end cell, we can set our solved flag and return out of the function
        if (maze.get(currCell.y, currCell.x).getType() == 'E') {
            solved = true;
            return;
        }

        // If it is not the end, we need to visit it, and then add it's neighbors to the queue
        // maze.get(currCell.y, currCell.x).visit();

        // Check top neighbor
        if (currCell.y > 0) {
            Cell topNeighbor = maze.get(currCell.y - 1, currCell.x);
            if (topNeighbor.getType() != '#' && !topNeighbor.visited()) {
                maze.get(currCell.y - 1, currCell.x).visit();
                toSearch.emplace(currCell.y - 1, currCell.x);
            }
        }

        // Check right neighbor
        if (currCell.x < maze.getCols() - 1) {
            Cell rightNeighbor = maze.get(currCell.y, currCell.x + 1);
            if (rightNeighbor.getType() != '#' && !rightNeighbor.visited()) {
                maze.get(currCell.y, currCell.x + 1).visit();
                toSearch.emplace(currCell.y, currCell.x + 1);
            }
        }

        // Check bottom neighbor
        if (currCell.y < maze.getRows() - 1) {
            Cell bottomNeighbor = maze.get(currCell.y + 1, currCell.x);
            if (bottomNeighbor.getType() != '#' && !bottomNeighbor.visited()) {
                maze.get(currCell.y + 1, currCell.x).visit();
                toSearch.emplace(currCell.y + 1, currCell.x);
            }
        }

        // Check left neighbor
        if (currCell.x > 0) {
            Cell leftNeighbor = maze.get(currCell.y, currCell.x - 1);
            if (leftNeighbor.getType() != '#' && !leftNeighbor.visited()) {
                maze.get(currCell.y, currCell.x - 1).visit();
                toSearch.emplace(currCell.y, currCell.x - 1);
            }
        }

    }

}

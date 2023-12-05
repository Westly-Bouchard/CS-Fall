#include <iostream>
#include <fstream>

#include "BFSRunner.h"
#include "DFSRunner.h"
using namespace std;

#include "Cell.h"
#include "Runner.h"

#include <SFML/Graphics.hpp>
using namespace sf;

#include "Matrix.hpp"

void drawMatrix(const Matrix<Cell>& mat, RenderWindow* renderer);

int main(int argc, char* argv[]) {
    string filePath;
    if (argc == 2) {
        filePath = argv[1];
    } else {
        cout << "Please Enter the maze file: ";
        cin >> filePath;
    }

    ifstream file;
    file.open(filePath);

    if (file.fail()) {
        cerr << "Failed to open input file: " << filePath << endl;
        cerr << "Terminating program" << endl;
        return -1;
    }

    int cols, rows;

    file >> rows;
    file >> cols;
    file.get();

    Matrix<Cell> maze = Matrix<Cell>(rows, cols);
    int startRow, startCol;

    char nextChar;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            file >> nextChar;
            maze.set(i, j, Cell(i, j, nextChar));
            if (nextChar == 'S') {
                startRow = i;
                startCol = j;
            }
        }
    }

    cout << "[DEBUG] PARSED MAZE" << endl;
    for (int i = 0; i  < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << maze.get(i, j) << " ";
        }
        cout << endl;
    }

    char searchMethod = '\0';

    while (searchMethod != 'B' && searchMethod != 'D') {
        cout << "What search method would you like to use? ('B' -> BFS, 'D' -> DFS) ";
        cin >> searchMethod;
        cout << endl;
    }

    ARunner* runner;
    if (searchMethod == 'B') {
        runner = new BFSRunner(maze, startRow, startCol);
    } else if (searchMethod == 'D') {
        runner = new DFSRunner(maze, startRow, startCol);
    }

    RenderWindow window(
        VideoMode(15 * cols, 15 * rows),
        "Maze Drawer",
        Style::Titlebar | Style::Close
    );

    Event event;

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        sleep(milliseconds(100));

        window.clear();

        runner->draw(window);

        window.display();

        if (!runner->isSolved()) runner->takeSolutionStep();

    }

}

void drawMatrix(const Matrix<Cell>& mat, RenderWindow& renderer) {
    for (int i = 0; i < mat.getRows(); i++) {
        for (int j = 0; j < mat.getCols(); j++) {
            mat.get(i, j).draw(renderer);
        }
    }
}

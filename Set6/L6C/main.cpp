#include <iostream>
#include <fstream>
using namespace std;

#include "Cell.h"

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

    char nextChar;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            file >> nextChar;
            maze.set(i, j, Cell(i, j, nextChar));
        }
    }

    for (int i = 0; i  < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << maze.get(i, j) << " ";
        }
        cout << endl;
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

        window.clear();

        for (int i = 0; i < maze.getRows(); i++) {
            for (int j = 0; j < maze.getCols(); j++) {
                maze.get(i, j).draw(window);
            }
        }

        window.display();
    }

}

void drawMatrix(const Matrix<Cell>& mat, RenderWindow& renderer) {
    for (int i = 0; i < mat.getRows(); i++) {
        for (int j = 0; j < mat.getCols(); j++) {
            mat.get(i, j).draw(renderer);
        }
    }
}

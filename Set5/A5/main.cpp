/* CSCI 200: Assignment 5 SFML Polygon Land:
 *
 * Author: Westly Bouchard
 *
 * More complete description here...
 */

#include <fstream>
#include <iostream>
#include <optional>
#include <string>
#include <sstream>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Coordinate.h"
#include "Polygon.h"
#include "Triangle.h"
#include "Quadrilateral.h"

using namespace std;
using namespace sf;

// Constants for window sizing
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 640

/**
 * @brief For passing polygons back and forth while preserving type information
 *        While it would be possible to use something like `typeid()` this was just easier
 */
enum class PolygonType {
    ET, ST, IT, R
};

/**
 * @brief Attempts to create a polygon of the given type. If validation fails, returns nullopt
 *        to signify to the caller that a valid polygon was not created, and an error message
 *        should be written
 * 
 * @param file istream reference to read polygon data from
 * @param type the type of polygon to create
 * @return optional<Polygon*> A pointer to a valid polygon or std::nullopt
 */
optional<Polygon*> makePolygon(istream& file, PolygonType type);

int main() {
    // Open the data file
    ifstream file;
    file.open("polygons.dat");

    // If we can't open the file, exit the application with an error code
    if (file.fail()) {
        return -1;
    }

    // Set up variables to use in while loop
    char type;
    string lineTemp;

    // Set up vector of polygons
    vector<Polygon*> shapes;

    // While we're not at the end of the file
    while (file.peek() != EOF) {
        // Grab the entire next line. This actually worked out really well, because it makes
        // reporting invalid polygons really easy
        getline(file, lineTemp);

        // Using a stringstream here to turn the line we just grabbed back into an istream object
        // so we can more easily extract data from it
        stringstream line;
        line << lineTemp;

        // The first character of the line should be the type of polygon that we're trying to create
        line >> type;

        // Set up variable to store type information
        PolygonType shapeType;

        // Switch over the type character we got and set the shapeType variant accordingly
        switch (type) {
            case 'S':
                shapeType = PolygonType::ST;
                break;

            case 'I':
                shapeType = PolygonType::IT;
                break;

            case 'E':
                shapeType = PolygonType::ET;
                break;

            case 'R':
                shapeType = PolygonType::R;
                break;

            default:
                // In theory this should never be reached, we could report an error here and continue
                // to the next polygon but this just exits the application. This was not specified
                // in the assignment so I'll just leave it like this for now
                return -1;
        }    

        // Attempt to create the polygon with the given line
        optional<Polygon*> polygon = makePolygon(line, shapeType);

        // If polygon creation was successful, we can add it to the vector of valid polygons to draw
        if (polygon) {
            shapes.push_back(polygon.value());
        } else {
            // If polygon creation failed, report the error and that's it
            cout << "polygon is invalid - \"" << line.str() << "\"" << endl;
        }
    }

    // For debugging, figured I'd leave it in cause it's good info to have
    cout << "Number of valid polygons: " << shapes.size() << endl;

    // Create SFML window object
    RenderWindow window(
        VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
        "Polygon Land",
        Style::Titlebar | Style::Close
    );

    // Set up event to use in the render loop
    Event event;

    // SFML rendering operation
    while (window.isOpen()) {
        // Close the window if necessary
        while(window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        // Clear previous window contents
        window.clear();

        // For every polygon in the vector, draw it to the window
        for (const auto& polygon : shapes) {
            polygon->draw(window);
        }

        // Display the polygon
        window.display();
    }

    return 0;
}

optional<Polygon*> makePolygon(istream& file, PolygonType type) {
    // Set up pointer
    Polygon* polygon;

    // Switch over the type we got, and create a polygon of that specified type
    switch (type) {
        case PolygonType::ET:
            polygon = new EquilateralTriangle();
            break;

        case PolygonType::IT:
            polygon = new IsoscelesTriangle();
            break;

        case PolygonType::ST:
            polygon = new ScaleneTriangle();
            break;

        case PolygonType::R:
            polygon = new Rhombus();
            break;

        default:
            // Unreachable
            return nullopt;
            break;
    }

    // Set up variables for coordinate parsing
    double x, y;

    // Iterate over the number of vertices in the polygon type, and parse their coordinates, adding
    // them to the polygon's internal array
    for (int i = 0; i < (type == PolygonType::R ? 4 : 3); i++) {
        file >> x;
        file >> y;

        polygon->setCoordinate(i, Coordinate(x, y));
    }

    // Parse color information
    int r, g, b;
    file >> r;
    file >> g;
    file >> b;

    // Attempt to validate the polygon, if it's valid we can set its color and return it to the
    // caller
    if (polygon->validate()) {
        polygon->setColor(sf::Color(r, g, b));
        return polygon;
    } else {
        // If its not valid, we need to delete it to avoid memory leaks and then we can return
        // nullopt
        delete polygon;
        return nullopt;
    }
}

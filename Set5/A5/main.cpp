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
#include <typeinfo>
#include <vector>

#include "Coordinate.h"
#include "Polygon.h"
#include "Triangle.h"
#include "Quadrilateral.h"

using namespace std;

enum class PolygonType {
    ET, ST, IT, R
};

optional<Polygon*> makePolygon(ifstream& file, PolygonType type);

int main() {

    ifstream file;
    file.open("polygons.dat");

    if (file.fail()) {
        return -1;
    }

    char type;
    string line;

    vector<Polygon*> shapes;

    while (file.peek() != EOF) {
        getline(file, line);
        file.unget();
        file >> type;
        PolygonType shapeType;

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
                return -1;
        }    

        optional<Polygon*> polygon = makePolygon(file, shapeType);

        if (polygon) {
            shapes.push_back(polygon.value());
        } else {
            cout << "polygon is invalid - \"" << line << "\"" << endl;
        }
    }

    



    cout << "Hello World" << endl;
    return 0;
}

optional<Polygon*> makePolygon(ifstream& file, PolygonType type) {

    Polygon* polygon;

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
            return nullopt;
            break;
    }

    double x, y;

    for (int i = 0; i < (type == PolygonType::R ? 4 : 3); i++) {
        file >> x;
        file >> y;

        polygon->setCoordinate(i, Coordinate(x, y));
    }

    int r, g, b;
    file >> r;
    file >> g;
    file >> b;

    // Consume the `\n' at the end of the line
    char _;
    file >> _;

    if (polygon->validate()) {
        polygon->setColor(sf::Color(r, g, b));
        return polygon;
    } else {
        delete polygon;
        return nullopt;
    }
}

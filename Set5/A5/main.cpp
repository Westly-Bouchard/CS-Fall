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
#include <typeinfo>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Coordinate.h"
#include "Polygon.h"
#include "Triangle.h"
#include "Quadrilateral.h"

using namespace std;
using namespace sf;

#define WINDOW_WIDTH 650
#define WINDOW_HEIGHT 650

enum class PolygonType {
    ET, ST, IT, R
};

optional<Polygon*> makePolygon(istream& file, PolygonType type);

int main() {

    ifstream file;
    file.open("polygons.dat");

    if (file.fail()) {
        return -1;
    }

    char type;
    string lineTemp;

    vector<Polygon*> shapes;

    while (file.peek() != EOF) {
        getline(file, lineTemp);
        stringstream line;
        line << lineTemp;

        line >> type;

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

        optional<Polygon*> polygon = makePolygon(line, shapeType);

        if (polygon) {
            shapes.push_back(polygon.value());
        } else {
            cout << "polygon is invalid - \"" << line.str() << "\"" << endl;
        }
    }

    cout << "Number of valid polygons: " << shapes.size() << endl;

    RenderWindow window(
        VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
        "Polygon Land",
        Style::Titlebar | Style::Close
    );

    Event event;

    while (window.isOpen()) {

        while(window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        window.clear();

        for (const auto& polygon : shapes) {
            polygon->draw(window);
        }

        window.display();
    }

    return 0;
}

optional<Polygon*> makePolygon(istream& file, PolygonType type) {

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

    if (polygon->validate()) {
        polygon->setColor(sf::Color(r, g, b));
        return polygon;
    } else {
        delete polygon;
        return nullopt;
    }
}

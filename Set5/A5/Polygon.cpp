
#include "Polygon.h"

using namespace sf;

Polygon::Polygon() {
    this->color = Color::White;
    this->numVertices = 0;
    this->vertices = nullptr;
}

Polygon::~Polygon() {
    delete this->vertices;
}

void Polygon::setColor(Color color) {
    this->color = color;
}

void Polygon::draw(RenderWindow& renderer) {
    // Create shape to draw
    ConvexShape shape = ConvexShape(this->numVertices);

    // Set the color
    shape.setFillColor(this->color);

    // Set the vertices
    for (int i = 0; i < this->numVertices; i++) {
        shape.setPoint(i, Vector2f(this->vertices[i].x, this->vertices[i].y));
    }

    // Draw the shape to the renderer
    renderer.draw(shape);
}

void Polygon::setCoordinate(int idx, Coordinate coord) {
    this->vertices[idx] = coord;
}

double calcLength(const Coordinate& coord1, const Coordinate& coord2) {
    double xDiff = coord1.x - coord2.x;
    double yDiff = coord1.y - coord2.y;

    return sqrt((xDiff * xDiff) + (yDiff * yDiff));
}


#include "Bubble.h"
using namespace sf;

Bubble::Bubble(double xPos, double yPos, double xDir, double yDir, double radius, Color color) {
    this->xDir = xDir;
    this->yDir = yDir;

    sfComponent.setRadius(radius);
    sfComponent.setPosition(xPos, yPos);
    sfComponent.setFillColor(color);
}

double Bubble::getXDir() {
    return xDir;
}

double Bubble::getYDir() {
    return yDir;
}

void Bubble::setXDir(double dir) {
    xDir = dir;
}

void Bubble::setYDir(double dir) {
    yDir = dir;
}

CircleShape Bubble::getSFComponent() {
    return sfComponent;
}

void Bubble::draw(RenderWindow& renderer) {
    renderer.draw(sfComponent);
}

void Bubble::updatePosition(double maxX, double maxY) {
    Vector2f currentPosition = sfComponent.getPosition();

    if (currentPosition.x + xDir + sfComponent.getRadius() * 2 > maxX
        || currentPosition.x + xDir < 0)
    {
        xDir *= -1;
    }

    if (currentPosition.y + yDir + sfComponent.getRadius() * 2 > maxY
        || currentPosition.y + yDir < 0)
    {
        yDir *= -1;
    }

    currentPosition.x += xDir;
    currentPosition.y += yDir;

    sfComponent.setPosition(currentPosition);
}
